#include <Arduino.h>

#define LED 2 
void setup() {
  Serial.begin(115200);
  delay(1000);// glitch avoid garna lai .. boot garesi serial moniter ma print nahune problem dher hunxa  
  pinMode(LED, OUTPUT);
  Serial.println("Type 'ON' to light up the blue LED.");
  Serial.println("Type 'OFF' to turn it off.");
}

void loop() {
  if (Serial.available() > 0) {// is there any unread test waiting on and off 
    String incomingText = Serial.readStringUntil('\n');
    incomingText.trim(); 
    Serial.print("ESP32 Received: ");
    Serial.println(incomingText);
    if (incomingText == "ON" || incomingText == "on") {
      digitalWrite(LED, HIGH);
      Serial.println(">> Success: Turning Blue LED ON!");
    } 
    else if (incomingText == "OFF" || incomingText == "off") {
      digitalWrite(LED, LOW);
      Serial.println(">> Success: Turning Blue LED OFF!");
    } 
    else {
      Serial.println(">> Error: Unknown command. Try typing 'ON' or 'OFF'.");
    }
  }
}