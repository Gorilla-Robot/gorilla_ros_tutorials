cmake_minimum_required(VERSION 3.8)
project(general_framework)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

set(dependencies 
  rclcpp
)

include_directories(
	${PROJECT_SOURCE_DIR}/include
)

add_executable(general_framework src/node_main.cc)
ament_target_dependencies(general_framework ${dependencies})

install(TARGETS 
  general_framework
  DESTINATION lib/${PROJECT_NAME})

ament_package()
