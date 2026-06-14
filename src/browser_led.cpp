#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YourWiFi";
const char* password = "YourPass";
WebServer server(80);
bool ledState = false;
void handleRoot() {
  String html = "<h1>ESP32 Control</h1>";
  html += "<a href='/on'><button>ON</button></a>";
  html += "<a href='/off'><button>OFF</button></a>";
  server.send(200, "text/html", html);
}
void handleOn() {
  digitalWrite(2, HIGH);
  ledState = true;
  server.sendHeader("Location", "/");
  server.send(303);
}
void handleOff() {
  digitalWrite(2, LOW);
  ledState = false;
  server.sendHeader("Location", "/");
  server.send(303);
}
void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
}
void loop() {
  server.handleClient();
}