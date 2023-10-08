/*******************************************************************************
* Copyright (C): 
* Filename: danshan_core.cpp
* Author: chengwei 
* Date:   2015/08/13  
* Version: A001
* Description : dashan_core ros node. 
                dashan_core is the control center of the dashan_demo robot.
                resposibility:
                1. receive the dashan_comm node msgs, handle and dispatch 
                2. controll the robot state, send state to dashan_comm node
                3. handle cmd_vel msg, send move command to dashan_basecontroller
                4. receive diagnosis msgs
                5. send led status to dashan_hmi node
                
                package:dashan_core  node:dashan_core
               
* History:  <author>     <date>            <version>      <description>
*           chengwei    2015/08/13          A001         create this file
*******************************************************************************/

#include <fstream>
#include <ros/ros.h>
#include <ros/console.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <vector>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>  
#include <sys/stat.h>  //get file state 
#include <fcntl.h>      
#include <termios.h>    
#include <errno.h> 
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/PoseWithCovariance.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_broadcaster.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <move_base_msgs/MoveBaseActionGoal.h>

#include <dashan_msg/hmiStatus.h>
#include <dashan_msg/diagnosis.h>
#include <dashan_msg/Mode.h>
#include <dashan_msg/SaveMap.h>
#include <dashan_msg/zhishancmd.h>
#include <dashan_msg/customRoute.h>
#include "../include/dashan_core/dashan_core.h"
#include "../../lib/xml/tinyxml.h"
#include "yaml-cpp/yaml.h"//Peter
#include "yaml-cpp/emitter.h"
#include "yaml-cpp/node/emit.h"
#include "yaml-cpp/node/node.h"
#include "yaml-cpp/node/impl.h"
#include "yaml-cpp/node/convert.h"
#include "yaml-cpp/node/iterator.h"
#include "yaml-cpp/node/detail/impl.h"
pthread_mutex_t mutex; 
static ros::Publisher s_pub_navGoal;
static ros::Publisher s_pubHMI;
static ros::Publisher s_pubAndroidHMI;
static ros::Publisher s_setPoseEstimate; 
static ros::Publisher s_pubZhishancmd;
static ros::Publisher s_pubDiagnosis;
static ros::Publisher s_pubCancleGoal;
static actionlib_msgs::GoalID CancelGoalID;
static actionlib_msgs::GoalStatus goalStatus;
static ros::Subscriber sub_navGoalStatus;
static ros::Subscriber sub_moveBaseGoal;
static dashan_msg::hmiStatus s_msghmiStatus;
static dashan_msg::diagnosis s_msgDiagnosis;
static dashan_msg::zhishancmd s_msgZhishancmd;

static geometry_msgs::PoseStamped s_stNavGoal;  /*store the current goal*/
static geometry_msgs::PoseStamped s_stSendPos;  /*send pos*/
static geometry_msgs::PoseStamped s_stInitPoseMap;  /*store the inital goal*/
static geometry_msgs::PoseStamped s_stInitPoseYaml;  /*store the inital goal*/
static geometry_msgs::PoseStamped s_astNavGoal[MAX_GOALS_NUM];  /*store the navigation goals*/
static geometry_msgs::PoseWithCovarianceStamped s_SetInitalPose;
static unsigned int s_arrayIndex = 0;   /*the index of s_astNavGoal*/

static geometry_msgs::Twist s_vel;

static int s_robotMode = 0;  /*robot mode. 1:navigatioin mode. 2:gmapping mode*/
static int s_saveMap_flag = 0; /*1 : to save the gmapping map*/
static unsigned int s_totalGoalNum = 0;   /*the index of s_astNavGoal*/
static int state_last = 0;
static bool g_bMultiGoalsFlag = false;
static bool g_bGotoInitialPos = false;
static int s_loop_num = 0;
static double s_staytime = 0;
static bool g_bIsLogOpen = true;
static bool g_bShutdown = false;
static bool g_bReboot = false;
static bool g_bSpeakFlag = false;
static void navGoalStateCallbackFunc(const actionlib_msgs::GoalStatusArray::ConstPtr& status)
{
    if (!status->status_list.empty()) //when the list is empty, empty() function will return 1
    {
        goalStatus = status->status_list[0];
				
        if (state_last != goalStatus.status && true == g_bMultiGoalsFlag)
        {
            state_last = goalStatus.status;
            if(SUCCEEDED == goalStatus.status)
            {//The goal was achieved successfully by the action server (Terminal State)
		        
				if(false == g_bSpeakFlag)
				{
					s_pub_navGoal.publish(s_astNavGoal[s_arrayIndex++]);
					ROS_INFO_COND_NAMED(SUCCEEDED == goalStatus.status, "zhishanlog", "[CORE][nospeak] = %d\n", 1);				
				}
				else
				{
					s_msgZhishancmd.zhishanCommand = 17;//voice
					s_msgZhishancmd.zhishanPara = s_arrayIndex;
					s_msgZhishancmd.zhishanVoice = 0;
				    s_pubZhishancmd.publish(s_msgZhishancmd);
					ROS_INFO_COND_NAMED(SUCCEEDED == goalStatus.status, "zhishanlog", "[CORE][speak] = %d\n", s_arrayIndex);		
				}

                sleep(s_staytime);
				ROS_INFO_COND_NAMED(SUCCEEDED == goalStatus.status, "zhishanlog", "zhishan.core.staytime = %d\n", s_staytime);				
                
				if ((1 == s_loop_num) && s_arrayIndex >= s_totalGoalNum && true == g_bMultiGoalsFlag)
				{
					g_bSpeakFlag = false;
					g_bMultiGoalsFlag = false;
					s_arrayIndex = 0;
					s_msgZhishancmd.zhishanCommand = 18;//stop patrol
					s_msgZhishancmd.zhishanVoice = 0;
				    s_pubZhishancmd.publish(s_msgZhishancmd);
				}
				else if ((1 < s_loop_num) && s_arrayIndex >= s_totalGoalNum && true == g_bMultiGoalsFlag)
				{
					s_arrayIndex = 0;
					s_loop_num--;
				}
            }
			else if(ABORTED  == goalStatus.status)
			{	
				s_msgZhishancmd.zhishanCommand = 8;//voice
				s_msgZhishancmd.zhishanPara = 3;
				s_msgZhishancmd.zhishanVoice = 32;//please make a way
				s_pubZhishancmd.publish(s_msgZhishancmd);
				ROS_INFO_COND_NAMED(ABORTED  == goalStatus.status, "zhishanlog", "zhishan.core.ABORTED = %d\n", ABORTED);
			}
			else if(LOST  == goalStatus.status)
			{
				ROS_INFO_COND_NAMED(LOST  == goalStatus.status, "zhishanlog", "zhishan.core.LOST = %d\n", LOST);
			}
			else
			{
				ROS_INFO_COND_NAMED(PREEMPTED  == goalStatus.status, "zhishanlog", "zhishan.core.PREEMPTED = %d\n", goalStatus.status);
				ROS_INFO_COND_NAMED(REJECTED  == goalStatus.status, "zhishanlog", "zhishan.core.REJECTED = %d\n", goalStatus.status);
				ROS_INFO_COND_NAMED(PREEMPTING  == goalStatus.status, "zhishanlog", "zhishan.core.PREEMPTING = %d\n", goalStatus.status);
				ROS_INFO_COND_NAMED(RECALLING  == goalStatus.status, "zhishanlog", "zhishan.core.RECALLING = %d\n", goalStatus.status);
				ROS_INFO_COND_NAMED(RECALLED  == goalStatus.status, "zhishanlog", "zhishan.core.RECALLED = %d\n", goalStatus.status);
			}
        }
		else if(state_last != goalStatus.status && true == g_bGotoInitialPos)
		{
		    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd_autoChargeOK = %d\n", 0);

			state_last = goalStatus.status;
            if (SUCCEEDED == goalStatus.status
			    && (abs(s_stNavGoal.pose.position.x - s_stInitPoseYaml.pose.position.x)) < 0.2
				&& (abs(s_stNavGoal.pose.position.y - s_stInitPoseYaml.pose.position.y)) < 0.2)
            {
				sleep(3);
			    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd_autoCharge = %d\n", 3);
				s_msgZhishancmd.zhishanCommand = 0;//voice
				s_msgZhishancmd.zhishanPara = 0;
				s_msgZhishancmd.autoCharge = 3;//send command to prepare charge
				s_pubZhishancmd.publish(s_msgZhishancmd);
				g_bGotoInitialPos = false;
			}
		}
    }
}

