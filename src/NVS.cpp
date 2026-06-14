#include <Arduino.h>
#include <Preferences.h>
Preferences prefs;
void setup() {
  Serial.begin(115200);
  prefs.begin("myapp", false);
  int count = prefs.getInt("bootcount", 0);
  count++;
  prefs.putInt("bootcount", count);
  Serial.print("Boot count: ");
  Serial.println(count);
  prefs.end();
}
void loop() {}