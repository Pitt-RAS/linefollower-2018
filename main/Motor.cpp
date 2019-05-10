#include "Motor.h"
#include <Arduino.h>

Motor::Motor(int pin1, int pin2, int pwm_pin){
  // the direction pins
   pin1_ = pin1;
   pin2_ = pin2;

   // the speed pin
   pwm_pin_ = pwm_pin;

   // set the pin modes to outputs
   pinMode(pin1_, OUTPUT);
   pinMode(pin2_, OUTPUT);
   pinMode(pwm_pin_, OUTPUT);
}

void Motor::output(int dif, int dir){
  // write speed and direction to pins

  // dir = 0 --> spin forward
  // dir = 1 --> spin backward

  analogWrite(pwm_pin_, dif);     
  digitalWrite(pin1_, dir);     
  digitalWrite(pin2_, 1-dir);  
}
