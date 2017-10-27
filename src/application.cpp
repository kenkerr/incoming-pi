#include "application.h"

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

