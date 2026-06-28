#include <Arduino.h>

#define LED_PIN 2
#define PWM_CHANNEL 0
#define PWM_FREQUENCY 5000
#define PWM_RESOLUTION 8

void setup() {
  ledcSetup(PWM_CHANNEL, PWM_FREQUENCY, PWM_RESOLUTION); // channel 0, 5kHz, 8-bit
  ledcAttachPin(LED_PIN, PWM_CHANNEL);   // GPIO2 = built-in LED
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    ledcWrite(PWM_CHANNEL, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    ledcWrite(PWM_CHANNEL, i);
    delay(10);
  }
}
