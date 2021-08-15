#include <ros/ros.h>
#include <unistd.h>
#include "texas_robotics_academy/texbot_wrapper.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot");
  bool leftRight;
  bool threePressed;
  threePressed=false;
  leftRight=false;

  TexBot bot;

  while(ros::ok()) {
    if (bot.readButton()==0) {bot.lcd1 ("no button is being pressed");}
    else if (bot.readButton()==1) {bot.lcd1 ("Button 1 pressed");
    threePressed=false;
    }
    else if (bot.readButton()==2) {bot.lcd1 ("Button 2 is pressed");
    threePressed=false;}
    else if (bot.readButton()==3) {bot.lcd1 ("Button 3 is pressed");
    
    if (threePressed==false) {
    threePressed=true;
    if (leftRight==false) {leftRight=true;}
    else {leftRight=false;}
    }}
    if (leftRight==false) {bot.lcd2 ("Left");}
    if (leftRight==true) {bot.lcd2 ("Right");}
    ros::spinOnce();
  }

  return 0;

}
