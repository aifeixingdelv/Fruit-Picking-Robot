/*******************************************************************************
* Copyright (C): 
* Filename: danshan_diagnosis.cpp
* Author: chengwei 
* Date:   2016/09/03  
* Version: A001
* Description : danshan_diagnosis ros node. 
                                
                package:danshan_diagnosis  node:danshan_diagnosis
               
* History:  <author>     <date>            <version>      <description>
*           Chengwei    2015/08/17          A001         create this file
*           Peter       2016/09/03          V1R1C01         modify this file
*******************************************************************************/
#include <ros/ros.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include <nav_msgs/Odometry.h>
#include <dashan_msg/imudata.h>
#include <dashan_msg/diagnosis.h>
#include <geometry_msgs/Twist.h>
#include <dashan_msg/zhishancmd.h>

#include "../include/dashan_diagnosis/dashan_diagnosis.h"
#include "../../dashan_core/include/dashan_core/dashan_core.h"

static dashan_msg::diagnosis s_diagnosis;
static ros::Publisher pub_diagnosis;
static ros::Publisher pub_androidDiag;
static ros::Publisher s_pubTurtleBotVel;

static ros::Subscriber sub_zhishancmd;
static ros::Subscriber sub_serial;
static ros::Subscriber sub_odom;
static ros::Subscriber sub_core;
static geometry_msgs::Twist s_pubVel;

/*node count, we use them to diagnose node state*/
static unsigned int s_odomNode_count = 0;
static unsigned int s_SerialNode_count = 0;
static unsigned int s_coreNode_count = 0;
static unsigned int s_alarmtest = 0;
static bool g_bIsTurnning = false;
static bool g_bIsLogOpen = true;
static void zhishancmdCallback(const dashan_msg::zhishancmd :: ConstPtr &msg)
{
	if(CMD_TURN_LEFT == msg->zhishanCommand)
	{
        if(false == g_bIsTurnning && 5 > msg->zhishanPara)
		{
			s_pubVel.linear.x = 0;	
			s_pubVel.linear.y = 0; 
			s_pubVel.angular.z = 0;
			s_pubTurtleBotVel.publish(s_pubVel);
			//Peter，stop first then turn
			s_pubVel.linear.x = 0;	
			s_pubVel.linear.y = 0; 
			s_pubVel.angular.z = -PI*1/4;
			s_pubTurtleBotVel.publish(s_pubVel);
			s_diagnosis.State = GREEN_BLINK;
			g_bIsTurnning = true;
			s_alarmtest = alarm(msg->zhishanPara);
			if(0 != s_alarmtest)
			{
			    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[DIAG]alarm failed = %d\n", s_alarmtest);
			}
		}
	    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[DIAG]turn left = %d and %d\n", g_bIsTurnning, msg->zhishanPara);
	}
	else if(CMD_TURN_RIGHT == msg->zhishanCommand)
	{//turn right
        if(false == g_bIsTurnning && 5 > msg->zhishanPara)
		{
			s_pubVel.linear.x = 0;	
			s_pubVel.linear.y = 0; 
			s_pubVel.angular.z = 0;
			s_pubTurtleBotVel.publish(s_pubVel);
			//Peter，stop first then turn
			s_pubVel.linear.x = 0;	
			s_pubVel.linear.y = 0; 
			s_pubVel.angular.z = PI*1/4;
			s_pubTurtleBotVel.publish(s_pubVel);
			s_diagnosis.State = GREEN_BLINK;
			g_bIsTurnning = true;
			s_alarmtest = alarm(msg->zhishanPara);
			if(0 != s_alarmtest)
			{
			    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[DIAG]alarm failed = %d\n", s_alarmtest);
			}
		}
	    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[DIAG]turn right = %d and %d\n", g_bIsTurnning, msg->zhishanPara);
	}
	else
	{
	    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[DIAG]turn else = %d and %d\n", g_bIsTurnning, msg->zhishanPara);		
	}
}
void alarm_handler(int signo)
{
    if (signo == SIGALRM)
    {
        ROS_INFO("[DIAG]reset the turnning flag...\n");
        g_bIsTurnning = false;
		s_alarmtest = 0;
		s_pubVel.linear.x = 0;	
		s_pubVel.linear.y = 0; 
		s_pubVel.angular.z = 0;
		s_pubTurtleBotVel.publish(s_pubVel);
    }
}
/*******************************************************************************
 * Function: odomNodeCB
 * Identifier:  (Trace to: )
 * Description: call back function for msg nav_msgs::Odometry
 *              diagnose the odom node state.
 * Input:  nav_msgs::Odometry
 * Output: None
 * Return: 0 :OK, 1:ERROR
 * Others: 
 * Log: 2015/08/17 chengwei create.
 *******************************************************************************/
