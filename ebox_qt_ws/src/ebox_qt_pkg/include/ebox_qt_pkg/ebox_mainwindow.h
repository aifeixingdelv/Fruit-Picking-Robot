#ifndef EBOX_MAINWINDOW_H
#define EBOX_MAINWINDOW_H

#include <QWidget>
#include "ui_ebox_mainwindow.h"
#include <ros/ros.h>

namespace Ui {
class Eboxmainwindow;
}

class Eboxmainwindow : public QWidget
{
  Q_OBJECT

public:
  explicit Eboxmainwindow(QWidget *parent = nullptr);
  ~Eboxmainwindow();

private slots:
  void timer_update();
  // forward btn
  void on_forward_pushButton_pressed();
  void on_forward_pushButton_released();
  // back btn
  void on_back_pushButton_pressed();
  void on_back_pushButton_released();
  // left btn
  void on_left_pushButton_pressed();
  void on_left_pushButton_released();
  // right btn
  void on_right_pushButton_pressed();
  void on_right_pushButton_released();




private:
  Ui::Eboxmainwindow *ui;
  ros::NodeHandle* nh;
  QTimer *update_time;
  ros::Publisher twist_pub_;


  int vehicleNumber;
  int taskNumber;
  int car_control_signal; //0 stop; 1 forward; 2 back; 3 left; 4 right
  double linear_, angular_;
  double l_scale_, a_scale_;
};

#endif // EBOX_MAINWINDOW_H
