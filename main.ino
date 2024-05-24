// main.ino
#include "util.h"
#include "user.h"

// 創建任務
Job job01(1000);
Job job02(500);

// 創建 WebSocketClient 物件
WebSocketsClient webSocket;

void setup() {
  Serial.begin(115200); 
  Internet_inti();
  pinMode(Debug_LED, OUTPUT);  
  Serial.println("init!");
}

void loop() {
  job01.checkAndExecute(test123);
  job02.checkAndExecute(heartbeat);
  webSocket.loop();
}
