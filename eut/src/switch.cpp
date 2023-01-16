#include "esp32-hal.h"
#include <sys/_intsup.h>
#include <sys/_types.h>
#include "switch.h"
extern char summary[7][32];
int readSwitch() {
  int total = 0;
  if (digitalRead(SW_1) == LOW) { total += 1; }
  if (digitalRead(SW_2) == LOW) { total += 2; }
  if (digitalRead(SW_4) == LOW) { total += 4; }
  return total;
}

//test rotary switch
void testRotarySW() {
  if (readSwitch() == 0) {
    Serial.println("Rotary switch test is OK");
    summary[SW][1] = '0';
  } 
  else {
    Serial.println("Switch test is failed");
    summary[SW][1] = '1';
  }
}