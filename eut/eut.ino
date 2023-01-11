/*
 *   (C) Artila Electronics Co., Ltd. All Rights Reserved.
 *       Date: 2023.01.09
 */
#include "src/Artila-Matrix310.h"
#include "src/eut.h"
#include "src/switch.h"

// typedef enum {
//   RS232,
//   RS485,
//   DIO,
//   SW,
//   ALL
// } COMPONENT;

// const char * const COMPONENT_STR[] =
// {
//     [RS232] = "RS-232",
//     [RS485] = "RS-485",
//     [DIO]  = "DIO",
//     [SW]  = "RotateSW"
// };

char summary[7][32];
const char* helpMsg =
    "List of commands:\n"
    "  a) test all\n"
    "  b) DIO test\n"
    "  c) RS232 test\n"
    "  d) RS485 test\n"
    "  e) WIFI test\n"
    "  f) ETHERNET help\n"
    "  g) SD Card test\n"
    "  h) Switch test\n"
    "  r) restart\n";//matrix310重啟
//show all command
void printHelp() {
    Serial.printf("%s", helpMsg);
}

//show test result
void printResult() {
    Serial.println("===== Test Summary =====");
    for(int i=0; i<ALL; i++) {
        Serial.printf("%s: %s\n", COMPONENT_STR[i], summary[i]);
    }
}

// int readSwitch(){
//     int total=0;
//     if (digitalRead(SW_1) == LOW) { total+=1; }
//     if (digitalRead(SW_2) == LOW) { total+=2; }
//     if (digitalRead(SW_4) == LOW) { total+=4; }
//     return total;
// }

// //test rotary switch
// void testRotarySW() {
//     int bulleye = random(0, 7);
//     Serial.printf("Please change rotary switch to %d\n", bulleye);
    
//     while ( readSwitch() != bulleye ) ;
//     Serial.println("Please rotary switch test OK");
//     summary[SW][1] = '0';
// }

//initial summary array
void init_summary() {
    for(int i=0; i<ALL; i++) {
        strcpy(summary[i], "0");
    }
}

void setup() {
    initGPIO();
    Serial.begin(115200);
    while(!Serial);
    
    init_summary();
    randomSeed(millis());
    
    Serial.println("___Hello ARTILA___");
    Serial.printf("%s v%s\n", _NAME, _VERSION);

    setReadyLed(HIGH);

    //測試項目全部輸出0: 代表還沒開始測試
    printResult();
    printHelp();
    
}

String strCMD;
void loop() {
    if (Serial.available())
    {
        strCMD = Serial.readString();
        Serial.println("<<< " + strCMD);
        
        switch(strCMD[0]) {
        case 'a':
            Serial.println("Test all");
            break;
        case 'b':
            Serial.println("RS-232 Test");
            break;
        case 'c':
            Serial.println("RS-485 Test");
            break;
        case 'h':
            printHelp();
            break;
        case 's':
            summary[SW][0] = '1';
            testRotarySW();
            printResult();
            break;
        default:
            Serial.printf("Command %c is not found!!\n", strCMD[0]);
            break;
        }
        
    }
}

//serial in
char getChar() {
    while(Serial.available() == 0);
    return((char)Serial.read());
}
