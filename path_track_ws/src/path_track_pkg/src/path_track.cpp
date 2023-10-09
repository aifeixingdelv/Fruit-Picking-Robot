#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/NavSatFix.h>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cmath>

#include <iostream>
#include <iomanip>

#include <xlsxwriter.h>

class RobotTracker
{
public:
    RobotTracker()
    {
        ros::NodeHandle nh;
        cmd_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
        path_sub = nh.subscribe("/path_points", 10, &RobotTracker::pathPointsCallback, this);
        rtk_sub = nh.subscribe("/rtk_data", 10, &RobotTracker::rtkDataCallback, this);

        workbook = nullptr;
        worksheet = nullptr;
        row = 1; // 从第二行开始写入数据

        // 从参数服务器获取关键性跟踪参数
        nh.param<double>("kp", Kp, 1.0);
        nh.param<double>("ki", Ki, 0.0);
        nh.param<double>("kd", Kd, 0.0);
        nh.param<double>("lookahead_distance", lookahead_distance, 1.0);
        nh.param<double>("max_speed", max_speed, 1.0);
        nh.param<double>("max_angular_speed", max_angular_speed, 1.0);
        nh.param<double>("dt", dt, 0.1);
        nh.param<double>("tolerance_distance", tolerance_distance, 0.1);

        ROS_INFO_STREAM("Kp: " << Kp);
        ROS_INFO_STREAM("Ki: " << Ki);
        ROS_INFO_STREAM("Kd: " << Kd);
        ROS_INFO_STREAM("Lookahead Distance: " << lookahead_distance);
        ROS_INFO_STREAM("Max Speed: " << max_speed);
        ROS_INFO_STREAM("Max Angular Speed: " << max_angular_speed);
        ROS_INFO_STREAM("dt: " << dt);
        ROS_INFO_STREAM("Tolerance Distance: " << tolerance_distance);

        createExcel();
    }

    void pathPointsCallback(const nav_msgs::Path::ConstPtr &path_msg)
    {
        path_points = path_msg->poses;
        startTracking();
    }

    void rtkDataCallback(const sensor_msgs::NavSatFix::ConstPtr &rtk_msg)
    {
        rtk_data = rtk_msg;
        current_position = rtk_msg->position;
        current_yaw = rtk_msg->orientation.z;

        // 更新当前位置和角度后，将路径点和当前位置写入Excel表格
        if (worksheet != nullptr)
        {
            writePathToExcel();
        }
        else
        {
            ROS_INFO("Write Excel Error !!!");
        }
    }

    void startTracking()
    {
        ROS_INFO("Waiting for path points...");
        while (path_points.empty())
        {
            ros::spinOnce();
        }
        ROS_INFO("Path points received. Start tracking...");

        current_point_index = 0;

        while (current_point_index < path_points.size())
        {
            geometry_msgs::PoseStamped target_point = path_points[current_point_index];

            // 计算方向角度和距离
            double dx = target_point.pose.position.x - current_position.x;
            double dy = target_point.pose.position.y - current_position.y;
            double target_yaw = atan2(dy, dx);
            double distance = hypot(dx, dy);

            // 使用预瞄点计算目标速度
            double target_speed = calculateTargetSpeed(distance);

            // 使用 PID 控制计算速度和角速度
            double linear_error = target_speed - current_speed;
            double angular_error = target_yaw - current_yaw;
            double control_signal = calculateControlSignal(linear_error, angular_error);

            // 发布控制指令
            geometry_msgs::Twist cmd_vel;
            cmd_vel.linear.x = target_speed;
            cmd_vel.angular.z = control_signal;
            cmd_pub.publish(cmd_vel);

            // 到达跟踪点的容忍距离检查
            if (distance < tolerance_distance)
            {
                current_point_index++;
                ROS_INFO("Path tracking point_index: " << current_point_index);
            }

            ros::Duration(dt).sleep();
            ros::spinOnce();
        }

        ROS_INFO("Path tracking completed!");
        closeExcel();
    }

    double calculateTargetSpeed(double distance)
    {
        // 根据距离和预瞄距离计算目标速度
        double target_speed = 0.0;
        if (distance > lookahead_distance)
        {
            target_speed = max_speed; // 根据需求调整
        }
        return target_speed;
    }

