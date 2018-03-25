#include <map>
#include <iostream>
#include <fstream>
#include "ioCom.h"
#include "ioComMgr.h"
#include "logger.h"


// Constructor
IoComMgr::IoComMgr(){
    ifstream     regMapFile;
    string       regMapFilename;
    const char   *pCfgDir;
   
    pCfgDir = getenv ("CFGDIR");
    if (!pCfgDir) {
        cout << "getenv(CFGDIR) returned null" << endl;
        return;
    }
    regMapFilename.assign (pCfgDir);
    regMapFilename += "/" + REGMAP_FILENAME;

    regMapFile.open (regMapFilename, ios::binary);
    regMapFile.read ((char *) &registerMap, sizeof(registerMap));
    regMapFile.close();

    std::map<string,int>::iterator it=registerMap.begin();

    cout << "register Map" << endl;
    while (it != registerMap.end()){
        string regName=it->first;
        int    regNum =it->second;
        cout << "\t register " << regNum << " name = " << regName << endl;
    }
}

// Destructor
IoComMgr::~IoComMgr(){
}

void IoComMgr::create(){
// Create ioCom, a mappable memory structure
}

void IoComMgr::map(){
// Map ioCom
// return key?
}

int IoComMgr::writeReg (int registerNumber, int valueToWrite){
    reg[registerNumber] = valueToWrite;
    return IOCOM_SUCCESS;
}

int IoComMgr::writeReg (int registerNumber, float valueToWrite){
    memcpy ( (void *) &reg[registerNumber], (const void *) &valueToWrite, sizeof(float));
    return IOCOM_SUCCESS;
}

int IoComMgr::writeReg (string registerName, int valueToWrite){

    cout << "DBG> writeReg(string,int) - 1" << endl;

    cout << "DBG> Setting register[" <<  getRegisterNumber(registerName) << "] (" << registerName + ") = " << valueToWrite << endl;

    if (int registerNumber = getRegisterNumber(registerName) > IOCOM_FIRST_ERROR) {
        logMessage = "writeReg error # " + std::to_string(registerNumber) + "writing register " + registerName;
        Logger::instance().log(logMessage, Logger::kLogLevelDebug);
        return registerNumber;
    } else {
        reg[getRegisterNumber(registerName)] = valueToWrite;
        return IOCOM_SUCCESS;
    }

}

int IoComMgr::writeReg (string registerName, float valueToWrite){
    memcpy ( (void *) &reg[getRegisterNumber(registerName)], (const void *) &valueToWrite, sizeof(float));
    return IOCOM_SUCCESS;
}

int IoComMgr::getRegisterNumber (string registerName) {
/*
    if (registerMap.find(registerName) == registerMap.end()) {
    */
        return IOCOM_NO_SUCH_NAME;
/*
    } else {
        return registerMap[registerName];
    }
*/
}
