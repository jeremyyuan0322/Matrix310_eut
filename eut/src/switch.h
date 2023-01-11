#ifndef SWITCH_H
#define SWITCH_H

#ifdef __cplusplus//_cplusplus
#include <Arduino.h>
#include "eut.h"
#include "Artila-Matrix310.h"
// extern char summary[7][32];

extern "C" {
#endif
extern int readSwitch();
extern void testRotarySW();
#ifdef __cplusplus
}
#endif//_cplusplus
#endif
