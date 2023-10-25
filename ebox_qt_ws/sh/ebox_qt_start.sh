#!/bin/bash

#MASTER_IP=192.168.0.18
#SLAVE_IP=192.168.0.101
#export ROS_MASTER_URI=http://$MASTER_IP:11311
#export ROS_IP=$SLAVE_IP
source ../devel/setup.bash
roslaunch ebox_qt_pkg ebox_qt.launch 