static void moveBaseGoalCallbackFunc(const move_base_msgs::MoveBaseActionGoal::ConstPtr& goal)
{

}
static void SetRouteCallback(const dashan_msg::customRoute :: ConstPtr &msg)
{
	s_msghmiStatus.zhishancmdshow = CMD_SEND_GOALS;
	s_pubHMI.publish(s_msghmiStatus);
	s_pubAndroidHMI.publish(s_msghmiStatus);
	ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "msg->pointIndexes.size() = %d\n", msg->pointIndexes.size());
	s_msghmiStatus.zhishancmdshow = 0;
	/////////read goals from yaml file
	ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "msg->length = %d\n", msg->length);

	if(msg->pointIndexes.size() != msg->length)
	{
		return;
	}

	YAML::Node navigoals = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");
	s_totalGoalNum = 0;
	s_totalGoalNum = navigoals["totalnumber"].as<int>();
	if(s_totalGoalNum >0 && s_totalGoalNum <= MAX_GOALS_NUM && msg->pointIndexes.size() < MAX_GOALS_NUM)
	{
		s_totalGoalNum = msg->pointIndexes.size();
		std::vector<float> vGoal;
	    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "s_totalGoalNum = %d\n", s_totalGoalNum);

		for (int j=0; j < msg->pointIndexes.size(); j++)
		{
		    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "msg->pointIndexes[j]%100 = %d\n", (msg->pointIndexes[j]%100));
			vGoal = navigoals[msg->pointIndexes[j]%100].as<std::vector<float> >();
			s_astNavGoal[j].header.frame_id = "map";
			s_astNavGoal[j].pose.position.x = vGoal.at(0);
			s_astNavGoal[j].pose.position.y = vGoal.at(1);
			s_astNavGoal[j].pose.position.z = vGoal.at(2);
		    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "msg->pointIndexes[j]/100) % 10 = %d\n", (msg->pointIndexes[j]/100) % 10);

			if(0 == (msg->pointIndexes[j]/100) % 10)
			{//forward and North
				s_astNavGoal[j].pose.orientation.x = 0;
				s_astNavGoal[j].pose.orientation.y = 0;
				s_astNavGoal[j].pose.orientation.z = 0;
				s_astNavGoal[j].pose.orientation.w = 1;
			}
			else if(1 == (msg->pointIndexes[j]/100) % 10)
			{//backward and south
				s_astNavGoal[j].pose.orientation.x = 0;
				s_astNavGoal[j].pose.orientation.y = 0;
				s_astNavGoal[j].pose.orientation.z = 1;
				s_astNavGoal[j].pose.orientation.w = 0;
			}
			else if(2 == (msg->pointIndexes[j]/100) % 10)
			{//left and west
				s_astNavGoal[j].pose.orientation.x = 0;
				s_astNavGoal[j].pose.orientation.y = 0;
				s_astNavGoal[j].pose.orientation.z = 0.707107;
				s_astNavGoal[j].pose.orientation.w = 0.707107;
			}
			else if(3 == (msg->pointIndexes[j]/100) % 10)
			{//right and East
				s_astNavGoal[j].pose.orientation.x = 0;
				s_astNavGoal[j].pose.orientation.y = 0;
				s_astNavGoal[j].pose.orientation.z = -0.707107;
				s_astNavGoal[j].pose.orientation.w = 0.707107;
			}
			else
			{
				
			}
		}

		s_loop_num =1;

		g_bMultiGoalsFlag = true;
		s_pub_navGoal.publish(s_astNavGoal[s_arrayIndex++]);	
	}
	else
	{
		ROS_INFO("totalgoalnum failed");
	}
}

/*******************************************************************************
 * Function: zhishancmd
 * Identifier:  (Trace to: )
 * Description: call back func for btn message
 *              
 * Input:  dashan_msg::zhishancmd
 * Output: None
 * Return: None
 * Others: 
 * Log: 2016/08/02 cuijie create.
 *******************************************************************************/
