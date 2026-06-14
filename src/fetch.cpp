#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
const char* ssid = "Shuva_2.4G";
const char* password = "Taanshuva@1409";
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  HTTPClient http;
  http.begin("http://jsonplaceholder.typicode.com/todos/1");
  int code = http.GET();
  Serial.println(http.getString());
  http.end();
}
void loop() {}