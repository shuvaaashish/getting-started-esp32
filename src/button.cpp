#include <Arduino.h>

#define BUTTON_PIN 4
#define LED_PIN 2

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  int state = digitalRead(BUTTON_PIN);
  
  if (state == LOW) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Button pressed");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Button released");
  }
  
  delay(100);
}