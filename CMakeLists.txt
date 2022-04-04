cmake_minimum_required(VERSION 2.8.3)
project(onrobot_gripper)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  ur_msgs
)

################################################
## Declare ROS messages, services and actions ##
################################################

add_service_files(
  FILES
  command_gripper_srv.srv
)

generate_messages(
  DEPENDENCIES
  ${PROJECT_NAME}
)

###################################
## catkin specific configuration ##
###################################

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES onrobot_gripper
  CATKIN_DEPENDS message_runtime
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

##################################################################################################

# OnRobot Gripper Library

add_library(onrobot_gripper src/onrobot_gripper.cpp)
target_link_libraries(onrobot_gripper ${catkin_LIBRARIES})
add_dependencies(onrobot_gripper ${catkin_EXPORTED_TARGETS} ${${PROJECT_NAME}_EXPORTED_TARGETS})

add_executable(onrobot_gripper_Node src/onrobot_gripper_Node.cpp src/onrobot_gripper.cpp)
target_link_libraries(onrobot_gripper_Node ${catkin_LIBRARIES})
add_dependencies(onrobot_gripper_Node ${catkin_EXPORTED_TARGETS} ${${PROJECT_NAME}_EXPORTED_TARGETS})


##################################################################################################
