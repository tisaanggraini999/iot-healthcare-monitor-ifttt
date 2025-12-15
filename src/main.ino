#include <Arduino.h>
#include "wifi_config.h"
#include "ifttt_client.h"
#include "sensor_bp.h"

int systolic;
int diastolic;

void setup() {
  Serial.begin(115200);
  connectWiFi();
}

void loop() {
  systolic = readPressure();
  diastolic = systolic * 2 / 3;

  Serial.print("SYS: ");
  Serial.print(systolic);
  Serial.print(" DIA: ");
  Serial.println(diastolic);

  if (systolic > 50 && systolic < 250) {
    sendToIFTTT(systolic, diastolic, 0);
  }

  delay(15000); // avoid spam
}
