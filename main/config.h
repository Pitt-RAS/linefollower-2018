#ifndef LINEFOLLOWER_CONF_H_
#define LINEFOLLOWER_CONF_H_

#include <Arduino.h>

//IR pins
#define IR1_PIN A2
//#define IR2_PIN A1
#define IR3_PIN A3
//#define IR4_PIN A3
#define IR5_PIN A4
//#define IR6_PIN A5
#define IR7_PIN A5
//#define IR8_PIN A7
#define IR9_PIN A6
#define NUM_SENSORS 5
#define CALIB_ARRAY_SIZE 10

#define PITCH 8 //distance between IR sensors in mm
#define CALIB_TO_LOW 1 //low value we want to map ir readings to
#define CALIB_TO_HIGH 1000 //high value we want to map ir readings to
#define CALIB_TIME 5000 //how long we want to calibrate for

//Motor pins
#define PWM_PIN_1 9
#define PWM_PIN_2 11
#define MOTOR_L_1 4 // D4
#define MOTOR_L_2 5 // D5
#define MOTOR_R_1 2 // D2
#define MOTOR_R_2 3 // D3
#define MAX_SPEED 50

//Controller parameters
#define K_P 1
#define K_I 1
#define K_D .01
#define I_LWR_BND -40
#define I_UPR_BND 40
#define SETPOINT 0

#endif
