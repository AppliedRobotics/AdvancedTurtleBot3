#include <ros/ros.h>
#include <std_msgs/Bool.h>
#include <geometry_msgs/Twist.h>

bool data = false;

void callback(std_msgs::Bool bol) {
	data = bol.data;
}

int main(int argc, char* argv[]) {
	ros::init(argc, argv, "turtle_line_drive");
	ros::NodeHandle nh;

	ros::Publisher myPub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
	ros::Subscriber mySub = nh.subscribe("line_sensor_data", 1000, callback);
	ros::Rate loop_rate(10);

	geometry_msgs::Twist twist;

	while (ros::ok()) {
		if (data) {
			twist.linear.x = 0.05;
			twist.angular.z = 0;
		}
		else {
			twist.linear.x = -0.05;
			twist.angular.z = 0;
		}

		myPub.publish(twist);
		ros::spinOnce();
		loop_rate.sleep();
	}
	ros::spin();
}