# Install script for directory: /home/ruslan/my_catkin_ws/src/advanced_turtlebot3/advanced_turtlebot3_slam

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ruslan/my_catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/ruslan/my_catkin_ws/build/advanced_turtlebot3/advanced_turtlebot3_slam/catkin_generated/installspace/advanced_turtlebot3_slam.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/advanced_turtlebot3_slam/cmake" TYPE FILE FILES
    "/home/ruslan/my_catkin_ws/build/advanced_turtlebot3/advanced_turtlebot3_slam/catkin_generated/installspace/advanced_turtlebot3_slamConfig.cmake"
    "/home/ruslan/my_catkin_ws/build/advanced_turtlebot3/advanced_turtlebot3_slam/catkin_generated/installspace/advanced_turtlebot3_slamConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/advanced_turtlebot3_slam" TYPE FILE FILES "/home/ruslan/my_catkin_ws/src/advanced_turtlebot3/advanced_turtlebot3_slam/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/advanced_turtlebot3_slam/flat_world_imu_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/advanced_turtlebot3_slam/flat_world_imu_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/advanced_turtlebot3_slam/flat_world_imu_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/advanced_turtlebot3_slam" TYPE EXECUTABLE FILES "/home/ruslan/my_catkin_ws/devel/lib/advanced_turtlebot3_slam/flat_world_imu_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/advanced_turtlebot3_slam/flat_world_imu_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/advanced_turtlebot3_slam/flat_world_imu_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/advanced_turtlebot3_slam/flat_world_imu_node"
         OLD_RPATH "/opt/ros/noetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/advanced_turtlebot3_slam/flat_world_imu_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/advanced_turtlebot3_slam" TYPE DIRECTORY FILES "/home/ruslan/my_catkin_ws/src/advanced_turtlebot3/advanced_turtlebot3_slam/include/advanced_turtlebot3_slam/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/advanced_turtlebot3_slam" TYPE DIRECTORY FILES
    "/home/ruslan/my_catkin_ws/src/advanced_turtlebot3/advanced_turtlebot3_slam/bag"
    "/home/ruslan/my_catkin_ws/src/advanced_turtlebot3/advanced_turtlebot3_slam/config"
    "/home/ruslan/my_catkin_ws/src/advanced_turtlebot3/advanced_turtlebot3_slam/launch"
    "/home/ruslan/my_catkin_ws/src/advanced_turtlebot3/advanced_turtlebot3_slam/rviz"
    )
endif()

