#include <ros/ros.h>
#include <unistd.h>
#include "texas_robotics_academy/texbot_wrapper.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot");
  double leftObstacleSensor,rightObstacleSensor;
  
  TexBot bot;


  while(ros::ok()) {
    leftObstacleSensor=bot.leftObstacleSensor();
    rightObstacleSensor=bot.rightObstacleSensor();
    bot.move(100,100);
    if (leftObstacleSensor<3 || rightObstacleSensor<3) {bot.move (-100,-100);}
    ros::spinOnce();
    usleep (10000);
  }

  return 0;

}
