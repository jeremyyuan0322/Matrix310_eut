#include "rs232.h"

extern char summary[7][32];
void testRS232() {
  String writeMsg = "Message";
  String readStr = "";
  char buf[64];
  int readLen = 0;
  int writeLen = 0;
  Serial1.begin(9600, SERIAL_8N1, COM2_RX, COM2_TX);
  Serial1.setTimeout(100);
  Serial.println("RS232 already setup.");

  writeLen = Serial1.print(writeMsg);
  Serial1.flush();
  delay(10);
  Serial.printf("data send: %i\n", writeLen);
  Serial.printf("write: %s\n", writeMsg);

  unsigned long Time232;
  Time232 = millis();
  while (1) {
    if (Serial1.available()) {
      readStr = Serial1.readString();
      Serial1.flush();
      delay(10);
      readStr.trim();
      readLen = readStr.length();
      Serial.printf("data receive: %i\n", readLen);
      Serial.printf("read: %s\n", readStr);
      break;
    }
    if (millis() - Time232 > 5000) {
      Serial.println("read nothing!");
      break;
    }
  }
  if (readLen > 0) {
    if (writeMsg.compareTo(readStr) == 0) {
      Serial.println("RS232 test is OK");
      summary[RS232][1] = '0';
    } else {
      Serial.println("RS232 test is failed");
      summary[RS232][1] = '1';
    }
  } else {
    Serial.println("RS232 test is failed");
    summary[RS232][1] = '1';
  }
}