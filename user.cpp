// user.cpp
#include "user.h"

void test123() {
    Serial.println("test!");
}

void heartbeat(){
  static bool state = 0;
  if(state == 0) state = 1;
  else state = 0;
  Serial.println("debug!");
  digitalWrite(Debug_LED, state);
}
