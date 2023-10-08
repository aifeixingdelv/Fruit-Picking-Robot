#!/bin/bash

source /home/zhishan/Dashan_demo_update/sh/ip.sh
echo $MASTER_IP

source /home/zhishan/Dashan_demo_update/devel/setup.bash
export ROS_HOSTNAME=zhishan-robot
export ROS_MASTER_URI=http://cbc:11311
roslaunch dashan_bringup zhishanrobot_start.launch 
