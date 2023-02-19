/*
// char* input;
// size_t inputLength; (optional)
// string input size for 20 items is around 1536 bytes, 15 items is 768 bytes

#include <ArduinoJson.h>

StaticJsonDocument<768> doc;

DeserializationError error = deserializeJson(doc, input, inputLength);

if (error) {
  Serial.print(F("deserializeJson() failed: "));
  Serial.println(error.f_str());
  return;
}

const char* type = doc["type"]; // "12345678"

for (JsonObject list_item : doc["list"].as<JsonArray>()) {

  const char* list_item_pin = list_item["pin"]; // "12", "12", "12", "12", "12", "12", "12", "12", "12", ...
  const char* list_item_state = list_item["state"]; // "123456", "123456", "123456", "123456", "123456", ...

}


StaticJsonDocument<1024> doc;

doc["type"] = "12345678";

JsonArray list = doc.createNestedArray("list");

JsonObject list_0 = list.createNestedObject();
list_0["pin"] = "12";
list_0["state"] = "123456";

JsonObject list_1 = list.createNestedObject();
list_1["pin"] = "12";
list_1["state"] = "123456";

JsonObject list_2 = list.createNestedObject();
list_2["pin"] = "12";
list_2["state"] = "123456";

JsonObject list_3 = list.createNestedObject();
list_3["pin"] = "12";
list_3["state"] = "123456";

JsonObject list_4 = list.createNestedObject();
list_4["pin"] = "12";
list_4["state"] = "123456";

JsonObject list_5 = list.createNestedObject();
list_5["pin"] = "12";
list_5["state"] = "123456";

JsonObject list_6 = list.createNestedObject();
list_6["pin"] = "12";
list_6["state"] = "123456";

JsonObject list_7 = list.createNestedObject();
list_7["pin"] = "12";
list_7["state"] = "123456";

JsonObject list_8 = list.createNestedObject();
list_8["pin"] = "12";
list_8["state"] = "123456";

JsonObject list_9 = list.createNestedObject();
list_9["pin"] = "12";
list_9["state"] = "123456";

JsonObject list_10 = list.createNestedObject();
list_10["pin"] = "12";
list_10["state"] = "123456";

JsonObject list_11 = list.createNestedObject();
list_11["pin"] = "12";
list_11["state"] = "123456";

JsonObject list_12 = list.createNestedObject();
list_12["pin"] = "12";
list_12["state"] = "123456";

JsonObject list_13 = list.createNestedObject();
list_13["pin"] = "12";
list_13["state"] = "123456";

JsonObject list_14 = list.createNestedObject();
list_14["pin"] = "12";
list_14["state"] = "123456";

serializeJson(doc, output);


*/