#ifndef BUZZER_AUDIO_H
#define BUZZER_AUDIO_H

int BUZZER_PIN = 18;

void initBuzzer() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void beepOK() {
  tone(BUZZER_PIN, 2000, 150);
}

void beepError() {
  tone(BUZZER_PIN, 1000, 500);
}

#endif

