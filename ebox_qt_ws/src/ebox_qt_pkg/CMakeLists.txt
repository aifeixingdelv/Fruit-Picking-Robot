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


file(GLOB_RECURSE QT_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} FOLLOW_SYMLINKS src/*.cpp node/*.cpp)

add_executable(ebox_mainwindow_node ${QT_SOURCES} ${QT_RESOURCES_CPP} ${QT_FORMS_HPP} ${QT_MOC_HPP} )
target_link_libraries(ebox_mainwindow_node ${QT_LIBRARIES} ${catkin_LIBRARIES})
install(TARGETS ebox_mainwindow_node RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
