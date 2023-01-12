/*
Used for communication between the Matrix-310 and a computer or other devices. 
Matrix310 uses SERIAL2 PINS to achieve RS485 communication.
*/
#include "rs485.h"
extern char summary[7][32];
void testRS485() {
  String writeMsg = "Message";
  String readStr = "";
  int readLen = 0;

  //Setup Serial2 PINS with the specified baud rates that is depends on the device you connect.
  Serial2.begin(115200);
  Serial2.setTimeout(100);
  //Configures the COM1_RTS pin to behave as an output.
  pinMode(COM1_RTS, OUTPUT);
  //Write a HIGH value to COM1_RTS pin before the Matrix-310 uses the Serial2 PINS to send/write data.
  //Write a LOW value to COM1_RTS pin before the Matrix-310 uses the Serial2 PINS to receive/read data.
  digitalWrite(COM1_RTS, HIGH);
  delay(1);
  Serial.println("RS485 already setup.");
  if (Serial2.availableForWrite()) {
    int writeLen = Serial2.print(writeMsg);
    Serial2.flush();
    delay(10);
    Serial.print("data send: ");
    Serial.println(writeLen);
  }
  digitalWrite(COM1_RTS, LOW);  // read
  delay(1);
  unsigned long Time485;
  Time485 = millis();
  while (1) {
    if (Serial2.available()) {
      readStr = Serial2.readString();
      Serial2.flush();
      delay(10);
      readStr.trim();
      readLen = readStr.length();
      Serial.printf("data receive: %i\n", readLen);
      Serial.printf("read: %s\n", readStr);
      break;
    }
    if (millis() - Time485 > 5000) {
      Serial.println("read nothing!");
      break;
    }
  }
  if (readLen > 0) {
    if (writeMsg.compareTo(readStr) == 0) {
      Serial.println("RS485 test is OK");
      summary[RS485][1] = '0';
    } else {
      Serial.println("RS485 test is failed");
      summary[RS485][1] = '1';
    }
  } else {
    Serial.println("RS485 test is failed");
    summary[RS485][1] = '1';
  }
  
}
