#include "logger.h"
#include "cmdServer.h"

// Constructor
CmdServer::CmdServer() : Application ("cmdServer"){
}

CmdServer::~CmdServer(){
}


void CmdServer::Method1 () {
    cout << "CmdServer::Method1" << endl;
}


int main (){

    // Instantiate instance of Io object (call constructor)
    CmdServer app = CmdServer();
    
    app.Init ();

    IoComMgr ioCom = IoComMgr();

    app.execute(ioCom);
/*
    // Instantiate the Logger
    Logger::instance().log("test message", Logger::kLogLevelDebug);
    vector<string> items = {"item1", "item2"};
    Logger::instance().log(items, Logger::kLogLevelError);
*/

    app.Method1();

    return 0;
}

int CmdServer::execute(IoComMgr ioCom){
    int command;
    int status;
    
    cout << "cmdServer/execute - 1"  << endl;

    while (true) {
        cout << "cmdServer/execute - 2"  << endl;
        command = getCommand();

        cout << "cmdServer/execute - 3"  << endl;
        switch (command) {

            case DOG_DETER_ON:
                cout << "DBG> cmdServer DOG_DETER_ON " << endl;
                if ( (status=ioCom.writeReg("strobe", 1)) != IOCOM_SUCCESS) {
                    // TODO return failure message to command initiator
                }

                if ( (status=ioCom.writeReg("siren",  1)) != IOCOM_SUCCESS) {
                    // TODO return failure message to command initiator
                }

                break;

            case DOG_DETER_OFF:
                cout << "DBG> cmdServer DOG_DETER_OFF " << endl;
                if ( (status=ioCom.writeReg("strobe", 0)) != IOCOM_SUCCESS) {
                    // TODO return failure message to command initiator
                }

                if ( (status=ioCom.writeReg("siren",  0)) != IOCOM_SUCCESS) {
                    // TODO return failure message to command initiator
                }

                break;

            case ALL_DONE:
                return 0;

            default:
                break;
        }
    }
}

int CmdServer::getCommand() {
    int command;

    cout << "Enter command (1=OFF; 2=ON; 9=QUIT): ";
    cin >> command;
    return command;
}
