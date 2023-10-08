#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

class TeleopJoy
{
public:
    TeleopJoy();

private:
    void joyCallback(const sensor_msgs::Joy::ConstPtr &joy);

    ros::NodeHandle nh_;

    int linear_axis_, angular_axis_, emergency_button_, gear_up_button_, gear_down_button_;
    double max_linear_speed_, max_angular_speed_;
    bool emergency_stop_;
    ros::Publisher vel_pub_;
    ros::Subscriber joy_sub_;
};

TeleopJoy::TeleopJoy() : linear_axis_(1),
                         angular_axis_(0),
                         emergency_button_(0),
                         gear_up_button_(5),
                         gear_down_button_(4),
                         max_linear_speed_(0.2),
                         max_angular_speed_(0.2),
                         emergency_stop_(false)
{
    nh_.param("axis_linear", linear_axis_, linear_axis_);
    nh_.param("axis_angular", angular_axis_, angular_axis_);
    nh_.param("button_emergency", emergency_button_, emergency_button_);
    nh_.param("button_gear_up", gear_up_button_, gear_up_button_);
    nh_.param("button_gear_down", gear_down_button_, gear_down_button_);
    nh_.param("max_linear_speed", max_linear_speed_, max_linear_speed_);
    nh_.param("max_angular_speed", max_angular_speed_, max_angular_speed_);

    vel_pub_ = nh_.advertise<geometry_msgs::Twist>("smooth_cmd_vel", 1);

    joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopJoy::joyCallback, this);
}

void TeleopJoy::joyCallback(const sensor_msgs::Joy::ConstPtr &joy)
{
    geometry_msgs::Twist twist;
    twist.linear.x = joy->axes[linear_axis_] * max_linear_speed_;
    twist.angular.z = joy->axes[angular_axis_] * max_angular_speed_;

    if (joy->buttons[emergency_button_])
    {
        twist.linear.x = 0.0;
        twist.angular.z = 0.0;
        emergency_stop_ = true;
    }
    else if ((joy->buttons[gear_up_button_]) && (max_linear_speed_ < 0.79))
    {
        max_linear_speed_ += 0.2;
        max_angular_speed_ += 0.2;
        ros::Duration(0.7).sleep();
    }
    else if ((joy->buttons[gear_down_button_]) && (max_linear_speed_ > 0.21))
    {
        max_linear_speed_ -= 0.2;
        max_angular_speed_ -= 0.2;
        ros::Duration(0.7).sleep();
    }
    else if (emergency_stop_)
    {
        // max_linear_speed_ = 0.2;
        // max_angular_speed_ = 0.2;
        emergency_stop_ = false;
    }
    vel_pub_.publish(twist);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "teleop_joy");
    TeleopJoy teleop_joy;

    ros::spin();
}