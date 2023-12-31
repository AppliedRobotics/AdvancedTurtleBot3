#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>

double x = 0.0;
double y = 0.0;
double th = 0.0;

double VX = 0;
double VTH = 0;

double vleft = 0.0;
double vright = 0.0;
double vth = 0.0;

void cbMessage(const geometry_msgs::Vector3 &arr) {
  vleft  = arr.x;
  vright = arr.y;

}

int main(int argc, char** argv){
  ros::init(argc, argv, "odometry_publisher");

  ros::NodeHandle n;
  ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
  ros::Subscriber sub = n.subscribe("velocity_data", 1000, cbMessage);
  tf::TransformBroadcaster broadcaster;
  //tf::TransformBroadcaster lidar_broadcaster;

  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();
    ROS_INFO("Odom init");
  ros::Rate r(10);
  while(n.ok()){

    ros::spinOnce();              
    current_time = ros::Time::now();

    double temp1 = (0.033 * (vleft + vright)) / 2;
    double temp2 = (0.033 * (vright - vleft)) / 0.155;

    double delta_s = temp1 * 0.1;
    double delta_a = temp2 * 0.1;

    th += delta_a;
    x += (delta_s * cos(th));
    y += (delta_s * sin(th));

    //next, we'll publish the odometry message over ROS
    nav_msgs::Odometry odom;
    odom.header.stamp = current_time;
    odom.header.frame_id = "odom";
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);
    //set the position
    odom.pose.pose.position.x = x;
    odom.pose.pose.position.y = y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;

    //set the velocity
    odom.child_frame_id = "base_footprint";
    odom.twist.twist.linear.x = temp1;
    odom.twist.twist.linear.y = 0;
    odom.twist.twist.angular.z = temp2;

    //publish the message
    odom_pub.publish(odom);

    //since all odometry is 6DOF we'll need a quaternion created from yaw
   

    //first, we'll publish the transform over tf
    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = current_time;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_footprint";

    odom_trans.transform.translation.x = x;
    odom_trans.transform.translation.y = y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;



    geometry_msgs::TransformStamped lidar_trans;
    lidar_trans.header.stamp = current_time;
    lidar_trans.header.frame_id = "base_footprint";
    lidar_trans.child_frame_id = "base_scan";

    lidar_trans.transform.translation.x = 0;
    lidar_trans.transform.translation.y = 0;
    lidar_trans.transform.translation.z = 0.15;
    geometry_msgs::Quaternion lidar_quat = tf::createQuaternionMsgFromYaw(0);
    lidar_trans.transform.rotation = lidar_quat;

    //send the transform
    broadcaster.sendTransform(lidar_trans);
    broadcaster.sendTransform(odom_trans);
    

    

    last_time = current_time;
    r.sleep();
  }
}

/*#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>

double x = 0.0;
double y = 0.0;
double th = 0.0;

double VX = 0;
double VTH = 0;

double vx = 0.0;
double vy = 0.0;
double vth = 0.0;

void cbMessage(const geometry_msgs::Vector3 &arr) {
  vx  = arr.x;
  vth = arr.y;

}

int main(int argc, char** argv){
  ros::init(argc, argv, "odometry_publisher");

  ros::NodeHandle n;
  ros::Publisher odom_pub = n.advertise<nav_msgs::Odometry>("odom", 50);
  ros::Subscriber sub = n.subscribe("velocity_data", 1000, cbMessage);
  tf::TransformBroadcaster odom_broadcaster;
  tf::TransformBroadcaster lidar_broadcaster;

  ros::Time current_time, last_time;
  current_time = ros::Time::now();
  last_time = ros::Time::now();
    ROS_INFO("LOL");
  ros::Rate r(100);
  while(n.ok()){

    ros::spinOnce();              
    current_time = ros::Time::now();

    double temp1 = (0.033 * (vx + vth)) / 2;
    double temp2 = (0.033 * (vth - vx)) / 0.155;

    double delta_s = temp1 * 0.01;
    double delta_a = temp2 * 0.01;

    th += delta_a;
    x += (delta_s * cos(th));
    y += (delta_s * sin(th));

    //since all odometry is 6DOF we'll need a quaternion created from yaw
    geometry_msgs::Quaternion odom_quat = tf::createQuaternionMsgFromYaw(th);

    //first, we'll publish the transform over tf
    geometry_msgs::TransformStamped odom_trans;
    odom_trans.header.stamp = current_time;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_footprint";

    odom_trans.transform.translation.x = x;
    odom_trans.transform.translation.y = y;
    odom_trans.transform.translation.z = 0.0;
    odom_trans.transform.rotation = odom_quat;



    geometry_msgs::TransformStamped lidar_trans;
    lidar_trans.header.stamp = current_time;
    lidar_trans.header.frame_id = "base_footprint";
    lidar_trans.child_frame_id = "base_scan";

    lidar_trans.transform.translation.x = 0;
    lidar_trans.transform.translation.y = 0;
    lidar_trans.transform.translation.z = 0.15;
    lidar_trans.transform.rotation = odom_quat;

    //send the transform
    lidar_broadcaster.sendTransform(lidar_trans);
    odom_broadcaster.sendTransform(odom_trans);
    

    //next, we'll publish the odometry message over ROS
    nav_msgs::Odometry odom;
    odom.header.stamp = current_time;
    odom.header.frame_id = "odom";

    //set the position
    odom.pose.pose.position.x = x;
    odom.pose.pose.position.y = y;
    odom.pose.pose.position.z = 0.0;
    odom.pose.pose.orientation = odom_quat;

    //set the velocity
    odom.child_frame_id = "base_link";
    odom.twist.twist.linear.x = vx;
    odom.twist.twist.linear.y = vy;
    odom.twist.twist.angular.z = vth;

    //publish the message
    odom_pub.publish(odom);

    last_time = current_time;
    r.sleep();
  }
}*/