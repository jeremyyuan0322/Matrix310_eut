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
    Serial.printf("Please change rotary switch to %d\n", bulleye);
    
    while ( readSwitch() != bulleye ) ;
    Serial.println("Please rotary switch test OK");
    summary[SW][1] = '0';
}