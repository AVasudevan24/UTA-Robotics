#include <ros/ros.h>
#include <unistd.h>
#include "texas_robotics_academy/texbot_wrapper.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot");
  //int readButton();
  //int input;
  //input=1

  TexBot bot;

  while(ros::ok()) {
    //input = readButton();
    if (bot.readButton()==0) {bot.lcd1 ("no button is being pressed");}
    else if (bot.readButton()==1) {bot.lcd1 ("Button 1 pressed");}
    else if (bot.readButton()==2) {bot.lcd1 ("Button 2 is pressed");}
    else if (bot.readButton()==3) {bot.lcd1 ("Button 3 is pressed");}
    ros::spinOnce();
  }

  return 0;

}