static void zhishancmdCallback(const dashan_msg::zhishancmd :: ConstPtr &msg)
{
	if (CMD_SAVE_INIT_PARA == msg->zhishanCommand)
	{
		YAML::Node zhishanmap = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");
		YAML::Node node;
		YAML::Node nodeOrientation;
		node.push_back(s_stNavGoal.pose.position.x);
		node.push_back(s_stNavGoal.pose.position.y);
		node.push_back(s_stNavGoal.pose.position.z);
		nodeOrientation.push_back(s_stNavGoal.pose.orientation.x);
	    nodeOrientation.push_back(s_stNavGoal.pose.orientation.y);
	    nodeOrientation.push_back(s_stNavGoal.pose.orientation.z);
	    nodeOrientation.push_back(s_stNavGoal.pose.orientation.w);
		//zhishanmap.SetStyle(EmitterStyle::Flow);
		zhishanmap["distance"] = node;
        zhishanmap["orientation"] = nodeOrientation;
		std::ofstream foutzhishanmap("/home/zhishan/map_config/navigoals.yaml");
		foutzhishanmap << zhishanmap;
		foutzhishanmap.close();
		s_msghmiStatus.zhishancmdshow = CMD_SAVE_INIT_PARA;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);
		s_msghmiStatus.zhishancmdshow = 0;
/*		
		///test start
		double amcl_Yaw = 0;
		geometry_msgs::Quaternion odom_quat;
		//
		amcl_Yaw = atan2(0, 1);
		amcl_Yaw = amcl_Yaw + PI/2;
		if (amcl_Yaw >= PI)
		{
			amcl_Yaw -= 2.0 * PI;
		}
	 
        if (amcl_Yaw <= (-PI))
		{
			amcl_Yaw += 2.0 * PI;
		}

		odom_quat = tf::createQuaternionMsgFromRollPitchYaw(0,0,amcl_Yaw);
		s_stNavGoal.pose.orientation = odom_quat;
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "left = %f, %f, %f, %f\n", s_stNavGoal.pose.orientation.x,s_stNavGoal.pose.orientation.y,s_stNavGoal.pose.orientation.z,s_stNavGoal.pose.orientation.w);
        //
		amcl_Yaw = atan2(0, 1);
		amcl_Yaw = amcl_Yaw - PI/2;
				if (amcl_Yaw >= PI)
		{
			amcl_Yaw -= 2.0 * PI;
		}
	 
        if (amcl_Yaw <= (-PI))
		{
			amcl_Yaw += 2.0 * PI;
		}
	    odom_quat = tf::createQuaternionMsgFromRollPitchYaw(0,0,amcl_Yaw);
		s_stNavGoal.pose.orientation = odom_quat;
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "right = %f, %f, %f, %f\n", s_stNavGoal.pose.orientation.x,s_stNavGoal.pose.orientation.y,s_stNavGoal.pose.orientation.z,s_stNavGoal.pose.orientation.w);
        //
		amcl_Yaw = atan2(0, 1);
		amcl_Yaw = amcl_Yaw + PI;
		if (amcl_Yaw >= PI)
		{
			amcl_Yaw -= 2.0 * PI;
		}
	 
        if (amcl_Yaw <= (-PI))
		{
			amcl_Yaw += 2.0 * PI;
		}
	    odom_quat = tf::createQuaternionMsgFromRollPitchYaw(0,0,amcl_Yaw);
		s_stNavGoal.pose.orientation = odom_quat;
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "back = %f, %f, %f, %f\n", s_stNavGoal.pose.orientation.x,s_stNavGoal.pose.orientation.y,s_stNavGoal.pose.orientation.z,s_stNavGoal.pose.orientation.w);
        ///test finish
*/
	}
	else if(CMD_SAVE_GOAL_PSTN == msg->zhishanCommand)
	{
		YAML::Node navigoals = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");
		YAML::Node node;
		node.push_back(s_stNavGoal.pose.position.x);
		node.push_back(s_stNavGoal.pose.position.y);
		node.push_back(s_stNavGoal.pose.position.z);
		node.push_back(s_stNavGoal.pose.orientation.x);
		node.push_back(s_stNavGoal.pose.orientation.y);
		node.push_back(s_stNavGoal.pose.orientation.z);
		node.push_back(s_stNavGoal.pose.orientation.w);
		//navigoals.SetStyle(EmitterStyle::Flow);
		s_totalGoalNum++;
		navigoals["totalnumber"] = s_totalGoalNum;
		navigoals[s_totalGoalNum] = node;	

		std::ofstream foutnavigoals("/home/zhishan/map_config/navigoals.yaml");
		foutnavigoals << navigoals;
		foutnavigoals.close();
		/////////read goals from yaml file
	    YAML::Node readgoals = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");

		std::vector<float> vGoal;
		vGoal = readgoals[s_totalGoalNum].as<std::vector<float> >();
		s_msghmiStatus.pos_x = vGoal.at(0);
		s_msghmiStatus.pos_y = vGoal.at(1);

		s_msghmiStatus.zhishancmdshow = CMD_SAVE_GOAL_PSTN;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);
		s_msghmiStatus.zhishancmdshow = 0;
	}
	else if(CMD_SAVEPOS_WITH_FOURDIRECTION == msg->zhishanCommand)
	{   //can be delete 
		YAML::Node navigoals = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");
		YAML::Node node;
		node.push_back(s_stNavGoal.pose.position.x);
		node.push_back(s_stNavGoal.pose.position.y);
		node.push_back(s_stNavGoal.pose.position.z);
		node.push_back(s_stNavGoal.pose.orientation.x);
		node.push_back(s_stNavGoal.pose.orientation.y);
		node.push_back(s_stNavGoal.pose.orientation.z);
		node.push_back(s_stNavGoal.pose.orientation.w);
		//navigoals.SetStyle(EmitterStyle::Flow);
		s_totalGoalNum++;
		navigoals["totalnumber"] = s_totalGoalNum;
		navigoals[s_totalGoalNum] = node;	

		std::ofstream foutnavigoals("/home/zhishan/map_config/navigoals.yaml");
		foutnavigoals << navigoals;
		foutnavigoals.close();
		/////////read goals from yaml file
	    YAML::Node readgoals = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");

		std::vector<float> vGoal;
		vGoal = readgoals[s_totalGoalNum].as<std::vector<float> >();
		s_msghmiStatus.pos_x = vGoal.at(0);
		s_msghmiStatus.pos_y = vGoal.at(1);

		s_msghmiStatus.zhishancmdshow = CMD_SAVE_GOAL_PSTN;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);
		s_msghmiStatus.zhishancmdshow = 0;
	}

	else if(CMD_SEND_GOALS == msg->zhishanCommand)
	{
		s_msghmiStatus.zhishancmdshow = CMD_SEND_GOALS;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);

		s_msghmiStatus.zhishancmdshow = 0;
		/////////read goals from yaml file
	    YAML::Node navigoals = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");
        s_totalGoalNum = 0;
		s_totalGoalNum = navigoals["totalnumber"].as<int>();
		if(s_totalGoalNum >0 && s_totalGoalNum <= MAX_GOALS_NUM)
		{
			for(int j = 0;j < s_totalGoalNum; j++)
			{
				std::vector<float> vGoal;
				vGoal = navigoals[j+1].as<std::vector<float> >();

				s_astNavGoal[j].header.frame_id = "map";
				s_astNavGoal[j].pose.position.x = vGoal.at(0);
				s_astNavGoal[j].pose.position.y = vGoal.at(1);
				s_astNavGoal[j].pose.position.z = vGoal.at(2);
				s_astNavGoal[j].pose.orientation.x = vGoal.at(3);
				s_astNavGoal[j].pose.orientation.y = vGoal.at(4);
				s_astNavGoal[j].pose.orientation.z = vGoal.at(5);
				s_astNavGoal[j].pose.orientation.w = vGoal.at(6);
			}
			s_loop_num = msg->zhishanPara;
			if(0 == s_loop_num || 0 > s_loop_num)
			{
				s_loop_num = 1;
			}
			g_bMultiGoalsFlag = true;
			s_pub_navGoal.publish(s_astNavGoal[s_arrayIndex++]);	
		}
		else
		{
			ROS_INFO("totalgoalnum failed");
		}

	}
	else if(CMD_SEND_CURR_PSTN == msg->zhishanCommand)
	{  
        //stop send multi-goals function
		g_bMultiGoalsFlag = false;
		g_bGotoInitialPos = false;//stop charge 
        s_arrayIndex = 0;
		////////////////////////
/*		
		ros::Time current_time;
	    current_time = ros::Time::now();
		s_stNavGoal.header.stamp = current_time;
		s_stNavGoal.header.frame_id = "map";
		s_pub_navGoal.publish(s_stNavGoal);
*/
        s_pubCancleGoal.publish(CancelGoalID);	
		
		s_msghmiStatus.zhishancmdshow = CMD_SEND_CURR_PSTN;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);
		s_msghmiStatus.zhishancmdshow = 0;
	}
