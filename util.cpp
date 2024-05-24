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

void checkWiFiStatus() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi 未連接");
    Internet_inti();
  }else Serial.println("Wi-Fi 已連接");
}

void Internet_inti() {
  const char* wifi_ssid = "RU_A15";
  const char* wifi_password ="qaz654321";
  const char* websocket_server_host = "49.213.238.75";
  const uint16_t websocket_server_port = 5000;
  const char* websocket_server_path = "/ws/chat/test/";
  WiFi.mode(WIFI_STA);
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  // 設定 WebSocket
  webSocket.begin(websocket_server_host, websocket_server_port, "/");
  webSocket.onEvent(webSocketEvent);
  webSocket.setReconnectInterval(3000);
}
void webSocketEvent(WStype_t type, const uint8_t * payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[WSc] Disconnected!\n");
            break;
        case WStype_CONNECTED:
            Serial.printf("[WSc] Connected to url: %s\n", payload);
            // 發送訊息到 WebSocket 伺服器
            {
                String message = "Hello from ESP8266";
                webSocket.sendTXT(message);
            }
            break;
        case WStype_TEXT: {
            String textPayload = String((char *)payload);
            Serial.printf("[WSc] get text: %s\n", textPayload.c_str());
            // 回傳收到的訊息
            {
                String response = "Received: " + textPayload;
                webSocket.sendTXT(response);
            }
            break;
        }
        case WStype_BIN:
            Serial.printf("[WSc] get binary length: %u\n", length);
            hexdump(payload, length);
            break;
        case WStype_ERROR:
            Serial.printf("[WSc] Error!\n");
            break;
    }
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
