cmake_minimum_required(VERSION 3.8)
project(communication)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

set(dependencies 
  rclcpp
  std_msgs
)

include_directories(
	${PROJECT_SOURCE_DIR}/include
)

add_executable(communication src/node_main.cc)
ament_target_dependencies(communication ${dependencies})

# ############################ topic tutorial ############################
add_executable(hello_world_publisher_tutorial tutorials/topic/hello_world_publisher_tutorial.cc)
ament_target_dependencies(hello_world_publisher_tutorial ${dependencies})

install(TARGETS 
  communication
  hello_world_publisher_tutorial
  DESTINATION lib/${PROJECT_NAME})

ament_package()
