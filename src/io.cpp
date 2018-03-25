//
// Io.cpp  : Io Class
//

#include "logger.h"
#include <vector>
#include <string>
#include "io.h"

Io::Io() : Application ("I/O") {
}

Io::~Io()  {
}

void Io::Method1 () {
    cout << "Io::Method1" << endl;
}


int main (){

    // Instantiate instance of Io object (call constructor)
    Io app = Io();
    
    app.Init ();
/*
    // Instantiate the Logger
    Logger::instance().log("test message", Logger::kLogLevelDebug);
    vector<string> items = {"item1", "item2"};
    Logger::instance().log(items, Logger::kLogLevelError);
*/

    app.Method1();

    return 0;
}
