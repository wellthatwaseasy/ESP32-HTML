#ifndef HTMSERVERUTILITIES
#define HTMSERVERUTILITIES

#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "digital.h"
#include "analogread.h"
#include "pwm.h"
#include "sensor.h"

#define PrintSerial true

void initWiFi();
void initSDCard();
String handleDigIO(String str, String CBF);
String ReadDigIO(String str, String CBF);
void setupDIO();
String handleADC(String str, String CBF);

#endif