//	else if(CMD_INNER_TURN == msg->zhishanCommand)
//	{  
/*
        //stop send multi-goals function
		g_bMultiGoalsFlag = false;
		g_bGotoInitialPos = false;//stop charge 
        s_arrayIndex = 0;
		////////////////////////
		ros::Time current_time;
	    current_time = ros::Time::now();
		s_stNavGoal.header.stamp = current_time;
		s_stNavGoal.header.frame_id = "map";
        ///test start
		double amcl_Yaw = 0;
		amcl_Yaw = atan2(2*s_stNavGoal.pose.orientation.w*s_stNavGoal.pose.orientation.z, (1-2*s_stNavGoal.pose.orientation.z*s_stNavGoal.pose.orientation.z));
        if(1 == msg->zhishanPara)
		{
			amcl_Yaw = amcl_Yaw + 1.57;
		}
		else if(2 == msg->zhishanPara)
		{
			amcl_Yaw = amcl_Yaw - 1.57;
		}
		else if(3 == msg->zhishanPara)
		{
			amcl_Yaw = amcl_Yaw + 3.141592;
		}
		else if(4 == msg->zhishanPara)
		{
			s_stNavGoal.pose.position.x += 0.3*cos(amcl_Yaw);
			s_stNavGoal.pose.position.y += 0.3*sin(amcl_Yaw);
		}
		else
		{
			
		}
		if (amcl_Yaw >= PI)
		{
			amcl_Yaw -= 2.0 * PI;
		}
	 
        if (amcl_Yaw <= (-PI))
		{
			amcl_Yaw += 2.0 * PI;
		}
	 
		geometry_msgs::Quaternion odom_quat;
		odom_quat = tf::createQuaternionMsgFromRollPitchYaw(0,0,amcl_Yaw);
		
        s_stNavGoal.pose.orientation = odom_quat;
        ///test finish
		s_pub_navGoal.publish(s_stNavGoal);
		
		s_msghmiStatus.zhishancmdshow = CMD_INNER_TURN;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);
		s_msghmiStatus.zhishancmdshow = 0;
*/
//	}
	else if(CMD_SAVE_POS == msg->zhishanCommand)
	{   //baocunchushiweizi
		YAML::Node navigoals = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");
		YAML::Node node;
		node.push_back(s_stNavGoal.pose.position.x);
		node.push_back(s_stNavGoal.pose.position.y);
		node.push_back(s_stNavGoal.pose.position.z);
		node.push_back(s_stNavGoal.pose.orientation.x);
		node.push_back(s_stNavGoal.pose.orientation.y);
		node.push_back(s_stNavGoal.pose.orientation.z);
		node.push_back(s_stNavGoal.pose.orientation.w);
		//navigoals.SetStyle(EmitterStyle::Flow);
		navigoals["callposition"] = node;	

		std::ofstream foutnavigoals("/home/zhishan/map_config/navigoals.yaml");
		foutnavigoals << navigoals;
		foutnavigoals.close();

		s_msghmiStatus.zhishancmdshow = CMD_SAVE_POS;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);
		s_msghmiStatus.zhishancmdshow = 0;
	}
	else if(CMD_SEND_POS == msg->zhishanCommand)
	{   //yijianhujiao
		/////////read position from yaml file
	    YAML::Node navigoals = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");

		std::vector<float> vGoal;
		vGoal = navigoals["callposition"].as<std::vector<float> >();
		s_stSendPos.header.frame_id = "map";
		s_stSendPos.pose.position.x = vGoal.at(0);
		s_stSendPos.pose.position.y = vGoal.at(1);
		s_stSendPos.pose.position.z = vGoal.at(2);
		s_stSendPos.pose.orientation.x = vGoal.at(3);
		s_stSendPos.pose.orientation.y = vGoal.at(4);
		s_stSendPos.pose.orientation.z = vGoal.at(5);
		s_stSendPos.pose.orientation.w = vGoal.at(6);
		ROS_INFO("[position] x:%f,y:%f,z:%f\n"
				 ,s_stSendPos.pose.position.x
				 ,s_stSendPos.pose.position.y
				 ,s_stSendPos.pose.position.z);
		ROS_INFO("[orientation] x:%f,y:%f,z:%f,w:%f\n"
				 ,s_stSendPos.pose.orientation.x
				 ,s_stSendPos.pose.orientation.y
				 ,s_stSendPos.pose.orientation.z
				 ,s_stSendPos.pose.orientation.w);
        s_pub_navGoal.publish(s_stSendPos);
		//
		s_msghmiStatus.zhishancmdshow = CMD_SEND_POS;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);
		s_msghmiStatus.zhishancmdshow = 0;
	}
	else if(CMD_SET_INIT_POS == msg->zhishanCommand)
	{   //shezhichushiweizi   
		ros::Time current_time;
	    current_time = ros::Time::now();
		s_SetInitalPose.header.stamp = current_time;
		s_SetInitalPose.header.frame_id = "map";
		s_setPoseEstimate.publish(s_SetInitalPose);
		s_msghmiStatus.zhishancmdshow = CMD_SET_INIT_POS;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);
		s_msghmiStatus.zhishancmdshow = 0;
	}
	else if(CMD_CLEAR_NAVIGOALS == msg->zhishanCommand)
	{   //=9
		YAML::Node navigoals = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");
		s_totalGoalNum = 0;
		navigoals["totalnumber"] = s_totalGoalNum;
		std::ofstream foutnavigoals("/home/zhishan/map_config/navigoals.yaml");
		foutnavigoals << navigoals;
		foutnavigoals.close();
		/////////read goals from yaml file
		s_msghmiStatus.zhishancmdshow = CMD_CLEAR_NAVIGOALS;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);
		s_msghmiStatus.zhishancmdshow = 0;
	}
	else if(CMD_SHUTDOWN == msg->zhishanCommand)
	{   //=13
        g_bShutdown = true;
	}	
	else if(CMD_REBOOT == msg->zhishanCommand)
	{  //=14
        g_bReboot = true;
	}	
	else if(GOTO_AUTO_CHARGE == msg->autoCharge)
	{   
		ros::Time current_time;
	    current_time = ros::Time::now();
		s_stInitPoseYaml.header.stamp = current_time;
		s_stInitPoseYaml.header.frame_id = "map";
		s_pub_navGoal.publish(s_stInitPoseYaml);
        g_bGotoInitialPos = true;
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "auto_charge = %d\n", GOTO_AUTO_CHARGE);

	}
	else if(16 == msg->zhishanCommand)
	{  //continue 
        if(true == g_bMultiGoalsFlag && s_arrayIndex < s_totalGoalNum)
		{
			if(SUCCEEDED == goalStatus.status)
			{
			    s_pub_navGoal.publish(s_astNavGoal[s_arrayIndex++]);
			}
			else
			{//when running, stop and then continue
				s_arrayIndex--;
				s_pub_navGoal.publish(s_astNavGoal[s_arrayIndex++]);
			}
			ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[CORE][speak16inner] = %d\n", s_arrayIndex);				
		}
		else
		{
     	    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[CORE][speak16] = %d\n", s_arrayIndex);				
   		    ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "[CORE][speak16] = %d\n", g_bMultiGoalsFlag);	
		}		
	}
	else if(19 == msg->zhishanCommand)
	{  //wait
        s_pubCancleGoal.publish(CancelGoalID);	
		
		s_msghmiStatus.zhishancmdshow = CMD_SEND_CURR_PSTN;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);
		s_msghmiStatus.zhishancmdshow = 0;			
	}
	else if(8 == msg->zhishanCommand && 5 == msg->zhishanPara)
	{  // start run after speaking finished
		s_msghmiStatus.zhishancmdshow = CMD_SEND_GOALS;
		s_pubHMI.publish(s_msghmiStatus);
		s_pubAndroidHMI.publish(s_msghmiStatus);
		ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);

		s_msghmiStatus.zhishancmdshow = 0;
		/////////read goals from yaml file
	    YAML::Node navigoals = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");
        s_totalGoalNum = 0;
		s_arrayIndex = 0;
		s_totalGoalNum = navigoals["totalnumber"].as<int>();
		if(s_totalGoalNum >0 && s_totalGoalNum <= MAX_GOALS_NUM)
		{
			for(int j = 0;j < s_totalGoalNum; j++)
			{
				std::vector<float> vGoal;
				vGoal = navigoals[j+1].as<std::vector<float> >();

				s_astNavGoal[j].header.frame_id = "map";
				s_astNavGoal[j].pose.position.x = vGoal.at(0);
				s_astNavGoal[j].pose.position.y = vGoal.at(1);
				s_astNavGoal[j].pose.position.z = vGoal.at(2);
				s_astNavGoal[j].pose.orientation.x = vGoal.at(3);
				s_astNavGoal[j].pose.orientation.y = vGoal.at(4);
				s_astNavGoal[j].pose.orientation.z = vGoal.at(5);
				s_astNavGoal[j].pose.orientation.w = vGoal.at(6);
			}
			s_loop_num = msg->zhishanVoice;
			if(0 == s_loop_num || 0 > s_loop_num)
			{
				s_loop_num = 1;
			}
			s_pub_navGoal.publish(s_astNavGoal[s_arrayIndex++]);
			sleep(1);
			g_bMultiGoalsFlag = true;
            g_bSpeakFlag = true;	//must after publish		
		}
		else
		{
			ROS_INFO("totalgoalnum failed");
		}
	}
	else
	{
		s_msghmiStatus.zhishancmdshow = 0;
	}
}

