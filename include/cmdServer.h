
#ifndef INCLUDE_CMDSERVER_H
#define INCLUDE_CMDSERVER_H

#include <string>
#include <map>
#include "application.h"
#include "ioComMgr.h"

using namespace std;

#define DOG_DETER_ON    2
#define DOG_DETER_OFF   1
#define ALL_DONE        9

class CmdServer : public Application
{

    public:
        CmdServer();
        ~CmdServer();
        void Method1();
        int execute (IoComMgr ioCom);

    private:
        int getCommand();

};
#endif
