
int PWMOutputPin = 5; //only some pins on the Arduino can be used for PWM
int DigitalOutputPin1 = 10;
int DigitalOutputPin2 = 11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PWMOutputPin, OUTPUT);
  pinMode(DigitalOutputPin1, OUTPUT);
  pinMode(DigitalOutputPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(PWMOutputPin, 50);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  delay(1000);  
}
