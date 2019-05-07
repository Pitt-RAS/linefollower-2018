#include <Arduino.h>
#include "Controller.h"
#include "config.h"

Controller::Controller(float kp, float ki, float kd, float i_lowerBound, float i_upperBound) {
  // PID gains
  kp_ = kp;
  ki_ = ki;
  kd_ = kd;

  // bounds for integral term
  i_term = 0;
  i_lowerBound_ = i_lowerBound;
  i_upperBound_ = i_upperBound;

  // error sum and previous error
  errorSum = 0;
  lastError = 0;

  // speed difference
  speedDifference = 0;
}

int Controller::calc_speedDiff(float current_position) {
  
  // calculate error between desired and actual position
  float error =  current_position - SETPOINT; 

  // caculate and constrain integral term
  errorSum += error;
  i_term = ki_ * errorSum;
  i_term = constrain(i_term, i_lowerBound_, i_upperBound_);

  // calculate pre-mapped speed difference 
  speedDifference = kp_ * error  + i_term + kd_ * (error - lastError);

  // take absolute value and map it to the range between what we've observed to be the min and max PID values
  speedDifference_mag = abs(speedDifference);
  speedDifference_mapped = map(speedDifference_mag, 0, kp_*16 + 40 + 16, 0 , 20);

  // copy the sign of the original speed difference onto the magnitude of the mapped speed difference
  speedDifference = copysign(speedDifference_mapped,speedDifference);
  
  lastError = error;

  return speedDifference;
  
}
