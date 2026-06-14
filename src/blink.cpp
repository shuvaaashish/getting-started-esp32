#include <Arduino.h>

#define LED 2

void setup(){
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

}

void loop(){
  digitalWrite(LED,HIGH);
  Serial.println("ON");
  delay(1000);
  
  digitalWrite(LED,LOW);
  Serial.println("OFF");
  delay(1000);
}