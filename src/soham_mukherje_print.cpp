#include "ros/ros.h"
#include "std_msgs/Int32.h"

void no_callback(const std_msgs::Int32::ConstPtr& message)
 {
  ROS_INFO("the recieved number is [%d]\n", message->data);                  //alternative to cout;it prints out the numbers
 }

void square_callback(const std_msgs::Int32::ConstPtr& message)
 {
  ROS_INFO("the recieved square is [%d]\n", message->data);                  //alternative to cout;it prints out the squares
 }

int main(int argc, char **argv)
{
 ros::init(argc, argv, "soham_mukherje_print");                               //initialization and naming the node "soham_mukherje_print"
 
 ros::NodeHandle NH3;                                                         //creating the node handle
  
 ros::Rate loop_rate(1);
 ros::Subscriber no_subscriber = NH3.subscribe<std_msgs::Int32>("topic_numbers",500,no_callback) ;                                            
 //subscribing to the incoming message from "topic_numbers" through NH3 (the created suscriber)
 
 loop_rate.sleep();
 
 ros::Subscriber sqr_subscriber = NH3.subscribe<std_msgs::Int32>("topic_squares",500,square_callback) ;
 //subscribing to the incoming message from "topic_squares" through NH3 (the created suscriber)                                      
 
 ros::spin()  ;                                                                //necessary for performing callbacks
 return 0;
}
