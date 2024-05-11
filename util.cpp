// util.cpp
#include "util.h"

Job::Job(unsigned long interval)
  : interval(interval), lastExecutionTime(0) {}

bool Job::checkAndExecute(void (*executed)()) {
  unsigned long currentMillis = millis();
  if (currentMillis - lastExecutionTime >= interval) {
    executed();
    lastExecutionTime = currentMillis;
    return true;
  }
  return false;
}


void wifi_inti(const char* ssid, const char* password) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
}

void GetRequest(){
  static int OutputTemp;
  HTTPClient http;
  WiFiClient client;
  http.begin(client, "http://49.213.238.75:8000/app/");
  http.setTimeout(500); 
  http.addHeader("Content-Type", "application/json");
  int httpCode = http.GET();
  if (httpCode > 0)
  {
    String payload = http.getString();
    DynamicJsonDocument doc(256);
    DeserializationError error = deserializeJson(doc, payload);
    if (error){
      Serial.print("JSON解析失败: ");
      Serial.println(error.c_str());
      return;
    }
    OutputTemp = doc["is_clicked"];
    Serial.print("OutputTemp: ");
    Serial.println(OutputTemp);
  }
  else{
    String temp = http.errorToString(httpCode).c_str();
    Serial.println("HTTP GET request failed. Error: " + temp);
  }
  http.end();
}
