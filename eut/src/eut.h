#ifndef EUT_H
#define EUT_H
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {//0-7
  DIO,//b,0
  RS232,//c,1
  RS485,//d,2
  WIFI,//e,3
  ETH,//f,4
  SDCARD,//g,5
  SW,//i,6
  ALL,//a,7
} COMPONENT;

const char * const COMPONENT_STR[] =
{
  [DIO] = "DIO",
  [RS232] = "RS-232",
  [RS485] = "RS-485",
  [WIFI]  = "Wifi",
  [ETH] = "Ethernet",
  [SDCARD] = "SDcard",
  [SW]  = "RotateSW",
  [ALL] = "ALL"
};

#ifdef __cplusplus
}
#endif
#endif