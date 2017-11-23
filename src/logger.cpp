// Logger.cpp - from professional C++ programming 
//        http://www.wiley.com/WileyCDA/WileyTitle/productCd-0470932449.html
// Implementation of a multithread safe singleton logger class
#include <stdexcept>
#include "logger.h"

using namespace std;

const string Logger::kLogLevelDebug = "DEBUG";
const string Logger::kLogLevelInfo  = "INFO";
const string Logger::kLogLevelError = "ERROR";

//const char* const Logger::kLogFileName = "/var/log/incoming/events.log";
const char* const Logger::kLogFileName = "/home/pi/projects/incoming/logs/events.log";

Logger* Logger::pInstance = nullptr;

mutex Logger::sMutex;

Logger& Logger::instance()
{
    static Cleanup cleanup;

    lock_guard<mutex> guard(sMutex);
    if (pInstance == nullptr)
        pInstance = new Logger();
    return *pInstance;
}

Logger::Cleanup::~Cleanup()
{
    lock_guard<mutex> guard(Logger::sMutex);
    delete Logger::pInstance;
    Logger::pInstance = nullptr;
}

Logger::~Logger()
{
    mOutputStream.close();
}

Logger::Logger()
{
    mOutputStream.open(kLogFileName, ios_base::app);
    if (!mOutputStream.good()) {
        throw runtime_error("Unable to initialize the Logger!");
    } 
}

void Logger::log(const string& inMessage, const string& inLogLevel)
{
    lock_guard<mutex> guard(sMutex);
    logHelper(inMessage, inLogLevel);
}

void Logger::log(const vector<string>& inMessages, const string& inLogLevel)
{
    lock_guard<mutex> guard(sMutex);
    for (size_t i = 0; i < inMessages.size(); i++) {
        logHelper(inMessages[i], inLogLevel);
    }
}

void Logger::logHelper(const std::string& inMessage, const std::string& inLogLevel)
{
    time (&rawTime);
    currentLocalTime = localtime (&rawTime);
    cout << asctime(currentLocalTime) << "-D-" << endl;

    mOutputStream << asctime(currentLocalTime) << ":" << inLogLevel << ": " << inMessage << endl;
}
