#!/bin/bash
###
 # @Author: aifeixingdelv 67185045+aifeixingdelv@users.noreply.github.com
 # @Date: 2023-07-27 10:50:25
 # @LastEditors: aifeixingdelv 67185045+aifeixingdelv@users.noreply.github.com
 # @LastEditTime: 2023-07-28 10:21:49
 # @FilePath: /fruit_picking_robot/car/sh/master_board.sh
 # @Description: 用于多机通讯中ROS主机的配置以及节点的启动,林果采摘项目中ROS主机为图为主机
### 

echo "device control starting..."
sleep 60
MASTER_IP=192.168.0.18
SLAVE_IP=192.168.0.101
export ROS_MASTER_URI=http://$MASTER_IP:11311
export ROS_IP=$SLAVE_IP
source ../devel/setup.bash
echo "device control is ok !!!"
roslaunch keyboard_control keyboard_control.launch

