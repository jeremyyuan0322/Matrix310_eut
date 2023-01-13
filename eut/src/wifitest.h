#ifndef WIFITEST_H
#define WIFITEST_H

#ifdef __cplusplus//_cplusplus
#include <WiFi.h>
#include "eut.h"
#include "Artila-Matrix310.h"

extern "C" {
#endif
extern void testWifi();
extern void wifiServerConnect();
extern void testWifiFail();
#ifdef __cplusplus
}
#endif//_cplusplus
#endif
