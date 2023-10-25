#include <ros/ros.h>
#include <QtGui>
#include <QApplication>
#include <stdlib.h>
#include <stdio.h>
#include "../include/ebox_qt_pkg/ebox_mainwindow.h"

int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  Eboxmainwindow m;
  m.show();
  app.exec();
  return 0;
}
