#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <sstream>

int main(int argc, char **argv)
{

 ros::init(argc, argv, "sohammukherje_numbers");             //initializing and naming the node sohammukherje_numbers 
 
 ros::NodeHandle NH;                                         //access point for communications created
 
 ros::Publisher topic_numbers_pub = NH.advertise<std_msgs::Int32>("topic_numbers", 500);     
 //created a publisher named topic_numbers_pub. the advertise function expresses my desire to publish on a topic name
 
 ros::Rate loop_rate(1);                                     //setting the frequency to 1 Hz
 
 int count=1;
 
 std_msgs::Int32 message;                                    //this is a message object that will contain some data
 
 while (ros::ok())
 {
  message.data=count; 
 
  ++count;
 
  ROS_INFO("The published number is [%d]\n", message.data);  //ROS_INFO serves as a kind of an alternative for the cout function
  
  topic_numbers_pub.publish(message);                        //publishes the message through the created publisher
  
  ros::spinOnce();                                           //necessary in case there are any callbacks
  
  loop_rate.sleep();  
  //a thread sleep with duration defined by the used frequency which is 1Hz in    this  case                             
 }
 
 return 0;
} 
  

