cmake_minimum_required(VERSION 2.8.3)
project(turtleLineDrive)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
  CATKIN_DEPENDS
)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}_node src/turtleLineDrive.cpp)

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
)
