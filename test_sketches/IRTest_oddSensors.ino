int AnalogInputPin0 = A0;
//int AnalogInputPin2 = A0;
int AnalogInputPin1 = A1;
//int AnalogInputPin4 = A3;
int AnalogInputPin2 = A2;
//int AnalogInputPin6 = A5;
int AnalogInputPin3 = A3;
//int AnalogInputPin8 = A7;
int AnalogInputPin4 = A4;

// raw IR values
int ir1 = 0;
int ir3 = 0;
int ir5 = 0;
int ir7 = 0;
int ir9 = 0;
int pitch = 4; //distance between IR sensors in mm

int sensor_dist = 0;
float error = 0;

// calibration ranges
int low1;
int high1;
int low3;
int high3;
int low5;
int high5;
int low7;
int high7;
int low9;
int high9;

//calculates distance between a given sensor and the middle of the array board
//only for IR arrays with an odd number of sensors
int sensor_distance(int sensorNum) {
  //sensorNum is the number of the sensor counting from left to right
  //5 is the ir in the  middle of the array
  sensor_dist = pitch*(5-sensorNum);
  return sensor_dist ;
}

// calculates how far the line is from the center of the robot with a weighted average
float calculateError(){
  int num = (sensor_distance(9)*(ir9-ir1) + sensor_distance(7)*(ir7-ir3));
  int den = ir1+ir3+ir5+ir7+ir9;

  error = num/den;
  return error;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(AnalogInputPin0, INPUT);
  pinMode(AnalogInputPin1, INPUT);
  pinMode(AnalogInputPin2, INPUT);
  pinMode(AnalogInputPin3, INPUT);
  pinMode(AnalogInputPin4, INPUT);
  calibration();
}

void calibration(){
  int start = millis();
  int current = millis();
  int value1 = analogRead(AnalogInputPin0);
  int value3 = analogRead(AnalogInputPin1);
  int value5 = analogRead(AnalogInputPin2);
  int value7 = analogRead(AnalogInputPin3);
  int value9 = analogRead(AnalogInputPin4);
  low1 = value1;high1 = value1;
  low3 = value3;high1 = value3;
  low5 = value5;high1 = value5;
  low7 = value7;high1 = value7;
  low9 = value9;high1 = value9;
  
  while((current-start)<5000){
    value1 = analogRead(AnalogInputPin0);
    value3 = analogRead(AnalogInputPin1);
    value5 = analogRead(AnalogInputPin2);
    value7 = analogRead(AnalogInputPin3);
    value9 = analogRead(AnalogInputPin4);
    if(value1 > high1){
      high1 = value1;
    }
    else if(value1 < low1){
      low1 = value1;
    }
    if(value3 > high3){
      high3 = value3;
    }
    else if(value3 < low3){
      low3 = value3;
    }
    if(value5 > high5){
      high5 = value5;
    }
    else if(value5 < low5){
      low5 = value5;
    }
    if(value7 > high7){
      high7 = value7;
    }
    else if(value7 < low7){
      low7 = value7;
    }
    if(value9 > high9){
      high9 = value9;
    }
    else if(value9 < low9){
      low9 = value9;
    }
    current = millis();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  ir1 = analogRead(AnalogInputPin0);
  ir3 = analogRead(AnalogInputPin1);
  ir5 = analogRead(AnalogInputPin2);
  ir7 = analogRead(AnalogInputPin3);
  ir9 = analogRead(AnalogInputPin4);

  ir1 = map(ir1,low1,high1,0,100);
  ir1 = constrain(ir1,0,100);
  ir3 = map(ir3,low3,high3,0,100);
  ir3 = constrain(ir3,0,100);
  ir5 = map(ir5,low5,high5,0,100);
  ir5 = constrain(ir5,0,100);
  ir7 = map(ir7,low7,high7,0,100);
  ir7 = constrain(ir7,0,100);
  ir9 = map(ir9,low9,high9,0,100);
  ir9 = constrain(ir9,0,100);

  Serial.println(ir9);

  delay(100);

}
