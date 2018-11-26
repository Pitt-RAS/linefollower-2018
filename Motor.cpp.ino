#include "Motor.h"
Motor::Motor(int IN1, int IN2, int PWM)
{
   this -> IN1 = IN1;
   this -> IN2 = IN2;
   this -> PWM = PWM;
}

void Motor::output(int dif)
{
  int speed = 150 + dif;
  //int leftSpeed = 150 - dif;
  analogWrite(PWM, speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(1000); 
}