    double calculateControlSignal(double linear_error, double angular_error)
    {
        // 使用 PID 控制计算速度和角速度
        static double integral = 0.0;
        static double previous_error = 0.0;

        integral += linear_error * dt;
        double derivative = (linear_error - previous_error) / dt;

        double control_signal = Kp * linear_error + Ki * integral + Kd * derivative;

        // 限制控制信号在最大速度范围内
        if (control_signal > max_angular_speed)
        {
            control_signal = max_angular_speed;
        }
        else if (control_signal < -max_angular_speed)
        {
            control_signal = -max_angular_speed;
        }

        previous_error = linear_error;

        return control_signal;
    }

    void writePathToExcel()
    {
        // 写入当前位置和正在跟踪的路径点
        std::time_t now = std::time(nullptr);
        std::tm *timeinfo = std::localtime(&now);
        std::ostringstream oss;
        oss << std::put_time(timeinfo, "%H:%M:%S");
        std::string time_str = oss.str();
        if (path_points.size() != 0)
        {
            worksheet_write_string(worksheet, row, 0, time_str.c_str(), nullptr);
            worksheet_write_number(worksheet, row, 1, current_position.x, nullptr);
            worksheet_write_number(worksheet, row, 2, current_position.y, nullptr);
            worksheet_write_number(worksheet, row, 3, path_points[current_point_index].pose.position.x, nullptr);
            worksheet_write_number(worksheet, row, 4, path_points[current_point_index].pose.position.y, nullptr);
        }
        else
        {
            worksheet_write_string(worksheet, row, 0, time_str.c_str(), nullptr);
            worksheet_write_number(worksheet, row, 1, current_position.x, nullptr);
            worksheet_write_number(worksheet, row, 2, current_position.y, nullptr);
            worksheet_write_number(worksheet, row, 3, "NULL", nullptr);
            worksheet_write_number(worksheet, row, 4, "NULL", nullptr);
        }

        row++;
    }
    void createExcel()
    {
        ROS_INFO("Creating Excel file...");
        if (workbook == nullptr)
        {
            // 创建一个新的Excel文件
            std::time_t now = std::time(nullptr);
            std::tm *timeinfo = std::localtime(&now);
            std::ostringstream oss;
            oss << std::put_time(timeinfo, "%Y-%m-%d_%H-%M-%S");
            std::string filename = "path_tracker_record" + oss.str() + ".xlsx";

            workbook = workbook_new(filename.c_str());
            worksheet = workbook_add_worksheet(workbook, "Path Tracking");

            // 写入表头
            worksheet_write_string(worksheet, 0, 0, "Time", nullptr);
            worksheet_write_string(worksheet, 0, 1, "Current_Position_x", nullptr);
            worksheet_write_string(worksheet, 0, 2, "Current_Position_y", nullptr);
            worksheet_write_string(worksheet, 0, 3, "Target_Position_x", nullptr);
            worksheet_write_string(worksheet, 0, 4, "Target_Position_y", nullptr);
        }
        ROS_INFO("Excel file Created.");
    }
    void closeExcel()
    {
        ROS_INFO("Closing Excel file...");
        workbook_close(workbook);
        workbook_free(workbook);
        workbook = nullptr;
        worksheet = nullptr;
        ROS_INFO("Excel file closed.");
    }

private:
    ros::Publisher cmd_pub;
    ros::Subscriber path_sub;
    ros::Subscriber rtk_sub;

    std::vector<geometry_msgs::PoseStamped> path_points;
    sensor_msgs::NavSatFix::ConstPtr rtk_data;
    geometry_msgs::Point current_position;
    double current_yaw = 0.0;
    double current_speed = 0.0;

    // 跟踪参数
    double Kp;
    double Ki;
    double Kd;
    double lookahead_distance;
    double max_speed;
    double max_angular_speed;
    double dt;
    double tolerance_distance;
    size_t current_point_index;

    // Excel
    lxw_workbook *workbook;
    lxw_worksheet *worksheet;
    uint32_t row;
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "path_tracker_node");
    RobotTracker tracker;
    ros::spin();
    return 0;
}