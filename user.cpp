// user.cpp
#include "user.h"

long temp123;


void test123() {
  Serial.println("test!");
  temp123++;
}

void heartbeat(){
  static bool state = 0;
  if(state == 0) state = 1;
  else state = 0;
  Serial.print(temp123);
  Serial.println(" debug!");
  digitalWrite(Debug_LED, state);
}
