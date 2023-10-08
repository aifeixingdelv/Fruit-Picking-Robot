
/*******************************************************************************
* Copyright (C): 
* Filename: odometry_s.cpp
* Author:  LZL
* Date:   2015/07/24  
* Version: A001
* Description : imu数据发布代码
                package:dashan_odometry  node:odom_data
                读取imu 传感器数据，发布imu消息供其他节点订阅
* History:  <author>     <date>            <version>      <description>
*              LZL    2015/07/10          A001         create this file
************************************************************************/
#include <ros/ros.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>
#include "std_msgs/String.h"
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>

#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>


#include "../include/dashan_odometry/odom.h"
#include <dashan_msg/wheelSpeed.h>
#include <dashan_msg/imudata.h>
#include "../../dashan_core/include/dashan_core/dashan_core.h"

static double s_vel_z_normalized = 0; /*normalized vel z, when both wheel speed 
is 0, set vel_z to 0*/
static int s_both_wheel_stop = 0; /*when both wheel speed 
is 0 set it to 0*/

int firstin = 0;
double v_tmp = 0.0;
// Wheel Speeds 
double vx = 0.0;
double vy = 0.0;

// Robot position
double robot_pose_px_;
double robot_pose_py_;
double robot_pose_pa_;

// Robot Speeds
double linearSpeedMps_;
double angularSpeedRads_;
//sample period
//double fSamplePeriod = 0.1;   //10hz
double fSamplePeriod = 0.05;   //20hz
// IMU values
double ang_vel_x_ = 0.0;
double ang_vel_y_ = 0.0;
static double ang_vel_z_ = 0.0;
static double ang_yaw_ = 0.0;

double lin_acc_x_ = 0.0;
double lin_acc_y_ = 0.0;
double lin_acc_z_ = 0.0;

double orientation_x_ = 0.0;
double orientation_y_ = 0.0;
double orientation_z_ = 0.0;
double orientation_w_ = 0.0;

double Vel = 0;

double WHEEL_RADIUS = 0.0775;
static int testcount;
/**
time printf
**/
void print_time_odomtry()
{
    struct timeval tv;
    struct tm* ptm;
    char time_str[128];
    long milliseconds;
    gettimeofday(&tv, NULL);
    ptm = localtime(&tv.tv_sec);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", ptm);
    milliseconds = tv.tv_sec / 1000;
	testcount++;
    printf("[odomtry][cycle]%s.%03ld[%d]\n", time_str, milliseconds,testcount);
}
/*******************************************************************************
 * Function: jointStatesCallback

 * Identifier:  (Trace to: )
 * Description:  
//////////////////////////////////////////////////////////////
//     CALLBACK TO RECEIVE THE ROBOT JOINTS STATES          //

//////////////////////////////////////////////////////////////
 * Input:  
 * Output: 
 * Return: void

 * Others: 
 * Log: 2015/07/24 LZL create.
 *******************************************************************************/

void jointStatesCallback(const dashan_msg::wheelSpeed :: ConstPtr &msg) 
{
#if 0   //chengwei deleted 2016.1.8
   if((abs(msg->leftwheel_speed) > 2.0) || (abs(msg->rightwheel_speed) > 2.0))
   {
	return;
   }
#endif   
   Vel = (double)(msg->leftwheel_speed + msg->rightwheel_speed)/2.0;
   //v_tmp = (double)msg->leftwheel_speed;
   
  ////ROS_INFO("Vel=%f\n",Vel);

    /*both wheel is stop*/
    if (  (IsFloatEqualZero(msg->leftwheel_speed)) && 
    (IsFloatEqualZero(msg->rightwheel_speed))    )
    {
        s_both_wheel_stop = 1;   
    }
    else
    {
        s_both_wheel_stop = 0;  
    }
}

/*******************************************************************************
 * Function: imuCallback
 * Identifier:  (Trace to: )
 * Description:  

 //////////////////////////////////////////////////////////////
//           CALLBACK TO RECEIVE THE IMU STATE              //      
//////////////////////////////////////////////////////////////

 * Input:  
 * Output: 
 * Return: void
 * Others: 

 * Log: 2015/07/24 LZL create.
 *******************************************************************************/
void imuCallback(const dashan_msg::imudata :: ConstPtr &msg1){//

	/*
	orientation_x_ = imu_msg.orientation.x;
	orientation_y_ = imu_msg.orientation.y;
	orientation_z_ = imu_msg.orientation.z;

	orientation_w_ = imu_msg.orientation.w;
	*/

	ang_vel_x_ = msg1->Gx ;
	ang_vel_y_ = msg1->Gy ;
	ang_vel_z_ = msg1->Gz * PI / 180;
	ang_yaw_ = msg1->Yaw;////lai 20160504
	//ang_vel_z_ = msg1->Gz + 620;
	//printf("ang_vel_z_=%f\n", ang_vel_z_);

	lin_acc_x_ = msg1->Ax;
	lin_acc_y_ = msg1->Ay;
	lin_acc_z_ = msg1->Az;
	firstin = 1;
}
/*******************************************************************************

 * Function: Getodom
 * Identifier:  (Trace to: )
 * Description:  
                

 *
 * Input:   
 * Output: 
 * Return: void

 * Others: 
 * Log: 2015/07/24 LZL create.
 *******************************************************************************/
