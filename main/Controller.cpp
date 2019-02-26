#include <Arduino.h>
#include "Controller.h"

Controller::Controller(float kp, float ki, float kd, float i_lowerBound, float i_upperBound) {
  kp_ = kp;
  ki_ = ki;
  kd_ = kd;
  i_lowerBound_ = i_lowerBound;
  i_upperBound_ = i_upperBound;
  errorSum = 0;
  lastError = 0;
  i_term = 0;
}

int Controller::calc_speedDiff(const float target_position, float current_position) {
  
  // calculate error between desired and actual position
  float error = target_position - current_position;

  // caculate and constrain integral term
  errorSum += error;
  i_term = ki_ * errorSum;
  i_term = constrain(i_term, i_lowerBound_, i_upperBound_);
  
  int speedDifference = kp_ * error + i_term + kd_ * (error - lastError); //do we need to divide the derivative term by the sample time?

  // Can either calculate left and right speed here and return array
  // or just return speed difference
  //int rightSpeed = maxSpeed + speedDifference;
  //int leftSpeed = maxSpeed - speedDifference;

  lastError = error;

  return speedDifference;
  
}
