* **硬件平台: Orin(armv8)**
## 命令行安装 Qt5
```bash
sudo apt-get update    更新下库
sudo apt install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools  环境
sudo apt-get install qtcreator   界面
 
#安装qml开发环境      sudo apt-get install qtdeclarative5-dev
#安装QtMultimedia    sudo apt-get install qtmultimedia5-dev
#安装Qtserialport    sudo apt-get install libqt5serialport5-dev
#安装opengl的开发环境 sudo apt-get install libgles2-mesa-dev
#安装QtMySQL         sudo apt-get install libqt5sql5-mysql
```
## 安装 qtcreator-ros
```bash
qtcreator-ros可能会有一些小bug，但不影响使用
sudo snap install qtcreator-ros --classic 
```
## 创建工作空间、ros包、节点、qt代码
* **参考博客 1** [click here](https://blog.csdn.net/YMGogre/article/details/130588657)
* **参考博客 2** [click here](https://blog.csdn.net/m0_67254672/article/details/131939083?ops_request_misc=&request_id=&biz_id=102&utm_term=qt%20creator%20ros&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-131939083.nonecase&spm=1018.2226.3001.4187)
## 注意 ##
* ros包以下分出node、src、include、ui四个文件夹，另外CMakeLists.txt和package.xml需要注意
  
  ```cmake
  CMakeLists.txt
  cmake_minimum_required(VERSION 2.8.0)
  project(ebox_qt_pkg)

  set(CMAKE_INCLUDE_CURRENT_DIR ON)
  set(CMAKE_AUTOUIC ON)
  set(CMAKE_AUTOMOC ON)
  set(CMAKE_AUTORCC ON)


  find_package(catkin REQUIRED COMPONENTS
      roscpp
      std_msgs
  )

  include_directories(${catkin_INCLUDE_DIRS})

  find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
  find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

  set(QT_LIBRARIES Qt5::Widgets)

  catkin_package()

  file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
  file(GLOB QT_RESOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} resources/*.qrc)
  file(GLOB_RECURSE QT_MOC RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS include/ebox_qt_pkg/*.hpp *.h)

  QT5_ADD_RESOURCES(QT_RESOURCES_CPP ${QT_RESOURCES})
  QT5_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
  QT5_WRAP_CPP(QT_MOC_HPP ${QT_MOC})


  file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp)

  add_executable(ebox_mainwindow_node ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP} )
  target_link_libraries(ebox_mainwindow_node ${QT_LIBRARIES} ${catkin_LIBRARIES})
  install(TARGETS ebox_mainwindow_node RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
  ```
  ```xml
  package.xml
  <?xml version="1.0"?>
  <package format="2">
  <name>ebox_qt_pkg</name>
  <version>0.0.0</version>
  <description>The ebox_qt_pkg package</description>
  <maintainer email="nvidia@todo.todo">nvidia</maintainer>
  <license>TODO</license>
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>qt_build</build_depend>
  <build_depend>roscpp</build_depend>
  <build_depend>libqt4-dev</build_depend>
  <exec_depend>qt_build</exec_depend>
  <exec_depend>roscpp</exec_depend>
  <exec_depend>libqt4-dev</exec_depend>
  </package>
  ```
* 以上操作, 在 x86_64 平台可以类比




