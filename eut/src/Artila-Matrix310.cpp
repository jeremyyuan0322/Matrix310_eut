/*
 *   (C) Artila Electronics Co., Ltd. All Rights Reserved.
 *       Date: 2022.10.17
 */
#include "Artila-Matrix310.h"
extern void setLed(int pin, int status);
void setReadyLed(int state){
    if(state) {
        // LED ON
        setLed(LED_READY, HIGH);
    }
    else {
        // LED OFF
        setLed(LED_READY, LOW);
    }
}

void setWifiLed(int state){
    if(state) {
        // LED ON
        setLed(LED_WIFI, HIGH);
    }
    else {
        // LED OFF
        setLed(LED_WIFI, LOW);
    }
}

void setLed(int pin, int status){
    digitalWrite(pin, status);
}

//initial ethernet(w5500)
void WizReset() {
    Serial.print("Resetting Wiz W5500 Ethernet Board...  ");
    pinMode(LAN_RST, OUTPUT);
    digitalWrite(LAN_RST, HIGH);
    delay(250);
    digitalWrite(LAN_RST, LOW);
    delay(50);
    digitalWrite(LAN_RST, HIGH);
    delay(350);
    Serial.println("Done.");
}

void initGPIO()
{
    pinMode(DO1, OUTPUT);
    pinMode(DI1, INPUT);
    pinMode(DI2, INPUT);
    pinMode(SD_CS, OUTPUT);
    pinMode(COM1_RTS, OUTPUT);
    pinMode(LED_WIFI, OUTPUT);
    pinMode(LED_READY, OUTPUT);
    
    pinMode(SW_1, INPUT);
    pinMode(SW_2, INPUT);
    pinMode(SW_4, INPUT);
    // make sure LED OFF, if possible
    // setReadyLed(0);
    // digitalWrite(LED_WIFI, LOW);
}