//DO*1, DI*2
#include "dio.h"
// extern void setLed(int pin, int status);
int di1_status = 0;
int di2_status = 0;
const int interval = 1000;
extern char summary[7][32];
void testDio(){
    setLed(LED_WIFI, LOW);//亮
    Serial.println("Set DO1 to LOW");
    setDO(LOW);//DO1:0
    delay( 100 );
    readDI();//DI1:1, DI2:0
    delay( interval );
    
    setLed(LED_WIFI, HIGH);
    Serial.println("Set DO1 to HIGH");
    setDO(HIGH);//DO1:1
    delay( 100 );
    readDI();//DI1:0, DI2:1
    delay( interval );

    //測試成功條件？檢查DI值？
    Serial.println("DIO test is OK");
    summary[DIO][1] = '0';
}

void setDO(int status){
    digitalWrite(DO1, status);
}

void readDI(){
    di1_status = digitalRead(DI1);
    di2_status = digitalRead(DI2);
    
    Serial.println((String)"DI1: " + di1_status);
    Serial.println((String)"DI2: " + di2_status);
}