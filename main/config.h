#ifndef LINEFOLLOWER_CONF_H_
#define LINEFOLLOWER_CONF_H_

#include <Arduino.h>

// IR pins
// only odd numbered pins were used because we ran out of pins on the Arduino Nano
#define IR1_PIN A2
//#define IR2_PIN A1
#define IR3_PIN A3
//#define IR4_PIN A3
#define IR5_PIN A4
//#define IR6_PIN A5
#define IR7_PIN A5
//#define IR8_PIN A7
#define IR9_PIN A6

// number of individual IR's we are using the size of the calibration array 
#define NUM_SENSORS 5
#define CALIB_ARRAY_SIZE 10

#define PITCH 8             //distance between IR sensors in mm
#define CALIB_TO_LOW 1      //low value we want to map IR readings to
#define CALIB_TO_HIGH 1000  //high value we want to map IR readings to
#define CALIB_TIME 5000     //how long we want to calibrate for in ms

// motor pins
#define PWM_PIN_1 11
#define PWM_PIN_2 9
#define MOTOR_L_1 4 // D4
#define MOTOR_L_2 5 // D5
#define MOTOR_R_1 2 // D2
#define MOTOR_R_2 3 // D3

// the speed we will add and subtract the speed difference from, for each motor
// the right motor seemed to spin at a slightly slower speed even when given the same PWM
#define MAX_SPEED_R 29 // = 1.16*25
#define MAX_SPEED_L 25 

// controller parameters

#define K_P 1
#define K_I 1
#define K_D .01
#define I_LWR_BND -40
#define I_UPR_BND 40
#define SETPOINT 0

#endif
