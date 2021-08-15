#include <ros/ros.h>
#include <unistd.h>
#include "texas_robotics_academy/texbot_wrapper.h"
using namespace std
int main(int argc, char **argv) {
  
  ros::init(argc, argv, "robot");

  TexBot bot;

  while(ros::ok()) {
    
    for(int i=0, i<8, i++){
      int sensorNum = bot.readLineSensor();
      cout << sensorNum << endl;
    }
    
    ros::spinOnce();
  }

  return 0;

}
