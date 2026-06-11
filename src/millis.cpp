#include <Arduino.h>
unsigned long previousMillis = 0;
const long interval = 1000;
bool ledState = false;

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(2, ledState);
    Serial.println(ledState ? "LED ON" : "LED OFF");
  }

}