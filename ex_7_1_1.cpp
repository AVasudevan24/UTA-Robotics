#include <ros/ros.h>
#include <unistd.h>
#include "texas_robotics_academy/texbot_wrapper.h"


#define BEST_C 40.0
#define BEST_P 25.0
#define BEST_D 15.0
#define BEST_I 0.001

void printThreshold(TexBot &bot, int sensorArray[8]) {
    int threshold = 70;
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

void printDarkestPixel(TexBot &bot, int darkestPixel) {
    char asteriskLine[17];

    for(int i = 0; i < 8; i++) {
      if(i == darkestPixel) {
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

float followerValue(int darkestPixel) {
  return (((float)darkestPixel) - 3.5) / 3.5;
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "robot");

  TexBot bot;
  int sensorArray[8];

  float K_c = 20.0;
  float K_p = 100.0;
  float K_d = 5.0;
  float K_i = 0.01;
  float p_prev = 0.0;
  float i = 0.0;

  while(ros::ok()) {
    for(int cur = 0; cur < 8; cur++) {
      sensorArray[cur] = bot.readLineSensor(cur);
    }
    
    int darkestPixel = findDarkestPixel(sensorArray);
    printDarkestPixel(bot, darkestPixel);
    float p = followerValue(darkestPixel);
    float d = p - p_prev;

    p_prev = p;
    i += p;

    bot.lcd2(p);

    float leftMotor = K_c + (K_p * p + K_d * d + K_i * i);
    float rightMotor = K_c - (K_p * p  + K_d * d + K_i * i);

    bot.move(leftMotor, rightMotor);

    ros::spinOnce();

    usleep(50000);

  }

  return 0;

}