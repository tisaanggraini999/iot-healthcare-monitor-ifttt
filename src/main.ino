#include "wifi_config.h"
#include "ifttt_client.h"
#include "sensor_bp.h"
#include "actuator_control.h"
#include "lcd_display.h"
#include "buzzer_audio.h"

int systolic;
int diastolic;

void setup() {
  Serial.begin(115200);

  connectWiFi();
  initActuator();
  initLCD();
  initBuzzer();
}

void loop() {
  openValve();
  delay(500);
  startPump();
  delay(3000);

  systolic = readPressure();
  stopPump();
  closeValve();

  diastolic = systolic * 2 / 3;

  if (systolic > 50 && systolic < 250) {
    showPressure(systolic, diastolic);
    sendToIFTTT(systolic, diastolic);
    beepOK();
  } else {
    beepError();
  }

  delay(15000);
}
