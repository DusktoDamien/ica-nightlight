// light_sensor.ino - reads the photoresistor on LIGHT_SENSOR_PIN
// Returns 0 (dark) up to 1023 (bright).

int readLight() {
  // TODO Task 1 (Developer A): average SENSOR_SAMPLES readings.
  int sum = 0;
  for (int i = 0; i < SENSOR_SAMPLES; i++) {
    sum += analogRead(LIGHT_SENSOR_PIN);
    delay(10); // small delay between readings
  }
  return sum / SENSOR_SAMPLES;
}


// TODO Task 8 (Project Manager): add lightLabel() below this line.
const char* lightLabel(int light) {
  if (light < DARK_THRESHOLD) {
    return "dark";
  }
  return "bright";
}