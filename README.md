# **Fruit Picking Robot v0.1**
## 2023.10.08
## Dashan_demo_update:四驱移动底盘CRUISE板载代码（车端）
* 移动地盘IP地址是192.168.0.18，车载路由器WiFi名：TP-LINK_215,WiFi密码兼车载路由器管理员密码：1qazxcvbnm ;  车载工控机用户名是zhishan，用户密码是：1ess!sm0re
* 代码留有一个接受话题信息的接口("/smooth_cmd_vel"),消息类型geometry_msgs::Twist，其中twist.linear.x代表前后移动（前进为正， 后退为负），twist.angular.z代表旋转（左拐为正，右拐为负）
* 一键启动：在Dashan_demo_update目录下，cd sh; ./master_board.sh
* 移动底盘已经配置开机自启动：自启动文件在/etc/init.d/robotengine.sh，注意分配权限

## car_motion_control_ws:底盘运动控制代码（上位机端）
* keyboard_control: 键盘控制底盘功能包, joy_control: 手柄控制底盘功能包
* 手柄控制底盘功能包包含功能：前后左右运动、急刹车、加档、减档
* 编译：在car_motion_control_ws目录下， rm -rf build devel; catkin_make
* 一键启动：在car_motion_control_ws目录下，cd sh; ./slave_board_joy.sh(手柄控制) or ./slave_board_keyboard.sh（键盘控制）

## 注意
* 上位机ip地址应与控制底盘ip地址在同一个网段下（ **192.168.0.xxx** ）
* 不同开发板之间的ros通讯需要设置主机和从机：将移动底盘作为主机master(MASTER_IP=192.168.0.18)，将上位机作为从机slaver(SLAVE_IP=192.168.0.101)，一键启动脚本已经自动配置主从机ros的ip