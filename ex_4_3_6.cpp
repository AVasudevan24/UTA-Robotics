#include <ros/ros.h>
#include <unistd.h>
#include "texas_robotics_academy/texbot_wrapper.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot");
  bool leftRight;
  bool threePressed;
  int leftVal;
  int rightVal;
  int count;
  count=0;
  rightVal=0;
  leftVal=0;
  threePressed=false;
  leftRight=false;

  TexBot bot;

  while(ros::ok()) {
    
    bot.lcd1(leftVal, " ", rightVal);
    
    if (count%7000==0); {
    if (bot.readButton()==1) {
      threePressed=false;
      if (leftRight==false) {
        leftVal++;
      }
      else if (leftRight==true) {
        rightVal++;
      }
    }
    else if (bot.readButton()==2) {
      threePressed=false;
      if (leftRight==false) {
        leftVal--;
      }
      else if (leftRight==true) {
        rightVal--;
      }
    }
    //else if (bot.readButton()==2) {
        //threePressed=false;
    //}
    else if (bot.readButton()==3) {
      if (threePressed==false) {
        threePressed==true;
        leftRight=!leftRight;
      }
    }
    if (leftRight==false) {bot.lcd2 ("Left");}
    if (leftRight==true) {bot.lcd2 ("Right");}
    
  }
  count++;
  ros::spinOnce();
  }

  return 0;

}
