#include <Arduino.h>

Controller::Controller

int Controller::Calculate(float target_pos, float current_pos) {
  // PID gains
  float kp = 5;
  float ki = 5;
  float kd = 5;
  // Upper bound and lower bound for error integral term
  float i_lowerBound = 40;
  float i_upperBound = -40;
  // Initialize sum of error
  float errorSum = 0;
  // Initialize last error
  float lastError = 0;
  // Initialize max speed of the motors
  int maxSpeed = 255;
  
  // calculate error between desired and actual position
  float error = setpoint_position - current_position;

  errorSum += error;
  i_term = ki * errorSum;
  i_term = constrain(i_term, i_lowerBound, i_upperBound);
  
  int speedDifference = kp * error + i_term + kd * (error - lastError); //do we need to divide the derivative term by the sample time?


  // Can either calculate left and right speed here and return array
  // or just return speed difference
  int rightSpeed = maxSpeed + speedDifference;
  int leftSpeed = maxSpeed - speedDifference;

  lastError = error;

  return speedDifference;
  
  
  
}
