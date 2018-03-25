//
// Configure.cpp  : Configure Class
//

#include "logger.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "configure.h"
#include "tinyxml2.h"
#include "ioCom.h"
#include "registerMap.h"
#include "ioComMgr.h"

using namespace tinyxml2;

Configure::Configure() : Application ("Configure") {
}

Configure::~Configure()  {
}

void Configure::Method1() {
    cout << "Configure::Method1" << endl;
}


int main (){
    XMLDocument cfgDoc;
    XMLElement  *pElement;

    string      dataDictionaryFilename;
    string      regMapFilename;
    const char  *pCfgDir;
    int         registerNumber;
    string      registerName;
    ofstream    regMapFile;

    pCfgDir = getenv ("CFGDIR");
    if (!pCfgDir) {
        cout << "getenv returned null" << endl;
        return 3;
    }

    dataDictionaryFilename.assign (pCfgDir);
    dataDictionaryFilename += "/dataDictionary.xml";

    regMapFilename.assign (pCfgDir);
    regMapFilename += "/" + REGMAP_FILENAME;

    // Instantiate instance of Configure object (call constructor)
    Configure app = Configure();
    app.Init ();

    cout << "Opening " << dataDictionaryFilename << endl;

    // Read configuration xml file and build necessary data structures
    if (cfgDoc.LoadFile (dataDictionaryFilename.c_str()) != XML_SUCCESS) {
        cout << "cfgDoc.LoadFile failed, filename=" << dataDictionaryFilename << endl;
        return 1;
    }
    
    XMLNode *pRoot = cfgDoc.FirstChild();
    if (pRoot == nullptr){
        cout << "cfgDoc.FirstChild returned null pointer" << endl;
        return 2;
    }
    cout << "first child found " << pRoot->Value() << endl;

    // Open the register Map file that is used at run time
    regMapFile.open (regMapFilename, ios::binary);

    for (pElement = pRoot->FirstChildElement ("register"); pElement != nullptr; pElement=pElement->NextSiblingElement("register") ) {

        XMLElement *pRegisterNumber = pElement->FirstChildElement("number");
        pRegisterNumber->QueryIntText(&registerNumber);
        cout << "Register Number = " << registerNumber << endl;

        XMLElement *pRegisterName = pElement->FirstChildElement("name");
        registerName.assign(pRegisterName->GetText());
        cout << "Register Name = " << registerName << endl;

        if (!registerMap.insert(std::pair<string, int> (registerName, registerNumber)).second) {
            Logger::instance().log("Failed to create map entry", Logger::kLogLevelError);
            return 1;
        }
    }

//TODO registerMap must be written out element by element  (needs some research)
    for (i=0; i<registerMap.size, i++) {
        regMapFile.write ((char *) &registerMap.stringElement, sizeof(registerMap));
    }
    regMapFile.close();    

    return 0;
}
