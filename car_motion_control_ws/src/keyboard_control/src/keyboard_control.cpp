/*
 * @Author: aifeixingdelv 67185045+aifeixingdelv@users.noreply.github.com
 * @Date: 2023-07-27 10:46:52
 * @LastEditors: aifeixingdelv 67185045+aifeixingdelv@users.noreply.github.com
 * @LastEditTime: 2023-07-27 16:27:38
 * @FilePath: /四轮移动平台PC及工控机源码/car/src/ros_joy/src/teleop_joy.cpp
 * @Description: ros主机中测试汽车地盘运动的ros包
 */

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define KEYCODE_W 0x77
#define KEYCODE_A 0x61
#define KEYCODE_S 0x73
#define KEYCODE_D 0x64
#define KEYCODE_Q 0x71
#define KEYCODE_E 0x65

class TeleopTurtle
{
public:
  TeleopTurtle();
  void keyLoop();

private:
  ros::NodeHandle nh_;
  double linear_, angular_;
  double l_scale_, a_scale_;
  ros::Publisher twist_pub_;
};

TeleopTurtle::TeleopTurtle():
  linear_(0),
  angular_(0),
  l_scale_(0.1),
  a_scale_(0.1)
{
  twist_pub_ = nh_.advertise<geometry_msgs::Twist>("smooth_cmd_vel", 1);
}

int kfd = 0;
struct termios cooked, raw;

void TeleopTurtle::keyLoop()
{
  char c;
  bool dirty = false;

  // get the console in raw mode
  tcgetattr(kfd, &cooked);
  memcpy(&raw, &cooked, sizeof(struct termios));
  raw.c_lflag &= ~(ICANON | ECHO);
  // Setting a new line, then end of file
  raw.c_cc[VEOL] = 1;
  raw.c_cc[VEOF] = 2;
  tcsetattr(kfd, TCSANOW, &raw);

  puts("Reading from keyboard");
  puts("---------------------------");
  puts("Use 'WASD' to move the robot");
  puts("Use 'Q' and 'E' to rotate the robot");

  for(;;)
  {
    // get the next event from the keyboard
    if(read(kfd, &c, 1) < 0)
    {
      perror("read():");
      exit(-1);
    }

    linear_ = angular_ = 0;
    ROS_DEBUG("value: 0x%02X\n", c);

    switch(c)
    {
      case KEYCODE_W:
        linear_ = l_scale_;
        dirty = true;
        break;
      case KEYCODE_S:
        linear_ = -l_scale_;
        dirty = true;
        break;
      case KEYCODE_A:
        angular_ = a_scale_;
        dirty = true;
        break;
      case KEYCODE_D:
        angular_ = -a_scale_;
        dirty = true;
        break;
      case KEYCODE_Q:
        angular_ = a_scale_;
        linear_ = l_scale_;
        dirty = true;
        break;
      case KEYCODE_E:
        angular_ = -a_scale_;
        linear_ = l_scale_;
        dirty = true;
        break;
    }

    geometry_msgs::Twist twist;
    twist.angular.z = angular_;
    twist.linear.x = linear_;

    if(dirty == true)
    {
      twist_pub_.publish(twist);
      dirty = false;
    }
  }

  return;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_turtle");
  TeleopTurtle teleop_turtle;

  teleop_turtle.keyLoop();
  
  return 0;
}