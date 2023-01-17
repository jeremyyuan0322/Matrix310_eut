#ifndef DIO_H
#define DIO_H

#ifdef __cplusplus//_cplusplus
#include "eut.h"
#include "Artila-Matrix310.h"

extern "C" {
#endif
extern void testDio();
extern void setDO(int status);
extern void readDI();
#ifdef __cplusplus
}
#endif//_cplusplus
#endif
