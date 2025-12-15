#ifndef SENSOR_BP_H
#define SENSOR_BP_H

int sensorPin = 26;

int readPressure() {
  int raw = analogRead(sensorPin);
  float voltage = raw * 50.0 / 4095.0;
  int pressure = voltage / 12;
  return pressure;
}

#endif
