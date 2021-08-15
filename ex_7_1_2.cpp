#include <ros/ros.h>
#include <unistd.h>
#include "texas_robotics_academy/texbot_wrapper.h"

void printThreshold(TexBot &bot, int sensorArray[8]) {
    int threshold = 145;
    char asteriskLine[17];

    for(int i = 0; i < 8; i++) {
      if(sensorArray[i] > threshold) {
        asteriskLine[i * 2] = '*';
        asteriskLine[i * 2 + 1] = '*';
      } else {
        asteriskLine[i * 2] = '-';
        asteriskLine[i * 2 + 1] = '-';
      }
    }
    asteriskLine[16] = 0;

    bot.lcd1(asteriskLine);

}

int findDarkestPixel(int sensorArray[8]) {
  int darkestPixel = 0;
  int darkestValue = 0;

  for(int i = 0; i < 8; i++) {
    if(sensorArray[i] > darkestValue) {
      darkestPixel = i;
      darkestValue = sensorArray[i];
    }
  }

  return darkestPixel;
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot");

  TexBot bot;
  int sensorArray[8];
while(ros::ok()) {
    for(int i = 0; i < 8; i++) {
      sensorArray[i] = bot.readLineSensor(i);
    }

    int darkestPixel = findDarkestPixel(sensorArray);
    bot.lcd2((darkestPixel-3.5)/3.5);

    char asteriskLine[17];

    for(int i = 0; i < 8; i++) {
      if(i == darkestPixel) {
        asteriskLine[i * 2] = '*';
        asteriskLine[i * 2 + 1] = '*';
      } else {
        asteriskLine[i * 2] = '-';
        asteriskLine[i * 2]
    asteriskLine[16] = 0;

    bot.lcd1(asteriskLine);

    //printThreshold(bot, sensorArray);

    ros::spinOnce();

    usleep(200000);

  }

  return 0;

}
