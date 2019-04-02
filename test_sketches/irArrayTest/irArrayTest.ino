#include "config.h"
#include "irArray.h"

//float calib_from_vals[NUM_SENSORS*2];
/*
int* pins = NULL;
pins = new int[NUM_SENSORS];
pins[0] = IR1_PIN;
pins[1] = IR2_PIN;
pins[2] = IR3_PIN;
pins[3] = IR4_PIN;
pins[4] = IR5_PIN;
irArray test(pins, PITCH);
*/


void setup() {
  Serial.begin(9600);
  //Serial.println(A0);
  int* pins = NULL;
  pins = new int[NUM_SENSORS];
  pins[0] = IR1_PIN;
  pins[1] = IR2_PIN;
  pins[2] = IR3_PIN;
  pins[3] = IR4_PIN;
  pins[4] = IR5_PIN;
  for (int i = 0; i < NUM_SENSORS; i++){
    pinMode(pins[i], INPUT);
  }
  irArray test(pins, PITCH); //irArray test object
  
  Serial.println("Start");
  test.calibrate();
  Serial.println(test.get_calib()[9]); //first pin lower bound
  Serial.println(test.get_calib()[8]); //first pin upper bound

   

  
  //delete[] pins;

  /*
  for (int i = 0; i < 10; i++){
    Serial.print(test.get_calib()[i]);
    Serial.print("\n");
  }
  */

  float* irVal = new float[NUM_SENSORS];
  int startTime = millis();
   int currentTime = millis();

   while(currentTime-startTime<10000){
    irVal = test.read();
    Serial.println(test.interpolate(irVal));
    for(int i=0; i<NUM_SENSORS;i++){
    //Serial.println(irVal[i]);
    }
    currentTime = millis();
    delay(100);
   }
  

/*  
  for (int i = 0; i < 5; i++){
    
    //Serial.print(test.read()[i]);
    Serial.print("\n");
  }
  */
}


void loop() {
  

}
