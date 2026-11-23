// logger.ino - prints status messages to the Serial Monitor (9600 baud)

// TODO Task 4 (Project Manager): add modeName() here.
const char* modeName(Mode mode) {
  switch (mode) {
    case MODE_OFF:
      return "OFF";
    case MODE_AUTO:
      return "AUTO";
    case MODE_ON:
      return "ON";
    default:
      return "UNKNOWN";
  }
}

void logStatus(int light) {
  static unsigned long lastLogMs = 0;
  unsigned long now = millis();

  if (now - lastLogMs >= LOG_INTERVAL_MS) {
    lastLogMs = now;
    Serial.print("mode=");
    Serial.print(modeName(currentMode));
    Serial.print(" light=");
    Serial.print(light);
    Serial.print(" ");
    Serial.print(lightLabel(light));
    Serial.print(" led=");
    Serial.println(ledBrightness);
  }
}
void logBanner(){
  Serial.println("NightLight is starting, Button cycles modes");
}