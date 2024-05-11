// main.ino
#include "util.h"
#include "user.h"

// 創建任務
Job job01(1000);
Job job02(500);
Job job03(300);

void setup() {
  Serial.begin(115200); 
  wifi_inti("star","26931886");
  pinMode(Debug_LED, OUTPUT);  
  Serial.println("init!");
}

void loop() {
  job01.checkAndExecute(test123);
  job02.checkAndExecute(heartbeat);
  job03.checkAndExecute(GetRequest);
}
