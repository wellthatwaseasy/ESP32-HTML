
#include <WiFi.h>

extern const char *ssid;
extern const char *password;

void initWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(1000);
    }
    Serial.print("Web Server located @");
    Serial.println(WiFi.localIP());
}
