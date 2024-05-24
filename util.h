// util.h
#ifndef UTIL_H
#define UTIL_H

#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h> 
#include <WebSocketsClient.h>

class Job {
private:
    unsigned long lastExecutionTime;
    unsigned long interval;

public:
    Job(unsigned long interval);
    bool checkAndExecute(void (*executed)());
};
extern WebSocketsClient webSocket;

void Internet_inti();
void GetRequest();
void checkWiFiStatus();
void webSocketEvent(WStype_t type, const uint8_t * payload, size_t length);
#endif
