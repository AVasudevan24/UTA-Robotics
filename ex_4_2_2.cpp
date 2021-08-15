#include <ros/ros.h>
#include <unistd.h>
#include "texas_robotics_academy/texbot_wrapper.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot");

  TexBot bot;
  double leftObstacleSensor(),rightObstacleSensor();
  
  

  while(ros::ok()) {
    if (bot.leftObstacleSensor()<5) {bot.lcd1("left sensor active");
    bot.ledLeft(true);
    }
    else if (bot.rightObstacleSensor()<5) {bot.lcd1("right sensor active");
    bot.ledRight(true);
    }
    else if (bot.rightObstacleSensor()<5 && bot.leftObstacleSensor()<5) {bot.lcd1("both sensors active");
    bot.ledRight(true);
    bot.ledLeft(true);
    }
    else {bot.lcd1 (" ");
    bot.ledLeft(false);
    bot.ledRight(false);
    }
    
    ros::spinOnce();
    usleep(1000000);
  }

  return 0;

}
