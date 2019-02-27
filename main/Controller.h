#include <Arduino.h>

class Controller{
private:
  // PID gains
  float kp_, ki_, kd_;
  // bounds for integral term (anti-windup)
  float i_lowerBound_, i_upperBound_;
  // integral term
  float i_term = 0;

public:
  float errorSum;
  float lastError;
  Controller(float kp, float ki, float kd, float i_lowerBound, float i_upperBound);
  int calc_speedDiff(const float target_pos, float current_pos);
};


