#ifndef ETH_H
#define ETH_H

#ifdef __cplusplus//_cplusplus
#include <Ethernet.h>
#include "eut.h"
#include "Artila-Matrix310.h"

extern "C" {
#endif
extern void testEth();
extern void testEthFail();
extern void ethServerConnect();
#ifdef __cplusplus
}
#endif//_cplusplus
#endif
