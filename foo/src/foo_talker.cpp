#include <ros/ros.h>
#include <foo_msgs/Foo.h>

int main(int argc, char ** argv)
{
  ros::init(argc, argv, "foo_talker");
  ros::NodeHandle nh;

  auto pub = nh.advertise<foo_msgs::Foo>("foo", 10);

  foo_msgs::Foo msg; 
  msg.bar = 0;

  ros::Rate rate(1.0);
  while (ros::ok()) {
    ROS_INFO("[ROS 1 talker] publishing message %d", msg.bar);
    pub.publish(msg);
    ros::spinOnce();
    rate.sleep();
    msg.bar++;
  }

  return 0;
}
