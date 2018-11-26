int PWMOutputPin1 = 5; //only some pins on the Arduino can be used for PWM
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
  analogWrite(PWMOutputPin1, 50);
  digitalWrite(A2, LOW);
  digitalWrite(A3, HIGH);
  analogWrite(PWMOutputPin2, 50);
  digitalWrite(A4, LOW);
  digitalWrite(A5, HIGH);
  delay(1000);  
}
