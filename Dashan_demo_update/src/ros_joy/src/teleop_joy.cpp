#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
    
    
    class TeleopTurtle
    {
    public:
      TeleopTurtle();
   
   private:
     void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
   
     ros::NodeHandle nh_;
   
     int linear_lx,linear_rx,linear_y,angular_z;
     double l_scale_lx,l_scale_rx,l_scale_y,a_scale_z;
     ros::Publisher vel_pub_;
     ros::Subscriber joy_sub_;
   
   };
   
   
   TeleopTurtle::TeleopTurtle():
     linear_lx(1),
     linear_rx(3),
     linear_y(2),
     angular_z(0)
   {
   
     nh_.param("axis_linear_lx", linear_lx, linear_lx);
     nh_.param("axis_linear_rx", linear_rx, linear_rx);
     nh_.param("axis_linear_y", linear_y, linear_y);
     nh_.param("axis_angular_z", angular_z, angular_z);
     nh_.param("scale_angular_z", a_scale_z, a_scale_z);
     nh_.param("scale_linear_lx", l_scale_lx, l_scale_lx);
     nh_.param("scale_linear_rx", l_scale_rx, l_scale_rx);
     nh_.param("scale_linear_y", l_scale_y, l_scale_y);
   
   
     vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/base/cmd_vel", 1);
   
   
     joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopTurtle::joyCallback, this);
   
   }
   
   void TeleopTurtle::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
   {
     geometry_msgs::Twist twist;
     twist.angular.z = a_scale_z*joy->axes[angular_z];
     twist.linear.x = l_scale_lx*joy->axes[linear_lx];
     twist.linear.x += l_scale_rx*joy->axes[linear_rx];
     twist.linear.y = l_scale_y*joy->axes[linear_y];
     vel_pub_.publish(twist);
   }
   
   
   int main(int argc, char** argv)
   {
    ros::init(argc, argv, "teleop_turtle");
    TeleopTurtle teleop_turtle;
  
    ros::spin();
   }
