//
// Io.cpp  : Io Class
//

#include "io.h"


Io::Io() : Application ("IO") {
}

void Io::Method1 () {
    cout << "Io::Method1" << endl;
}

int main (){

    // Instatiate instance of Io object (call constructor)
    Io app = Io();

    cout << "Io:  Starting..." << endl;
//  app.Method1();

    return 0;
}
