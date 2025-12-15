#ifndef ACTUATOR_CONTROL_H
#define ACTUATOR_CONTROL_H

int PUMP_PIN  = 4;
int VALVE_PIN = 32;

void initActuator() {
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(VALVE_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW);
  digitalWrite(VALVE_PIN, LOW);
}

void startPump() {
  digitalWrite(PUMP_PIN, HIGH);
}

void stopPump() {
  digitalWrite(PUMP_PIN, LOW);
}

void openValve() {
  digitalWrite(VALVE_PIN, HIGH);
}

void closeValve() {
  digitalWrite(VALVE_PIN, LOW);
}

#endif

