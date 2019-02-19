#include <irArray.h>
#include <Arduino.h>

irArray sensor1({'A1', 'A2', 'A3', 'A4'}, 4)
sensor1.read()

class irArray {
private:

int pitch_ 
char pins_[NUM_SENSORS]

public:

irArray::irArray(char pins[num_sensors], int pitch){
    //char* pins_[num_sensors]
    pins_ = pins
    pitch_ = pitch
    for (i = 0, i < NUM_SENSORS, i++){
        pins_[i] = pins[i];
    }
}

irArray::Calibrate(){
    
        
}

int irArray::WeightedAverage(float arr[]){
    float sum_n = 0;
    float sum_d = 0;
    for (i=0; i < int(NUM_SENSORS/2); i++){
        sum_n += (pitch*((NUM_SENSORS/2)-i)) * (arr[NUM_SENSORS - i] - arr[i]); 
        sum_d += arr[i];
    }
    return sum_n/sum_d;

}


float irArray::Read(){
    float IR_values[NUM_SENSORS];
    for (i= 0; i < NUM_SENSORS; i++){
        IR_values[i] = analogRead(pins_[i]);
    }
    return IR_values;
}



