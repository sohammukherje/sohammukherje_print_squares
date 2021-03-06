#include "ros/ros.h"
#include "std_msgs/Int32.h"

std_msgs::Int32 square;                                               //creating a message object which will contain data
 
ros::Publisher no_square_publish;

void callBack(const std_msgs::Int32::ConstPtr& message)                   //define the callback function
{
 
 square.data = (message->data)*(message->data);                            //computation of squares
 
 ROS_INFO("The received number is [%1d]\n",(int)message->data);
 
 no_square_publish.publish(square);                                         //publishing the message through creted publisher
  
 ROS_INFO("The published square number is [%1d]\n",square.data);             //alternative for cout;it prints the output
}

 int main(int argc, char **argv)
{
 ros::init(argc, argv, "sohammukherje_squares");                           //initialization and naming the node sohammukherje_squares
 
 ros::NodeHandle NH2;                                                      //creating a node-handle which will serve as access point for communications
 
 no_square_publish = NH2.advertise<std_msgs::Int32>("topic_squares",500);  //creating the publisher no_square_publish using advertise function
 
 ros::Subscriber no_subscribe = NH2.subscribe("topic_numbers",500,callBack); //creatig a subscriber no_subscribe which can subscribe to incoming messages from "topic numbers"

 ros::Rate loop_rate(1);

 loop_rate.sleep();
 
 ros::spin();                                                              //needed for performing thne callback operation
 
 return 0;
}


