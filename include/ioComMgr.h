#ifndef INCLUDE_IOCOMMGR_H
#define INCLUDE_IOCOMMGR_H

#include <string>
#include <map>
#include "application.h"

#define MAX_REGS 1024

#define IOCOM_SUCCESS      0
#define IOCOM_FIRST_ERROR  10000
#define IOCOM_NO_SUCH_NAME 10001

using namespace std;

static const std::string REGMAP_FILENAME = "registerMap.dat";

class IoComMgr 
{

    public:
        IoComMgr();
        ~IoComMgr();
        int writeReg(int registerNumber, int valueToWrite);
        int writeReg(int registerNumber, float valueToWrite);
        int writeReg(string registerName, int valueToWrite);
        int writeReg(string registerName, float valueToWrite);
        void create();
        void map();

    private:
        int getRegisterNumber (string registerName);
        int reg[MAX_REGS];
        string logMessage;
    
//      std::map<std::string, int> registerMap;
        #include "registerMap.h"

};
#endif
