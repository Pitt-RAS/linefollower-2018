#include "Motor.h"
#include <Arduino.h>

Motor::Motor(int pin1, int pin2, int pwm_pin)
{
   pin1_ = pin1;
   pin2_ = pin2;
   pwm_pin_ = pwm_pin;
   pinMode(pin1_, OUTPUT);
   pinMode(pin2_, OUTPUT);
   pinMode(pwm_pin_, OUTPUT);
}

void Motor::output(int speed)
{
  analogWrite(pwm_pin, speed);
  digitalWrite(pin1_, LOW);
  digitalWrite(pin2_, HIGH); 
}