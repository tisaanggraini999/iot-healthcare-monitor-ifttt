#ifndef IFTTT_CLIENT_H
#define IFTTT_CLIENT_H

#include <HTTPClient.h>

// === IFTTT CONFIG (FROM ORIGINAL CODE) ===
String IFTTT_EVENT = "Data Tensi";
String IFTTT_KEY   = "bH74A7SPEKI4f8SoLgnQS7J15s9egoQBKUxY0UhD4S";

void sendToIFTTT(int systolic, int diastolic) {

  String url = "https://maker.ifttt.com/trigger/" + IFTTT_EVENT +
               "/with/key/" + IFTTT_KEY +
               "?value1=" + String(systolic) +
               "&value2=" + String(diastolic);

  Serial.println("[IFTTT] URL:");
  Serial.println(url);

  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET();

  if (httpCode > 0) {
    Serial.print("[IFTTT] HTTP Code: ");
    Serial.println(httpCode);
  } else {
    Serial.println("[IFTTT] Connection failed");
  }

  http.end();
}

#endif
