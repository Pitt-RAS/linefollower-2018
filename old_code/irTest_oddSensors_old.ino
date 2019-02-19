int AnalogInputPin0 = A0;
//int AnalogInputPin2 = A0;
int AnalogInputPin1 = A1;
//int AnalogInputPin4 = A3;
int AnalogInputPin2 = A2;
//int AnalogInputPin6 = A5;
int AnalogInputPin3 = A3;
//int AnalogInputPin8 = A7;
int AnalogInputPin4 = A4;

int ir1 = 0;
int ir3 = 0;
int ir5 = 0;
int ir7 = 0;
int ir9 = 0;



int finalIrVal = 0;
int weightedAvg = 0;
float error = 0;


int WeightedAvg(int sensorNum) {
  weightedAvg = (sensorNum*4*(5-sensorNum)); //pitch in mm
  return weightedAvg;
}

float calculateError(){
  int num = (WeightedAvg(9)*(ir9-ir1) + WeightedAvg(7)*(ir7-ir3));
  int den = ir1+ir3+ir5+ir7+ir9;

  error = num/den;
  return error;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(AnalogInputPin1, INPUT);
  pinMode(AnalogInputPin2, INPUT);
  //pinMode(AnalogInputPin3, INPUT);

}


void loop() {
  // put your main code here, to run repeatedly:
  ir1 = analogRead(AnalogInputPin0);
  ir3 = analogRead(AnalogInputPin1);
  ir5 = analogRead(AnalogInputPin2);
  ir7 = analogRead(AnalogInputPin3);
  ir9 = analogRead(AnalogInputPin4);

  calculateError();

  Serial.println(error);  

  delay(100);

}
