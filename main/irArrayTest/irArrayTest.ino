#include "config.h"
int pins[] = {IR1_PIN,IR3_PIN,IR5_PIN,IR7_PIN,IR9_PIN};
irArray test = new irArray(pins,PITCH);




void setup() {
  Serial.begin(9600);
  Serial.print(PITCH);
}
void loop() {
  

}
