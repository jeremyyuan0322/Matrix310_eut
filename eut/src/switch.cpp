#include "esp32-hal.h"
#include <sys/_intsup.h>
#include <sys/_types.h>
#include "switch.h"
extern char summary[7][32];
int readSwitch(){
    int total=0;
    if (digitalRead(SW_1) == LOW) { total+=1; }
    if (digitalRead(SW_2) == LOW) { total+=2; }
    if (digitalRead(SW_4) == LOW) { total+=4; }
    return total;
}

//test rotary switch
void testRotarySW() {
    int bulleye = random(0, 7);
    unsigned int interval = 15000;
    unsigned long timeSW = 0;
    Serial.printf("Please change rotary switch to %d\n", bulleye);
    timeSW = millis();
    while (1) {
      if (readSwitch() == bulleye) {
        Serial.println("Rotary switch test is OK");
        summary[SW][1] = '0';
      }
      if(millis() - timeSW > interval)
      {
        Serial.println("Switch test is failed");
        summary[SW][1] = '1';
      }
    }
    // while ( readSwitch() != bulleye );
    // Serial.println("Rotary switch test is OK");
    // summary[SW][1] = '0';
}