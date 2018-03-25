#ifndef INCLUDE_APPLICATION_H
#define INCLUDE_APPLICATION_H

#include <stdio.h>
#include <iostream>
using namespace std;


class Application                               // Abstract class
{

    public:
        virtual void Method1()=0;               // Pure virtual function (abstract function)
        Application(string appName);
        ~Application();
        void Init();

    protected:
        string appName;
};
#endif
