#include "HardwareSerial.h"
#include "esp32-hal-gpio.h"
//DO*1, DI*2
//HIGH: 1, LOW: 0
#include "dio.h"
int di1_status = 0;
int di2_status = 0;
const int interval = 1000;
extern char summary[7][32];
bool stage1 = false;
bool stage2 = false;
void testDio() {
  Serial.printf("DO1: %i\n", digitalRead(DO1));
  if (digitalRead(DO1) == HIGH) {
    setLed(LED_WIFI, LOW);  //亮
    Serial.println("Set DO1 to LOW");
    setDO(LOW);
    delay(100);
    readDI();
    delay(interval);
    if (di1_status == HIGH && di2_status == LOW) {
      stage1 = true;
    }
  } 
  else {
    setLed(LED_WIFI, HIGH);
    Serial.println("Set DO1 to HIGH");
    setDO(HIGH);
    delay(100);
    readDI();
    delay(interval);
    if (di1_status == LOW && di2_status == HIGH) {
      stage2 = true;
    }
  }
  //測試成功條件: 檢查DI值
  if (stage1 == true || stage2 == true) {
    Serial.println("DIO test is OK");
    summary[DIO][1] = '0';
  } 
  else {
    Serial.println("DIO test is failed");
    summary[DIO][1] = '1';
  }
}

void setDO(int status) {
  digitalWrite(DO1, status);
}


void readDI() {
  di1_status = digitalRead(DI1);
  di2_status = digitalRead(DI2);

  Serial.println((String) "DI1: " + di1_status);
  Serial.println((String) "DI2: " + di2_status);
}