static void selectGoalCallback(const geometry_msgs::PoseWithCovarianceStamped :: ConstPtr& goal)
{
	if(NAVIGATION_MODE == s_robotMode)
	{
		s_stNavGoal.pose.position.x = goal->pose.pose.position.x;
		s_stNavGoal.pose.position.y = goal->pose.pose.position.y;
		s_stNavGoal.pose.position.z = goal->pose.pose.position.z;
		s_stNavGoal.pose.orientation.x = goal->pose.pose.orientation.x;
		s_stNavGoal.pose.orientation.y = goal->pose.pose.orientation.y;
		s_stNavGoal.pose.orientation.z = goal->pose.pose.orientation.z;
		s_stNavGoal.pose.orientation.w = goal->pose.pose.orientation.w;
	}
}
static void selectGmappingGoalCallback(const nav_msgs::Odometry :: ConstPtr& goal)
{
	if (GMAPPING_MODE == s_robotMode)
	{
		s_stNavGoal.pose.position.x = goal->pose.pose.position.x;
		s_stNavGoal.pose.position.y = goal->pose.pose.position.y;
		s_stNavGoal.pose.position.z = goal->pose.pose.position.z;
		s_stNavGoal.pose.orientation.x = goal->pose.pose.orientation.x;
		s_stNavGoal.pose.orientation.y = goal->pose.pose.orientation.y;
		s_stNavGoal.pose.orientation.z = goal->pose.pose.orientation.z;
		s_stNavGoal.pose.orientation.w = goal->pose.pose.orientation.w;
	}
}

