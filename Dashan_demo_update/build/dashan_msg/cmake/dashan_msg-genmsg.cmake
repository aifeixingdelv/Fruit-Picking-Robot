# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "dashan_msg: 10 messages, 0 services")

set(MSG_I_FLAGS "-Idashan_msg:/home/zhishan/Dashan_demo_update/src/dashan_msg/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(dashan_msg_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/zhishancmd.msg" NAME_WE)
add_custom_target(_dashan_msg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dashan_msg" "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/zhishancmd.msg" ""
)

get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/Mode.msg" NAME_WE)
add_custom_target(_dashan_msg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dashan_msg" "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/Mode.msg" ""
)

get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/diagnosis.msg" NAME_WE)
add_custom_target(_dashan_msg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dashan_msg" "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/diagnosis.msg" ""
)

get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/SaveMap.msg" NAME_WE)
add_custom_target(_dashan_msg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dashan_msg" "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/SaveMap.msg" ""
)

get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/customRoute.msg" NAME_WE)
add_custom_target(_dashan_msg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dashan_msg" "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/customRoute.msg" ""
)

get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/imudata.msg" NAME_WE)
add_custom_target(_dashan_msg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dashan_msg" "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/imudata.msg" ""
)

get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/xyyawdata.msg" NAME_WE)
add_custom_target(_dashan_msg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dashan_msg" "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/xyyawdata.msg" ""
)

get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/wheelSpeed.msg" NAME_WE)
add_custom_target(_dashan_msg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dashan_msg" "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/wheelSpeed.msg" ""
)

get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/ribbontask.msg" NAME_WE)
add_custom_target(_dashan_msg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dashan_msg" "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/ribbontask.msg" ""
)

get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/hmiStatus.msg" NAME_WE)
add_custom_target(_dashan_msg_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "dashan_msg" "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/hmiStatus.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/zhishancmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
)
_generate_msg_cpp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/Mode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
)
_generate_msg_cpp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/ribbontask.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
)
_generate_msg_cpp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/SaveMap.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
)
_generate_msg_cpp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/customRoute.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
)
_generate_msg_cpp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/imudata.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
)
_generate_msg_cpp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/xyyawdata.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
)
_generate_msg_cpp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/wheelSpeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
)
_generate_msg_cpp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/diagnosis.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
)
_generate_msg_cpp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/hmiStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
)

### Generating Services

### Generating Module File
_generate_module_cpp(dashan_msg
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(dashan_msg_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(dashan_msg_generate_messages dashan_msg_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/zhishancmd.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_cpp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/Mode.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_cpp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/diagnosis.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_cpp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/SaveMap.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_cpp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/customRoute.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_cpp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/imudata.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_cpp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/xyyawdata.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_cpp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/wheelSpeed.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_cpp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/ribbontask.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_cpp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/hmiStatus.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_cpp _dashan_msg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dashan_msg_gencpp)
add_dependencies(dashan_msg_gencpp dashan_msg_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dashan_msg_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/zhishancmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
)
_generate_msg_lisp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/Mode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
)
_generate_msg_lisp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/ribbontask.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
)
_generate_msg_lisp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/SaveMap.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
)
_generate_msg_lisp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/customRoute.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
)
_generate_msg_lisp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/imudata.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
)
_generate_msg_lisp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/xyyawdata.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
)
_generate_msg_lisp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/wheelSpeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
)
_generate_msg_lisp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/diagnosis.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
)
_generate_msg_lisp(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/hmiStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
)

### Generating Services

### Generating Module File
_generate_module_lisp(dashan_msg
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(dashan_msg_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(dashan_msg_generate_messages dashan_msg_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/zhishancmd.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_lisp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/Mode.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_lisp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/diagnosis.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_lisp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/SaveMap.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_lisp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/customRoute.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_lisp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/imudata.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_lisp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/xyyawdata.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_lisp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/wheelSpeed.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_lisp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/ribbontask.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_lisp _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/hmiStatus.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_lisp _dashan_msg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dashan_msg_genlisp)
add_dependencies(dashan_msg_genlisp dashan_msg_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dashan_msg_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/zhishancmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
)
_generate_msg_py(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/Mode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
)
_generate_msg_py(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/ribbontask.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
)
_generate_msg_py(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/SaveMap.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
)
_generate_msg_py(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/customRoute.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
)
_generate_msg_py(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/imudata.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
)
_generate_msg_py(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/xyyawdata.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
)
_generate_msg_py(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/wheelSpeed.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
)
_generate_msg_py(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/diagnosis.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
)
_generate_msg_py(dashan_msg
  "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/hmiStatus.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
)

### Generating Services

### Generating Module File
_generate_module_py(dashan_msg
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(dashan_msg_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(dashan_msg_generate_messages dashan_msg_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/zhishancmd.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_py _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/Mode.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_py _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/diagnosis.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_py _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/SaveMap.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_py _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/customRoute.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_py _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/imudata.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_py _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/xyyawdata.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_py _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/wheelSpeed.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_py _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/ribbontask.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_py _dashan_msg_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/zhishan/Dashan_demo_update/src/dashan_msg/msg/hmiStatus.msg" NAME_WE)
add_dependencies(dashan_msg_generate_messages_py _dashan_msg_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(dashan_msg_genpy)
add_dependencies(dashan_msg_genpy dashan_msg_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS dashan_msg_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/dashan_msg
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(dashan_msg_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/dashan_msg
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(dashan_msg_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/dashan_msg
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(dashan_msg_generate_messages_py std_msgs_generate_messages_py)
