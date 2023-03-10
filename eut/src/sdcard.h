#ifndef SDCARD_H
#define SDCARD_H

#ifdef __cplusplus//_cplusplus
#include <SD.h>
#include <string.h>
#include "eut.h"
#include "Artila-Matrix310.h"
extern "C" {
#endif
extern void testSD();
extern void readFile(fs::FS &fs, const char * path);
extern void writeFile(fs::FS &fs, const char * path, const char * message);
extern void deleteFile(fs::FS &fs, const char * path);
extern void testSDFail();
#ifdef __cplusplus
}
#endif//_cplusplus
#endif
