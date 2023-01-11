/*
Used for communication between the Matrix310 and a computer or other devices. 
Matrix310 can use SERIAL1 PINS or SERIAL2 PINS to achieve RS232 communication.
Our example use RS232 with null modem to simulate the multi device communication.
*/
#include "rs232.h"
extern char summary[7][32];
void testRS232() {
  // char writeMsg[] = "Message\0";
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
  if (Serial1.available() > 0) {
    //Read data from Serial1 and save to buffer.
    readStr = Serial1.readString();
    Serial1.flush();
    readLen = readStr.length();
    Serial.printf("data receive: %i\n", readLen);
    Serial.printf("read: %s\n", readStr);
  } else {
    Serial.println("read nothing!");
  }

  if (readLen > 0) {
    //Print the data from buffer.
    Serial.println(readStr);
    if(writeMsg.compareTo(readStr)==0){
      Serial.println("RS232 test is OK");
      summary[RS232][1] = '0';
    }
  }
}