// util.h
#ifndef UTIL_H
#define UTIL_H

#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h> 

extern String GET_URL;
extern String GET_BODY;
extern int GET_TIMEOUT;

class Job {
private:
    unsigned long lastExecutionTime;
    unsigned long interval;

public:
    Job(unsigned long interval);
    bool checkAndExecute(void (*executed)());
};

void wifi_inti(const char* ssid, const char* password);
void GetRequest();

#endif