static void Getodom()
{
#if 0 //chengwei deleted 20160512
	if (1 == s_both_wheel_stop) /*both wheel are stop*/
    {   
        s_vel_z_normalized = 0;
    }
    else
    {
        s_vel_z_normalized = ang_vel_z_;
    }
#endif
  // Compute orientation just integrating imu gyro
    //robot_pose_pa_ += (ang_vel_z_ )* fSamplePeriod*0.000133907;//0.000689712
    //robot_pose_pa_ += (s_vel_z_normalized )* fSamplePeriod * ANGULAR_CALIB_RATIO; //chengwei deleted 20160512
	
    robot_pose_pa_ = ang_yaw_/180.0*PI;

	//ROS_INFO("ang_yaw : %f\n", ang_yaw_);
	//ROS_INFO("robot_pose_pa_ : %f\n", robot_pose_pa_);

    // Normalized
   /* while (robot_pose_pa_ >= PI)
         robot_pose_pa_ -= 2.0 * PI;
    while (robot_pose_pa_ <= (-PI))
         robot_pose_pa_ += 2.0 * PI;
*/
    // Velocities
    vx = Vel * cos(robot_pose_pa_);
    vy = Vel * sin(robot_pose_pa_);
   ////ROS_INFO("Vx=%f,Vy= %f\n",vx,vy);

    // Positions
    robot_pose_px_ += vx * fSamplePeriod * LINEAR_CALIB_RATIO;
    robot_pose_py_ += vy * fSamplePeriod * LINEAR_CALIB_RATIO;
    return;
}
/*******************************************************************************
 * Function: main
 * Identifier:  (Trace to: )
 * Description: 节点主函数
 *
 * Input:  
 * Output: None
 * Return: 0 :OK, 1:ERROR
 * Others: 
 * Log: 2015/07/24 LZL create.
 *******************************************************************************/
int main(int argc, char** argv)
{
	//ROS_INFO("odom_data node loaded!");
  	ros::init(argc, argv, "odom_data");
 	ros::NodeHandle nh;
        //dashan_odometry::odomdata odom_msg;    
	ros::Subscriber wheel_speed_sub = nh.subscribe("/wheel_speed", 1000,jointStatesCallback);
	ros::Subscriber imu_data_sub = nh.subscribe("/imu_data", 1000, imuCallback);
    ros::Publisher odom_pub = nh.advertise<nav_msgs::Odometry>("/odom", 1000);
 	tf::TransformBroadcaster odom_broadcaster;
	ros::Rate loop_rate(20); 

  
	while(ros::ok())
	{
		ros::Time current_time;
		ros::Time last_time;
		current_time = ros::Time::now();
		last_time = ros::Time::now();
		

		Getodom();
		geometry_msgs::Quaternion odom_quat;
		odom_quat = tf::createQuaternionMsgFromRollPitchYaw(0,0,robot_pose_pa_);

		geometry_msgs::TransformStamped odom_trans;
		odom_trans.header.stamp = current_time;
		odom_trans.header.frame_id = "odom";
		odom_trans.child_frame_id = "base_footprint";

		odom_trans.transform.translation.x = robot_pose_px_;
		odom_trans.transform.translation.y = robot_pose_py_;
		odom_trans.transform.translation.z = 0;
		odom_trans.transform.rotation = tf::createQuaternionMsgFromYaw(robot_pose_pa_);
		//send the transform over /tf
		odom_broadcaster.sendTransform(odom_trans);  

		nav_msgs::Odometry odom;
		odom.header.stamp = current_time;
		odom.header.frame_id = "odom";

		//set the position
		// Position
		odom.pose.pose.position.x = robot_pose_px_;
		odom.pose.pose.position.y = robot_pose_py_;
		odom.pose.pose.position.z =  0;
		/* if((v_tmp == 0)) 
		{
		robot_pose_pa_ = 0;
		firstin = 1;
		}*/
		// Orientation
		odom.pose.pose.orientation = odom_quat;
		// Pose covariance
		for(int i = 0; i < 6; i++)
			odom.pose.covariance[i*6+i] = 0.1;

		//set the velocity
		odom.child_frame_id = "base_footprint";
		// Linear velocities
		odom.twist.twist.linear.x = Vel;
		odom.twist.twist.linear.y = 0.0;
		odom.twist.twist.linear.z = 0.0;
		// Angular velocities
		odom.twist.twist.angular.x = 0;
		odom.twist.twist.angular.y = 0;
		//odom.twist.twist.angular.z = ang_yaw_;//s_vel_z_normalized;//lai 20160504 //delete by chengwei 20160512
		odom.twist.twist.angular.z = ang_vel_z_;  //can we set this to zero ????  chengwei 20160512

		// Twist covariance
		for(int i = 0; i < 6; i++)
			odom.twist.covariance[6*i+i] = 0.1;

		if(firstin == 1)
		{
			odom_pub.publish(odom);
		}
			
		
		last_time = current_time;	
		ros::spinOnce();
		loop_rate.sleep();
	}
    
	return 0;
}


