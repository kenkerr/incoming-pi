
#ifndef INCLUDE_REGMAP_H
#define INCLUDE_REGMAP_H

#include <string>
#include <map>
#include <ioComMgr.h>

std::map<std::string, int> registerMap;

typedef struct {
    std::string     regName;
    int             regNumber;
} REGDATA_TYPE;

REGDATA_TYPE regData[MAX_REGS];
#endif
