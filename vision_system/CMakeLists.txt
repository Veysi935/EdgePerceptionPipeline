cmake_minimum_required(VERSION 3.8)
project(vision_system)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(sensor_node src/sensor_node.cpp)
target_link_libraries(sensor_node ${OpenCV_LIBS})
ament_target_dependencies(sensor_node rclcpp std_msgs sensor_msgs cv_bridge)

add_executable(perception_node src/perception_node.cpp)
target_link_libraries(perception_node ${OpenCV_LIBS})
ament_target_dependencies(perception_node rclcpp std_msgs sensor_msgs cv_bridge)

install(TARGETS sensor_node perception_node DESTINATION lib/${PROJECT_NAME})
ament_package()