static void modeCallback(const dashan_msg::Mode :: ConstPtr &msg)
{
    s_robotMode = msg->mode;
}

static void saveMapCallback(const dashan_msg::SaveMap :: ConstPtr &msg)
{
    s_saveMap_flag = msg->flag;
}
unsigned long get_file_size(const char *path)  
{  
    unsigned long filesize = -1;      
    struct stat statbuff;  
    if(stat(path, &statbuff) < 0){  
        return filesize;  
    }else{  
        filesize = statbuff.st_size;  
    }  
    return filesize;  
}
int ReadUserConfig(void)
{
    double max_vel_linear = 0;//x2
    double max_vel_z = 0;//x4
    double backward_vel = 0;//x6
    double xy_goal_tolerance = 0;//x8
    double z_goal_tolerance = 0;//x10
    double path_scale = 0;//x2
    double gdist_scale = 0;//x4
    double sim_time = 0;//x4
    double sim_granularity = 0;//x8
    double obstacle_range = 0;//x10
    double raytrace_range = 0;//x2
    double inflation_radius = 0;//x4
	double vehicle_head = 0;
	double vehicle_tail = 0;
	double vehicle_halfwidth = 0;
    int iRet = 0;
    TiXmlElement *pRoot = NULL;
    TiXmlElement *pNavi = NULL;//
    TiXmlDocument m_xmlDoc("/home/zhishan/map_config/zhishan_navi_config.xml");
    const char *pchAttribute;
    
    /*read navigation config*/
    iRet = m_xmlDoc.LoadFile("/home/zhishan/map_config/zhishan_navi_config.xml");
	if (iRet == false)
	{
		ROS_ERROR("read  zhishan_navi_config.xml failed ! \n");
		iRet = 1;
	}
	else
	{
		iRet = 0;
	}
    if (iRet == 0)
	{
		 pRoot = m_xmlDoc.FirstChildElement("ParamTable");
		 if (NULL == pRoot)
		 {
			 ROS_ERROR("not find ParamTable, read zhishan_navi_config.xml failed ! \n");
	    	 iRet = 1;
		 }
	}
    if (iRet == 0)
	{
        pNavi = pRoot->FirstChildElement("navigation");
        if(NULL != pNavi)
        {
            pchAttribute = pNavi->Attribute("max_vel_linear");
    		if (NULL != pchAttribute)
    		{
                max_vel_linear = strtod(pchAttribute, NULL);
                ROS_INFO("max_vel_linear=%f\n", max_vel_linear);
    		}
            pchAttribute = pNavi->Attribute("max_vel_z");
    		if (NULL != pchAttribute)
    		{
                max_vel_z = strtod(pchAttribute, NULL);
                ROS_INFO("max_vel_z=%f\n", max_vel_z);
    		}
            pchAttribute = pNavi->Attribute("backward_vel");
    		if (NULL != pchAttribute)
    		{
                backward_vel = strtod(pchAttribute, NULL);
                ROS_INFO("backward_vel=%f\n", backward_vel);
    		}
            pchAttribute = pNavi->Attribute("z_goal_tolerance");
    		if (NULL != pchAttribute)
    		{
                z_goal_tolerance = strtod(pchAttribute, NULL);
                ROS_INFO("z_goal_tolerance=%f\n", z_goal_tolerance);
    		}
            pchAttribute = pNavi->Attribute("xy_goal_tolerance");
    		if (NULL != pchAttribute)
    		{
                xy_goal_tolerance = strtod(pchAttribute, NULL);
                ROS_INFO("xy_goal_tolerance=%f\n", xy_goal_tolerance);
    		}
            pchAttribute = pNavi->Attribute("path_scale");
    		if (NULL != pchAttribute)
    		{
                path_scale = strtod(pchAttribute, NULL);
                ROS_INFO("path_scale=%f\n", path_scale);
    		}
            pchAttribute = pNavi->Attribute("gdist_scale");
    		if (NULL != pchAttribute)
    		{
                gdist_scale = strtod(pchAttribute, NULL);
                ROS_INFO("gdist_scale=%f\n", gdist_scale);
    		}
            pchAttribute = pNavi->Attribute("sim_time");
    		if (NULL != pchAttribute)
    		{
                sim_time = strtod(pchAttribute, NULL);
                ROS_INFO("sim_time=%f\n", sim_time);
    		}
            pchAttribute = pNavi->Attribute("sim_granularity");
    		if (NULL != pchAttribute)
    		{
                sim_granularity = strtod(pchAttribute, NULL);
                ROS_INFO("sim_granularity=%f\n", sim_granularity);
    		}
            pchAttribute = pNavi->Attribute("obstacle_range");
    		if (NULL != pchAttribute)
    		{
                obstacle_range = strtod(pchAttribute, NULL);
                ROS_INFO("obstacle_range=%f\n", obstacle_range);
    		}
            pchAttribute = pNavi->Attribute("raytrace_range");
    		if (NULL != pchAttribute)
    		{
                raytrace_range = strtod(pchAttribute, NULL);
                ROS_INFO("raytrace_range=%f\n", raytrace_range);
    		}
            pchAttribute = pNavi->Attribute("inflation_radius");
    		if (NULL != pchAttribute)
    		{
                inflation_radius = strtod(pchAttribute, NULL);
                ROS_INFO("inflation_radius=%f\n", inflation_radius);
    		}
			pchAttribute = pNavi->Attribute("vehicle_head");
			if (NULL != pchAttribute)
    		{
                vehicle_head = strtod(pchAttribute, NULL);
                ROS_INFO("vehicle_head=%f\n", vehicle_head);
    		}
			pchAttribute = pNavi->Attribute("vehicle_tail");
			if (NULL != pchAttribute)
    		{
                vehicle_tail = strtod(pchAttribute, NULL);
                ROS_INFO("vehicle_tail=%f\n", vehicle_tail);
    		}
			pchAttribute = pNavi->Attribute("vehicle_halfwidth");
			if (NULL != pchAttribute)
    		{
                vehicle_halfwidth = strtod(pchAttribute, NULL);
                ROS_INFO("vehicle_halfwidth=%f\n", vehicle_halfwidth);
    		}
			pchAttribute = pNavi->Attribute("stay_time");
			if (NULL != pchAttribute)
    		{
                s_staytime = strtod(pchAttribute, NULL);
                ROS_INFO("staytime=%f\n", s_staytime);
    		}
        }
    }

    /*save navigation config to ros-yaml files*/
    //base_local_planner_params.yaml
    YAML::Node config = YAML::LoadFile("/home/zhishan/Dashan_demo/src/dashan_2dnav/config/base_local_planner_params.yaml");
    //ROS_INFO("12121212=%f\n", config["controller_frequency"].as<double>());
    //ROS_INFO("test000=%f\n", config["TrajectoryPlannerROS"]["max_vel_x"].as<double>());

	
    config["TrajectoryPlannerROS"]["max_vel_x"] = max_vel_linear;
    config["TrajectoryPlannerROS"]["max_vel_theta"] = max_vel_z;
    config["TrajectoryPlannerROS"]["xy_goal_tolerance"] = xy_goal_tolerance;
    config["TrajectoryPlannerROS"]["yaw_goal_tolerance"] = z_goal_tolerance;
    config["TrajectoryPlannerROS"]["sim_time"] = sim_time;
    config["TrajectoryPlannerROS"]["pdist_scale"] = path_scale;
    config["TrajectoryPlannerROS"]["gdist_scale"] = gdist_scale;
    config["TrajectoryPlannerROS"]["sim_granularity"] = sim_granularity;
	config["TrajectoryPlannerROS"]["escape_vel"] = backward_vel;

    std::ofstream fout("/home/zhishan/Dashan_demo/src/dashan_2dnav/config/base_local_planner_params.yaml");
    fout << config;
	fout.close();

    //////////////////
    YAML::Node cfgcostmap = YAML::LoadFile("/home/zhishan/Dashan_demo/src/dashan_2dnav/config/costmap_common_params.yaml");
    
    cfgcostmap["obstacle_range"] = obstacle_range;
    cfgcostmap["raytrace_range"] = raytrace_range;
    cfgcostmap["inflation_radius"] = inflation_radius;
    cfgcostmap["footprint"][0][0] = vehicle_halfwidth;
    cfgcostmap["footprint"][0][1] = vehicle_head;
    cfgcostmap["footprint"][1][0] = vehicle_halfwidth*(-1);
	cfgcostmap["footprint"][1][1] = vehicle_head;
	cfgcostmap["footprint"][2][0] = vehicle_halfwidth*(-1);
	cfgcostmap["footprint"][2][1] = vehicle_tail*(-1);
	cfgcostmap["footprint"][3][0] = vehicle_halfwidth;
	cfgcostmap["footprint"][3][1] = vehicle_tail*(-1);
    std::ofstream foutcfgcostmap("/home/zhishan/Dashan_demo/src/dashan_2dnav/config/costmap_common_params.yaml");
    foutcfgcostmap << cfgcostmap;
	foutcfgcostmap.close();

    //////////////////
	//YAML::Node readzhishanmap = YAML::LoadFile("/home/zhishan/map_config/zhishanmap.yaml");
	//s_stInitPoseMap.pose.position.x = readzhishanmap["origin"][0].as<float>();
	//s_stInitPoseMap.pose.position.y = readzhishanmap["origin"][1].as<float>();
	//s_stInitPoseMap.pose.position.z = readzhishanmap["origin"][2].as<float>();
	YAML::Node readzhishannavigoals = YAML::LoadFile("/home/zhishan/map_config/navigoals.yaml");

	s_SetInitalPose.pose.pose.position.x = readzhishannavigoals["distance"][0].as<float>();
	s_SetInitalPose.pose.pose.position.y = readzhishannavigoals["distance"][1].as<float>();
	s_SetInitalPose.pose.pose.position.z = readzhishannavigoals["distance"][2].as<float>();
	
	s_SetInitalPose.pose.pose.orientation.x = readzhishannavigoals["orientation"][0].as<float>();
	s_SetInitalPose.pose.pose.orientation.y = readzhishannavigoals["orientation"][1].as<float>();
	s_SetInitalPose.pose.pose.orientation.z = readzhishannavigoals["orientation"][2].as<float>();
	s_SetInitalPose.pose.pose.orientation.w = readzhishannavigoals["orientation"][3].as<float>();
	//auto charge positon is the init position in zhishanmap.yaml and saved orientation in navigoals.yaml
	//because there is no orientation in zhishanmap.yaml
	s_stInitPoseYaml.pose.position.x = s_stInitPoseMap.pose.position.x;
	s_stInitPoseYaml.pose.position.y = s_stInitPoseMap.pose.position.y;
	s_stInitPoseYaml.pose.position.z = s_stInitPoseMap.pose.position.z;
	s_stInitPoseYaml.pose.orientation.x = s_SetInitalPose.pose.pose.orientation.x;
	s_stInitPoseYaml.pose.orientation.y = s_SetInitalPose.pose.pose.orientation.y;
	s_stInitPoseYaml.pose.orientation.z = s_SetInitalPose.pose.pose.orientation.z;
	s_stInitPoseYaml.pose.orientation.w = s_SetInitalPose.pose.pose.orientation.w;
    return iRet;
}


