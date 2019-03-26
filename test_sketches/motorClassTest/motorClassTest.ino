#include "config.h"
#include "Motor.h"

Motor motor1(A2, A3, 5);
Motor motor2(A4, A5, 11);

/*
 * motor 1 - A2, A3, 5
 * motor 2 - A4, A5, 11
 */

void setup() {
  Serial.begin(9600);

 

  //test_speed = MAX_SPEED/2;
  
}

void loop() {
  motor1.output(MAX_SPEED/2);
  motor2.output(MAX_SPEED/2);
}
