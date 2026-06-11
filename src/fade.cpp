#include <Arduino.h>

void setup() {
  ledcSetup(0, 5000, 8); // channel 0, 5kHz, 8-bit
  ledcAttachPin(2, 0);   // GPIO2 = built-in LED
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    ledcWrite(0, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    ledcWrite(0, i);
    delay(10);
  }
}