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

}


void loop() {
  // put your main code here, to run repeatedly:
  ir1 = analogRead(AnalogInputPin0);
  ir3 = analogRead(AnalogInputPin1);
  ir5 = analogRead(AnalogInputPin2);
  ir7 = analogRead(AnalogInputPin3);
  ir9 = analogRead(AnalogInputPin4);

  calculateError();

  Serial.println(ir1);  

  delay(100);

}
