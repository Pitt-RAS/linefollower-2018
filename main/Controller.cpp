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
  speedDifference = 0;
}

int Controller::calc_speedDiff(const float target_position, float current_position) {
  
  // calculate error between desired and actual position
  float error =  current_position - target_position; 

  // caculate and constrain integral term
  errorSum += error;
  i_term = ki_ * errorSum;
  i_term = constrain(i_term, i_lowerBound_, i_upperBound_);
  
  speedDifference = kp_ * error + i_term + kd_ * (error - lastError); //do we need to divide the derivative term by the sample time?
  speedDifference_mag = abs(speedDifference);
  speedDifference_mapped = map(speedDifference_mag, 0, kp_*16 + 40 + 16, 0 , 255);

  speedDifference = copysign(speedDifference_mapped,speedDifference);
  

  // Can either calculate left and right speed here and return array
  // or just return speed difference
  //int rightSpeed = maxSpeed + speedDifference;
  //int leftSpeed = maxSpeed - speedDifference;

  lastError = error;

  return speedDifference;
  
}
