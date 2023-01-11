#ifndef EUT_H
#define EUT_H
// #include "Artila-Matrix310.h"
#ifdef __cplusplus
extern "C" {
#endif

const char _NAME[] = "AOQTP";
const char _VERSION[] = "0.1.0";
typedef enum {
  RS232,
  RS485,
  DIO,
  SW,
  ALL
} COMPONENT;

const char * const COMPONENT_STR[] =
{
    [RS232] = "RS-232",
    [RS485] = "RS-485",
    [DIO]  = "DIO",
    [SW]  = "RotateSW"
};

//char summary[7][32];
//extern comp;//卡在這

// extern const char * const COMPONENT_STR[];

// extern char summary[7][32];

// const char* helpMsg =
//     "List of commands:\n"
//     "  a) test all\n"
//     "  b) DIO test\n"
//     "  c) RS232 test\n"
//     "  d) RS485 test\n"
//     "  e) WIFI test\n"
//     "  f) ETHERNET help\n"
//     "  g) SD Card test\n"
//     "  h) Switch test\n"
//     "  r) restart\n";//matrix310重啟

#ifdef __cplusplus
}
#endif
#endif

// const char _NAME[] = "AOQTP";
// const char _VERSION[] = "0.1.0";

// typedef enum {
//   RS232,
//   RS485,
//   DIO,
//   SW,
//   ALL
// } COMPONENT;

// const char * const COMPONENT_STR[] =
// {
//     [RS232] = "RS-232",
//     [RS485] = "RS-485",
//     [DIO]  = "DIO",
//     [SW]  = "RotateSW"
// };

// char summary[7][32];

// const char* helpMsg =
//     "List of commands:\n"
//     "  a) test all\n"
//     "  b) DIO test\n"
//     "  c) RS232 test\n"
//     "  d) RS485 test\n"
//     "  e) WIFI test\n"
//     "  f) ETHERNET help\n"
//     "  g) SD Card test\n"
//     "  h) Switch test\n"
//     "  r) restart\n";//matrix310重啟
// #endif // __LIBTEST_H2__

    //7個：0-6

    //b)DIO~0
    //c)232~1
    //d)485~2
    //e)wifi~3
    //f)eht~4
    //g)sdcard~5
    //h)switch~6
    //r)restart
    

    //ready led程式run就會亮
    //wifi led wifi連上要亮