static void odomNodeCB(const nav_msgs::Odometry::ConstPtr& vel)
{
    s_odomNode_count = 0;  //clear the count
    return;
}

static void imuNodeCB(const dashan_msg::imudata :: ConstPtr &msg)
{
    s_SerialNode_count = 0;   //clear the count
    return;
}
static void coreNodeCB(const dashan_msg::diagnosis :: ConstPtr &msg)
{
    s_coreNode_count = 0;   //clear the count
    return;
}

/*******************************************************************************
 * Function: InitDiagMsg
 * Identifier:  (Trace to: )
 * Description: init diagnosis msg
 *
 * Input:  
 * Output: None
 * Return: 0 :OK, 1:ERROR
 * Others: 
 * Log: 2015/08/18 chengwei create.
 *******************************************************************************/
static void InitDiagMsg(void)
{
    s_diagnosis.initInfo = 0;
    s_diagnosis.hardwareInfo = 0;
    s_diagnosis.Node = 0;
    s_diagnosis.State = NODE_STATE_OK;
    s_diagnosis.Para = 0;
}

static void DiagOtherNodeState(void)
{
    /*add every node count*/
    s_odomNode_count++;
    s_SerialNode_count++;
    s_coreNode_count++;
    s_diagnosis.State = NODE_STATE_OK;
    /*check the node count*/
    if (s_odomNode_count > 20 * MAIN_LOOP_RATE)
    {
        s_diagnosis.Node = ODOM_NODE;
		s_diagnosis.State = NODE_STATE_NOK;
		s_diagnosis.Para++;
        ROS_ERROR("[diagnosis]odom node is error! please check!\n");
    }
   
    if (s_SerialNode_count > 20 * MAIN_LOOP_RATE)
    {
        s_diagnosis.Node = SERIAL_NODE;
		s_diagnosis.State = NODE_STATE_NOK;
		s_diagnosis.Para++;
        ROS_ERROR("[diagnosis]serial node is error! please check!\n");
    }
	if (s_coreNode_count > 20 * MAIN_LOOP_RATE)
	{
	    s_diagnosis.Node = CORE_NODE;
		s_diagnosis.State = NODE_STATE_NOK;
		s_diagnosis.Para++;
        ROS_ERROR("[diagnosis]core node is error! please check!\n");	
	}
}

/*******************************************************************************
 * Function: main
 * Identifier:  (Trace to: )
 * Description: 
 *
 * Input:  
 * Output: None
 * Return: 0 :OK, 1:ERROR
 * Others: 
 * Log: 2015/08/17 chengwei create.
 *******************************************************************************/
int main(int argc, char** argv)
{
    ROS_INFO("dashan_diagnosis node loaded!\n");

    ros::init(argc, argv, "dashan_diagnosis");
    ros::NodeHandle nh;

    ros::Rate loop_rate(MAIN_LOOP_RATE); 

    /*register timer alarm signal*/
    if (signal(SIGALRM, alarm_handler) == SIG_ERR)
    {
        ROS_ERROR("[diagnosis]can't set handler for SIGALM\n");
        return -1;
    }

	/*publish msgs*/
	pub_diagnosis = nh.advertise<dashan_msg::diagnosis>("/dashan_diag", 1000);   /*dashan diagnosis message*/
	pub_androidDiag = nh.advertise<dashan_msg::diagnosis>("/zhishanAndroid/diagnosis", 1000);   /*dashan diagnosis message*/
    s_pubTurtleBotVel = nh.advertise<geometry_msgs::Twist>("/turtlebot_teleop/cmd_vel", 1000);

	sub_zhishancmd = nh.subscribe("/zhishanAndroid/zhishancmd", 1000, zhishancmdCallback);     /*button msg from dashan_hmi node*/
 
	/*subscribe msgs  to check the node status*/
    sub_odom = nh.subscribe("/odom", 1000, odomNodeCB);
    sub_serial = nh.subscribe("/imu_data", 1000, imuNodeCB);
	sub_core = nh.subscribe("/core_diagnosis", 1000, coreNodeCB);
    /*init diagnosis msg*/
    InitDiagMsg();
    
    while(ros::ok())
	{
        DiagOtherNodeState();
        pub_diagnosis.publish(s_diagnosis);
        pub_androidDiag.publish(s_diagnosis);
		ros::spinOnce();
		loop_rate.sleep();
	}
}

