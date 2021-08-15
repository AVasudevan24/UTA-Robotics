#include <ros/ros.h>
#include <unistd.h>
#include "texas_robotics_academy/texbot_wrapper.h"

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot");

  TexBot bot;

  while(ros::ok()) {
    bot.lcd1("Hello World!");
    bot.lcd2("Texas Texas Robotics Academy!");
    int usleep(useconds_t usleep);
    usleep (2000000);
    bot.lcd1("Hook 'em!");
    bot.lcd2("Horns!!");
    usleep (2000000);
    ros::spinOnce();
  }

  return 0;

}
