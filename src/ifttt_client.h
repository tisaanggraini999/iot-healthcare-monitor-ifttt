#ifndef IFTTT_CLIENT_H
#define IFTTT_CLIENT_H

#include <HTTPClient.h>

String IFTTT_SERVER = "http://maker.ifttt.com";
String EVENT_NAME   = "Data_Tensi";
String IFTTT_KEY    = "YOUR_IFTTT_KEY";

void sendToIFTTT(int sys, int dia, int pulse) {
  String url = IFTTT_SERVER + "/trigger/" + EVENT_NAME +
               "/with/key/" + IFTTT_KEY +
               "?value1=" + String(sys) +
               "&value2=" + String(dia) +
               "&value3=" + String(pulse);

  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET();
  http.end();

  Serial.println("IFTTT Response: " + String(httpCode));
}

#endif