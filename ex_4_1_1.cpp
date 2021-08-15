#include <ros/ros.h>
#include <unistd.h>
#include "texas_robotics_academy/texbot_wrapper.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot");

  TexBot bot;

  while(ros::ok()) {
    bot.lcd1("How are you today?");
bot.lcd2("I'm doing great thanks");
    ros::spinOnce();
  }

  return 0;

}
