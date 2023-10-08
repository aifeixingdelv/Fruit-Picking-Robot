#!/bin/bash
MASTER_IP=192.168.0.18
SLAVE_IP=192.168.0.101
export ROS_MASTER_URI=http://$MASTER_IP:11311
export ROS_IP=$MASTER_IP
source /home/zhishan/Dashan_demo_update/devel/setup.bash
roslaunch dashan_bringup zhishanrobot_start.launch 
 
