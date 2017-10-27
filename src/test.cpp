#include <stdio.h>
#include <iostream>
using namespace std;


class Application                               // Abstract class
{

    public:
        virtual void Method1()=0;               // Pure virtual function (abstract function)
        Application(string appName);
        ~Application();

    protected:
        string appName;
};


class Io : public Application
{

    public:
        Io();
        void Method1();

    private:

};


// Defines
Application *__thisApp;

// Public Methods
Application::Application(string appName) {
    this->appName = appName;

    __thisApp     = this;
}

Application::~Application() {
//  shutdown();
}


// Io.cpp  : Io Class
//

Io::Io() : Application ("IO") {
};

void Method1 () {
    cout << "Io::Method1" << endl;
}

int main (){

    // Instatiate instance of Io object (call constructor)
    Io app = Io();

    cout << "Io:  Starting..." << endl;
//  app.Method1();

    return 0;
}
