execute_process(COMMAND "/home/ruslan/my_catkin_ws/build/advanced_turtlebot3/advanced_turtlebot3_teleop/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/ruslan/my_catkin_ws/build/advanced_turtlebot3/advanced_turtlebot3_teleop/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
