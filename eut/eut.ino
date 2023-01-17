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
#include "src/rs485.h"
#include "src/wifitest.h"
#include "src/eth.h"


char summary[7][32];
const char* helpMsg =
  "List of commands:\n"
  "  a) Test all\n"
  "  b) DIO test\n"
  "  c) RS232 test\n"
  "  d) RS485 test\n"
  "  e) Wifi test\n"
  "  f) Ethernet test\n"
  "  g) SDcard test\n"//write and read
  "  i) Switch test\n"
  "  h) Command list\n"
  "  r) Restart\n";  //matrix310 restart
//show all command
void printHelp() {
  Serial.printf("%s", helpMsg);
}

//show test result
void printResult() {
  Serial.println("===== Test Summary =====");
  for (int i = 0; i < ALL; i++) {
  if (summary[i][0]== '1' && summary[i][1] == '0') {
    Serial.printf("%s: %s\n", COMPONENT_STR[i], "OK");
  }
  else if(summary[i][0]== '1' && summary[i][1] == '1'){
    Serial.printf("%s: %s\n", COMPONENT_STR[i], "FAIL");
  }
  }
}

void reboot(){
  delay(1000);
  ESP.restart();
}

void testAll(){
  Serial.println("DIO Test");
  summary[DIO][0] = '1';
  testDio();
  Serial.println("-------------------------");
  Serial.println("RS232 Test");
  summary[RS232][0] = '1';
  testRS232();
  Serial.println("-------------------------");
  Serial.println("RS485 Test");
  summary[RS485][0] = '1';
  testRS485();
  Serial.println("-------------------------");
  Serial.println("Wifi Test");
  summary[WIFI][0] = '1';
  testWifi();
  Serial.println("-------------------------");
  Serial.println("Ethernet Test");
  summary[ETH][0] = '1';
  testEth();
  Serial.println("-------------------------");
  Serial.println("SDcard Test");
  summary[SDCARD][0] = '1';
  testSD();
  Serial.println("-------------------------");
  Serial.println("Switch Test");
  summary[SW][0] = '1';
  testRotarySW();
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
  WizReset();
  Serial.begin(115200);
  while (!Serial)
    ;

  init_summary();
  randomSeed(millis());

  Serial.println("___Hello ARTILA___");
  Serial.printf("%s v%s\n", _NAME, _VERSION);

  setReadyLed(HIGH);

  printHelp();
}

String strCMD;
void loop() {
  if (Serial.available()) {
    strCMD = Serial.readString();
    Serial.println("<<< " + strCMD);

    switch (strCMD[0]) {
      case 'a':
        Serial.println("Test all");
        testAll();
        printResult();
        break;
      case 'b':
        Serial.println("DIO Test");
        summary[DIO][0] = '1';
        testDio();
        printResult();
        printHelp();
        break;
      case 'c':
        Serial.println("RS-232 Test");
        summary[RS232][0] = '1';
        testRS232();
        printResult();
        printHelp();
        break;      
      case 'd':
        Serial.println("RS-485 Test");
        summary[RS485][0] = '1';
        testRS485();
        printResult();
        printHelp();
        break;
      case 'e':
        Serial.println("Wifi Test");
        summary[WIFI][0] = '1';
        testWifi();
        setWifiLed(LOW);
        printResult();
        printHelp();
        break;
      case 'f':
        Serial.println("Ethernet Test");
        summary[ETH][0] = '1';
        testEth();
        printResult();
        printHelp();
        break;
      case 'g':
        Serial.println("SDcard Test");
        summary[SDCARD][0] = '1';
        testSD();
        printResult();
        printHelp();
        break;
      case 'i':
        Serial.println("Switch Test");
        summary[SW][0] = '1';
        testRotarySW();
        printResult();
        printHelp();
        break;
      case 'h':
        printHelp();
        break;
      case 'r':
        Serial.println("Reboot");
        reboot();
        break;
      default:
        Serial.printf("Command %c is not found!!\n", strCMD[0]);
        break;
    }
  }
}
