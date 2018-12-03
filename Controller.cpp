#include <Arduino.h>
#include "Controller.h"

Controller::Controller(float kp, float ki, float kd, float i_lowerBound, float i_upperBound) {
  this->kp = kp;
  this->ki = ki;
  this->kd = kd;
  this->i_lowerBound = i_lowerBound;
  this->i_upperBound = i_upperBound;
  errorSum = 0;
  lastError = 0;
  i_term = 0;
}

int Controller::calc_speedDiff(const float target_pos, float current_pos) {
  
  // calculate error between desired and actual position
  float error = target_pos - current_pos;

  // caculate and constrain integral term
  errorSum += error;
  i_term = ki * errorSum;
  i_term = constrain(i_term, i_lowerBound, i_upperBound);
  
  int speedDifference = kp * error + i_term + kd * (error - lastError); //do we need to divide the derivative term by the sample time?

  // Can either calculate left and right speed here and return array
  // or just return speed difference
  //int rightSpeed = maxSpeed + speedDifference;
  //int leftSpeed = maxSpeed - speedDifference;

  lastError = error;

  return speedDifference;
  
}