/*******************************************************************************
 * Function: cmFunc
 * Identifier:  (Trace to: )
 * Description: 
 * 
 * Input:  
 * Output: None
 * Return: None
 * Others: 
 * Log: 2017/08/14 cuibo create.
 *******************************************************************************/
void* cmFunc(void* arg)
{
				chdir("/home/zhishan/map_config");
				system("pwd");
                system("rm -rf zhishanmap*");
				sleep(1);
                system("rosrun map_server map_saver -f zhishanmap");
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
 * Log: 2015/08/13 chengwei create.
 *******************************************************************************/
int main(int argc, char** argv)
{
    ROS_INFO("dashan_core node loaded!\n");
	ROS_INFO("***********************************************\n");
	ROS_INFO("ZHISHAN CORPORATION ALL RIGHTS RESERVED.\n");
	ROS_INFO("PRODUCT VERSION: %s\n", VERSION);
	ROS_INFO("***********************************************\n");

	ros::init(argc, argv, "dashan_core");
	ros::NodeHandle nh;

	//actionlib::SimpleActionClient<actionlib_msgs::GoalStatus> ac("move_base", true);
   //定义ros循环的频率
	ros::Rate loop_rate(MAIN_LOOP_RATE); 

	/*publish msgs*/
    s_pub_navGoal = nh.advertise<geometry_msgs::PoseStamped>("move_base_simple/goal", 1000);//发布导航
	s_pubHMI = nh.advertise<dashan_msg::hmiStatus>("/dashan_hmiCmd", 1000);
	s_pubAndroidHMI = nh.advertise<dashan_msg::hmiStatus>("/zhishanAndroid/hmiStatus", 1000);//发布hmi消息
	s_setPoseEstimate = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 1000);//发布初始位资
    s_pubZhishancmd = nh.advertise<dashan_msg::zhishancmd>("/zhishanAndroid/zhishancmd", 1000);//发布zhishancmd消息
	s_pubDiagnosis = nh.advertise<dashan_msg::diagnosis>("/core_diagnosis", 1000);//Peter
    s_pubCancleGoal = nh.advertise<actionlib_msgs::GoalID>("move_base/cancel",1000);//发布取消导航指令

	/*subscribe msgs*/
    ros::Subscriber sub_zhishancmd = nh.subscribe("/zhishanAndroid/zhishancmd", 1000, zhishancmdCallback); //zhishancmd指令回调
	ros::Subscriber sub_navGoal = nh.subscribe("/amcl_pose", 1000, selectGoalCallback); //
    ros::Subscriber sub_GmappingSelectGoal = nh.subscribe("/odom", 1000, selectGmappingGoalCallback);//	
	ros::Subscriber sub_SetRoute = nh.subscribe("/zhishanAndroid/customRoute", 1000, SetRouteCallback);	//自定义路线回调

    //ros::Subscriber sub_navGoalStatus = nh.subscribe("move_base/status", 1000, navGoalStateCallback);  /*nav goal msg from rviz*/
    sub_navGoalStatus = nh.subscribe("move_base/status", 1000, navGoalStateCallbackFunc);  /*nav goal msg from rviz*/
    sub_moveBaseGoal = nh.subscribe("move_base/goal", 1000, moveBaseGoalCallbackFunc);  /*nav goal msg from rviz*/

    /*read user's config*/
    if (0 != ReadUserConfig())
    {
        ROS_ERROR("ReadUserConfig failed\n");
        return 1;
    }
    /*subscribe robot mode msg*/
    ros::Subscriber sub_robot_mode_cmd = nh.subscribe("/dashan_mode", 1, modeCallback);//选择模式回调
    ros::Subscriber sub_save_map_cmd = nh.subscribe("/save_map_cmd", 1, saveMapCallback);//保存地图回调
    
	/***    init phase    ***/  
/* 
	while(FALSE == IsOtherNodesReady())
	{
	    ros::spinOnce();
		loop_rate.sleep();
	}
*/
	ROS_INFO("dashan_core: INIT PHASE FINISHED! \n");

	/***    cycle phase   ***/
	while(ros::ok())
	{
      
        /*if we should save the gmapping map*/
        if (GMAPPING_MODE == s_robotMode)
        {
            if (1 == s_saveMap_flag)
            {
				/*ROS_INFO("[CORE]create map now...\n");//cuibo 20170814
			    pthread_mutex_lock(&mutex);/*lock the mutex 
				chdir("/home/zhishan/map_config");
				system("pwd");
                system("rm -rf zhishanmap*");
				sleep(1);
                system("rosrun map_server map_saver -f zhishanmap");
				sleep(10);*/
				ROS_INFO("[CORE]create map now...\n");
			    pthread_mutex_lock(&mutex);/*lock the mutex*/ 
				//cuibo 20170814
				pthread_t cmThread;
				pthread_create(&cmThread, NULL, &cmFunc, NULL);
				pthread_join(cmThread, NULL);
				
				if(0 >= get_file_size("/home/zhishan/map_config/zhishanmap.yaml"))
				{
					ROS_INFO("[CORE][create map failed and recreate]...\n");
					s_msgDiagnosis.initInfo = 1;
					s_msgDiagnosis.Node = CORE_NODE;
					s_msgDiagnosis.State = NODE_STATE_NOK;
					s_msgDiagnosis.Para = 1;
					s_msgDiagnosis.hardwareInfo = 0;
					s_pubDiagnosis.publish(s_msgDiagnosis);
					chdir("/home/zhishan/map_config");
				    system("pwd");
					system("rm -rf zhishanmap*");
					sleep(1);
				    system("rosrun map_server map_saver -f zhishanmap");
				    sleep(5);			
				}
				else
				{//sucess
					s_msghmiStatus.zhishancmdshow = CMD_SAVE_MAP_OK;
					s_pubHMI.publish(s_msghmiStatus);
					s_pubAndroidHMI.publish(s_msghmiStatus);
					ROS_INFO_COND_NAMED(true == g_bIsLogOpen, "zhishanlog", "zhishancmd = %d\n", s_msghmiStatus.zhishancmdshow);
					s_msghmiStatus.zhishancmdshow = 0;
					
					//s_robotMode = 0;
				    s_saveMap_flag = 0;
				//	ROS_INFO("[CORE][shutdown after create map]...\n");
				 //   system("pwd");
                 //   system("shutdown now");
				}
				pthread_mutex_unlock(&mutex);/*unlock the mutex*/  
                while(1)
                {
                    sleep(1); //we halt here, waiting power-off
					s_msgDiagnosis.initInfo = 0;
					s_msgDiagnosis.Node = CORE_NODE;
					s_msgDiagnosis.State = NODE_STATE_OK;
					s_msgDiagnosis.Para = 0;
					s_msgDiagnosis.hardwareInfo = 0;
					s_pubDiagnosis.publish(s_msgDiagnosis);
                }
            }
			s_msgDiagnosis.initInfo = 0;
			s_msgDiagnosis.Node = CORE_NODE;
			s_msgDiagnosis.State = NODE_STATE_OK;
			s_msgDiagnosis.Para = 0;
			s_msgDiagnosis.hardwareInfo = 0;
			
			s_pubDiagnosis.publish(s_msgDiagnosis);
        }
		if(true == g_bShutdown)
		{
				ROS_INFO("[CORE][shutdown]...\n");
				system("pwd");
                system("shutdown now");
		}
		if(true == g_bReboot)
		{
				ROS_INFO("[CORE][reboot]...\n");
				system("pwd");
                system("shutdown -r now");
		}
		s_msgDiagnosis.initInfo = 0;
		s_msgDiagnosis.Node = CORE_NODE;
		s_msgDiagnosis.State = NODE_STATE_OK;
		s_msgDiagnosis.Para = 0;
		s_msgDiagnosis.hardwareInfo = 0;
		
		s_pubDiagnosis.publish(s_msgDiagnosis);
		//////////////////////////////////////////////////////
		ros::spinOnce();
		loop_rate.sleep();
	}

	/*fatal error handle*/
	ROS_ERROR("dashan robot fatal error! STOP. \n");
    system("rosnode kill /danshan_core");
	while(1)
	{
        /*kill the dashan_serial node, this will cause PIC to stop the robot*/
        sleep(1);
	}

}

