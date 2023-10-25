#include "../include/ebox_qt_pkg/ebox_mainwindow.h"
#include <QDateTime>
#include <QTimer>
#include <QString>
#include <QDir>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

Eboxmainwindow::Eboxmainwindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Eboxmainwindow),nh(nullptr), update_time(nullptr), twist_pub_(ros::Publisher()), vehicleNumber(0), taskNumber(0), car_control_signal(0), linear_(0), angular_(0), l_scale_(0), a_scale_(0)
{
  ui->setupUi(this);

  // ros init
  int argc = 0;
  char** argv = nullptr;
  ros::init(argc, argv, "ebox_mainwindow_node");
  nh = new ros::NodeHandle();
  twist_pub_ = nh->advertise<geometry_msgs::Twist>("smooth_cmd_vel", 1);

  // 从参数服务器中读取参数的值
  nh->getParam("init/vehicle_number", vehicleNumber);
  nh->getParam("init/task_number", taskNumber);
  nh->getParam("init/linear_scale", l_scale_);
  nh->getParam("init/angular_scale", a_scale_);

  // 车辆号/任务号 init
  QString car_task_num = "车辆号/任务号: " +  QString("%1").arg(vehicleNumber, 3, 10, QChar('0'))+"/"+ QString("%1").arg(taskNumber, 3, 10, QChar('0'));
  ui->car_task_num_lineedit->setText(car_task_num);

  ui->forward_status_lineedit->setText("0");
  ui->forward_speed_lineedit->setText("0");
  ui->back_status_lineedit->setText("0");
  ui->back_speed_lineedit->setText("0");
  ui->left_status_lineedit->setText("0");
  ui->left_speed_lineedit->setText("0");
  ui->right_status_lineedit->setText("0");
  ui->right_speed_lineedit->setText("0");

  QImage shibie_image("/home/nvidia/ebox_qt_ws/src/ebox_qt_pkg/resources/shibie.png");
  QImage fenge_image("/home/nvidia/ebox_qt_ws/src/ebox_qt_pkg/resources/fenge.png");
  QImage chengshudu_image("/home/nvidia/ebox_qt_ws/src/ebox_qt_pkg/resources/chengshudu.png");
  QImage tracked_path_image("/home/nvidia/ebox_qt_ws/src/ebox_qt_pkg/resources/tracked_path.png");

  ui->shibie->setScaledContents(true);
  ui->fenge->setScaledContents(true);
  ui->chengshudu->setScaledContents(true);
  ui->tracked_path->setScaledContents(true);

  ui->shibie->setPixmap(QPixmap::fromImage(shibie_image).scaled(ui->shibie->size(), Qt::KeepAspectRatio));
  ui->fenge->setPixmap(QPixmap::fromImage(fenge_image).scaled(ui->shibie->size(), Qt::KeepAspectRatio));
  ui->chengshudu->setPixmap(QPixmap::fromImage(chengshudu_image).scaled(ui->shibie->size(), Qt::KeepAspectRatio));
  ui->tracked_path->setPixmap(QPixmap::fromImage(tracked_path_image).scaled(ui->shibie->size(), Qt::KeepAspectRatio));

  //timer init
  update_time = new QTimer();
  connect(update_time, SIGNAL(timeout()), this, SLOT(timer_update()));
  update_time->start(200);

}

Eboxmainwindow::~Eboxmainwindow()
{
  delete nh;
  delete ui;
}

void Eboxmainwindow::timer_update()
{
  //time update
  QDateTime currentDateTime = QDateTime::currentDateTime();
  QString currentTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss"); // 格式化当前时间
  ui->time->setText(currentTimeString);

  //car move signal update
  switch(car_control_signal)
     {
       case 0:
          linear_ = 0;
          angular_ = 0;
          break;

       case 1:
         linear_ = -l_scale_;
         break;

       case 2:
         linear_ = l_scale_;
         break;

       case 3:
         angular_ = a_scale_;
         break;

       case 4:
         angular_ = -a_scale_;
         break;
     }

     geometry_msgs::Twist twist;
     twist.angular.z = angular_;
     twist.linear.x = linear_;
     twist_pub_.publish(twist);
}

// forward btn
void Eboxmainwindow::on_forward_pushButton_pressed()
{
  car_control_signal = 1;
  ui->forward_status_lineedit->setText("1");
  ui->forward_speed_lineedit->setText(QString::number(l_scale_));
  ROS_INFO("car move forward!");
}
void Eboxmainwindow::on_forward_pushButton_released()
{
  ui->forward_status_lineedit->setText("0");
  ui->forward_speed_lineedit->setText("0");
  car_control_signal = 0;
  ROS_INFO("car stop!");
}

// back btn
void Eboxmainwindow::on_back_pushButton_pressed()
{
  ui->back_status_lineedit->setText("1");
  ui->back_speed_lineedit->setText(QString::number(l_scale_));
  car_control_signal = 2;
  ROS_INFO("car move back!");
}
void Eboxmainwindow::on_back_pushButton_released()
{
  ui->back_status_lineedit->setText("0");
  ui->back_speed_lineedit->setText("0");
  car_control_signal = 0;
  ROS_INFO("car stop!");
}

//left btn
void Eboxmainwindow::on_left_pushButton_pressed()
{
  ui->left_status_lineedit->setText("1");
  ui->left_speed_lineedit->setText(QString::number(a_scale_));
  car_control_signal = 3;
  ROS_INFO("car move left!");
}
void Eboxmainwindow::on_left_pushButton_released()
{
  ui->left_status_lineedit->setText("0");
  ui->left_speed_lineedit->setText("0");
  car_control_signal = 0;
  ROS_INFO("car stop!");
}

//right btn
void Eboxmainwindow::on_right_pushButton_pressed()
{
  ui->right_status_lineedit->setText("1");
  ui->right_speed_lineedit->setText(QString::number(a_scale_));
  car_control_signal = 4;
  ROS_INFO("car move right!");
}
void Eboxmainwindow::on_right_pushButton_released()
{
  ui->right_status_lineedit->setText("0");
  ui->right_speed_lineedit->setText("0");
  car_control_signal = 0;
  ROS_INFO("car stop!");
}






