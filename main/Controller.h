#include <Arduino.h>
#ifndef CONTROLLER_H_
#define CONTROLLER_H_


class Controller{
private:
  // PID gains
  float kp_, ki_, kd_;
  // bounds for integral term (anti-windup)
  float i_lowerBound_, i_upperBound_;
  // integral term
  float i_term;
  int speedDifference;
  float errorSum;
  float lastError;
  float speedDifference_mag;
  float speedDifference_mapped;
  

public:
  Controller(float kp, float ki, float kd, float i_lowerBound, float i_upperBound);
  int calc_speedDiff(const float target_position, float current_position);
};

#endif
