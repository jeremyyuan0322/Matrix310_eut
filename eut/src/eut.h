#ifndef EUT_H
#define EUT_H
// #include "Artila-Matrix310.h"
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
  ALL,
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

    //7個：0-6
    

    //b)DIO~0
    //c)232~1
    //d)485~2
    //e)wifi~3
    //f)eht~4
    //g)sdcard~5
    //i)switch~6

    //h)help
    //a)ALL
    //r)restart

    //ready led程式run就會亮
    //wifi led wifi連上要亮