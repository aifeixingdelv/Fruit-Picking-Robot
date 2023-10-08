/************************************************************
 * Copyright (C): 
 * FileName:    dashan_core.h
 * Author:      chengwei
 * Date:        2015/08/13
 * Version:
 * Description:
 * History:
 *    <author>     <time>           <version>            <desc>
 *    chengwei    2015/08/13          A001         create this file
 **************************************************************/

#ifndef DASHAN_CORE_H
#define DASHAN_CORE_H

//#define SINGAPORE_CUSTOMER

#define VERSION     "V 1.0.0"
#define PI 3.1415926535
//m/s
#define MAX_LINEAR_VEL 1
//0£ºlitte white 1£ºbig white 
#define VEHICLE_TYPE 1
/*robot state*/
#define INIT_PHASE  0
#define NORMAL_RUN  1
#define FATAL_ERROR 2
#define LOW_BATTERY 3
#define NORMAL_WARNING 4

#define MAIN_LOOP_RATE  10      /*loop rate 10hz T=100ms*/
#define FALSE 0
#define TRUE  1

//Peter,ok,20170108
#define NODE_STATE_OK       0
#define LIGHT_RED_ALWAYS    1
#define LIGHT_GREEN_ALWAYS  2
#define NODE_STATE_NOK      3
#define RED_BLINK           3
#define GREEN_BLINK         4
#define GREEN_AND_RED_BLINK 5

#define EPSINON     0.00001f

#define MAX_GOALS_NUM 1024
#define GOTO_AUTO_CHARGE 1
#define FINISH_AUTO_CHARGE 2
#define NAVIGATION_MODE 1
#define GMAPPING_MODE 2
#define CMD_SAVE_INIT_PARA 1
#define CMD_SAVE_GOAL_PSTN 2
#define CMD_SEND_GOALS 3
#define CMD_SEND_CURR_PSTN 4
#define CMD_SAVE_POS 5
#define CMD_SEND_POS 6
#define CMD_SET_INIT_POS 7
#define CMD_VOICE 8
#define CMD_CLEAR_NAVIGOALS 9
#define CMD_SAVE_MAP_OK 10
#define CMD_AIM_AT 12
#define CMD_SHUTDOWN 13
#define CMD_REBOOT 14
#define CMD_TURN_LEFT 15
#define CMD_TURN_RIGHT 21
#define CMD_SAVEPOS_WITH_FOURDIRECTION 22
#define NAV_NODE 1
#define ODOM_NODE 2
#define MODE_NODE 3
#define CORE_NODE 4
#define BRINGUP_NODE 5
#define DIAG_NODE 6
#define SERIAL_NODE 7
#define LIDAR_NODE 8
#define RPC_NODE 9

#define PENDING 0  // The goal has yet to be processed by the action server
#define ACTIVE 1   //The goal is currently being processed by the action server
#define PREEMPTED 2   //The goal received a cancel request after it started executing
                       //  and has since completed its execution (Terminal State)
#define SUCCEEDED 3   //The goal was achieved successfully by the action server (Terminal State)
#define ABORTED 4   //The goal was aborted during execution by the action server due
                            //   to some failure (Terminal State)
#define REJECTED 5   //The goal was rejected by the action server without being processed,
                            //   because the goal was unattainable or invalid (Terminal State)
#define PREEMPTING 6   //The goal received a cancel request after it started executing
                            //   and has not yet completed execution
#define RECALLING 7   //The goal received a cancel request before it started executing,
                            //   but the action server has not yet confirmed that the goal is canceled
#define RECALLED 8   //The goal received a cancel request before it started executing
                            //   and was successfully cancelled (Terminal State)
#define LOST 9   //An action client can determine that a goal is LOST. This should not be
                            //   sent over the wire by an action server

typedef unsigned char BOOL;

#define IsFloatEqualZero(f) (( ((f) >= -EPSINON)&&((f) <= EPSINON) )? TRUE : FALSE)


#endif
