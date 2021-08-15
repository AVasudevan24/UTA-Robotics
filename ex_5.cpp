#include <ros/ros.h>
#include <unistd.h>
#include "texas_robotics_academy/texbot_wrapper.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot");

  TexBot bot;

  while(ros::ok()) {
    bot.move (20,20);
    if (bot.leftObstacleSensor()<0.5 || bot.rightObstacleSensor()<0.5) {
      if (bot.leftObstacleSensor()>bot.rightObstacleSensor()) {bot.move (-30,-20);}
      else {bot.move (-20,-30);}
      }
    usleep (1000000);
    bot.move (80,80);
    ros::spinOnce();
  }

  return 0;

}
