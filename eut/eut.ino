/*
 *   (C) Artila Electronics Co., Ltd. All Rights Reserved.
 *       Date: 2023.01.09
 */

//equipment under test
#include "src/Artila-Matrix310.h"
#include "src/eut.h"
#include "src/switch.h"
#include "src/rs232.h"
#include "src/dio.h"
#include "src/sdcard.h"


char summary[7][32];
const char* helpMsg =
  "List of commands:\n"
  "  a) Test all\n"
  "  b) DIO test\n"
  "  c) RS232 test\n"
  "  d) RS485 test\n"
  "  e) Wifi test\n"//use CRC
  "  f) Ethernet test\n"
  "  g) SDcard test\n"//write and read
  "  i) Switch test\n"
  "  h) Command list\n"
  "  r) Restart\n";  //matrix310重啟

//show all command
void printHelp() {
  Serial.printf("%s", helpMsg);
}

//show test result
void printResult() {
  Serial.println("===== Test Summary =====");
  for (int i = 0; i < ALL; i++) {
    Serial.printf("%s: %s\n", COMPONENT_STR[i], summary[i]);
  }
}

//initial summary array
void init_summary() {
  for (int i = 0; i < ALL; i++) {
    strcpy(summary[i], "0");
  }
}

void setup() {
  const char _NAME[] = "AOQTP";
  const char _VERSION[] = "0.1.0";
  initGPIO();
  Serial.begin(115200);
  while (!Serial)
    ;

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
  if (Serial.available()) {
    strCMD = Serial.readString();
    Serial.println("<<< " + strCMD);

    switch (strCMD[0]) {//且strCMD[2]==\n
      case 'a':
        Serial.println("Test all");
        break;
      case 'b':
        Serial.println("DIO Test");
        summary[DIO][0] = '1';
        testDio();
        printResult();
        break;
      case 'c':
        Serial.println("RS-232 Test");
        summary[RS232][0] = '1';
        testRS232();
        printResult();
        break;      
      case 'd':
        Serial.println("RS-485 Test");
        break;
      case 'e':
        Serial.println("Wifi Test");
        break;
      case 'f':
        Serial.println("Ethernet Test");
        break;
      case 'g':
        Serial.println("SDcard Test");
        summary[SDCARD][0] = '1';
        testSD();
        printResult();
        break;
      case 'i':
        summary[SW][0] = '1';
        testRotarySW();
        printResult();
        break;
      case 'h':
        printHelp();
        break;
      case 'r':
        Serial.println("Restart");
        break;
      default:
        Serial.printf("Command %c is not found!!\n", strCMD[0]);
        break;
    }
  }
}
