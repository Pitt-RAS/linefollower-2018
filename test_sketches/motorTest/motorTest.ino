int PWMOutputPin1 = 9; //only some pins on the Arduino can be used for PWM
int PWMOutputPin2 = 11;

//AO-A5 only work
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PWMOutputPin1, OUTPUT);
  pinMode(PWMOutputPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(PWMOutputPin1, 150); 
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  analogWrite(PWMOutputPin2, 150);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(1000);  
}
