
//
// A simple server implementation showing how to:
//  * serve static messages
//  * read GET and POST parameters
//  * handle missing pages / 404s
//

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "FtpUtilities.h"
#include "HtmServerUtilities.h"

#include "SDCard.h"

#define PrintSerial true

AsyncWebServer server(80);

// Set these to your desired credentials.
const char *ssid = "NETGEAR35";
const char *password = "freshsheep727";

FtpServer ftpSrv;   //set #define FTP_DEBUG in ESP8266FtpServer.h to see ftp verbose on serial

void notFound(AsyncWebServerRequest *request) {
    request->send(404, "text/plain", "Not found");
}

void setup() {
    Serial.begin(115200);
    setupDIO();
    initWiFi();
    initSDCard();

    ftpSrv.setCallback(_callback);
    ftpSrv.setTransferCallback(_transferCallback);
    ftpSrv.begin("mike","esp32s");    //username, password for ftp.   (default 21, 50009 for PASV)
    
    server.serveStatic("/", SD, "/");
 
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(SD, "/index.html", "text/html");
    });

    server.on("/ajax", HTTP_POST, [](AsyncWebServerRequest *request){
        String message;
        if (request->hasParam("DIO", true) && request->hasParam("callback", true)) {
            message = handleDigIO(request->getParam("DIO", true)->value(), request->getParam("callback", true)->value());
        }  else if (request->hasParam("ReadDIO", true) && request->hasParam("callback", true)) {
            message = ReadDigIO(request->getParam("ReadDIO", true)->value(), request->getParam("callback", true)->value());
        }else if (request->hasParam("ADC", true) && request->hasParam("callback", true)) {
            message = handleADC(request->getParam("ADC", true)->value(), request->getParam("callback", true)->value());
        }
        else {
            message = "Error 'Server.on(/ajax)'";
        }
        request->send(200, "text/plain", message);
    });

    server.onNotFound(notFound);
    server.begin();
}

void loop() {
  ftpSrv.handleFTP();
}
