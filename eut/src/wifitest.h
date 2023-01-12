#ifndef WIFITEST_H
#define WIFITEST_H

#ifdef __cplusplus//_cplusplus
#include <WiFi.h>
#include <ESP32Ping.h>
#include "eut.h"
#include "Artila-Matrix310.h"

extern "C" {
#endif
extern void testWifi();
#ifdef __cplusplus
}
#endif//_cplusplus
#endif
