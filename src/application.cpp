#include "logger.h"
#include <vector>
#include <string>
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

void Application::Init() {

    string startMessage = this->appName + " started";
    Logger::instance().log(startMessage, Logger::kLogLevelInfo);
/*
    vector<string> items = {"item1", "item2"};
    Logger::instance().log(items, Logger::kLogLevelError);
*/
    return;
}
