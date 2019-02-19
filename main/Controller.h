// Header file for Controller class

#ifndef Controller_h
#define Controller_h

#include "Arduino.h"

class Controller{
private:
  // PID gains
  float kp, ki, kd;
  // bounds for integral term (anti-windup)
  float i_lowerBound, i_upperBound;
  // integral term
  float i_term = 0;

public:
  float errorSum;
  float lastError;
  Controller(float kp, float ki, float kd, float i_lowerBound, float i_upperBound);
  calc_speedDiff(const float target_pos, float current_pos);
};

#endif
