#include "logger.h"
#include <ctime>
#include <iomanip>

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

Logger::Logger() : logLevel(LogLevel::DEBUG) {}

void Logger::setLogLevel(LogLevel level) {
    logLevel = level;
}

void Logger::addOutputStream(std::ostream& os) {
    std::lock_guard<std::mutex> lock(mtx);
    outputStreams.push_back(&os);
}

void Logger::log(LogLevel level, const std::string& message) {
    if (level >= logLevel) {
        std::lock_guard<std::mutex> lock(mtx);
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);
        char timeStr[20];
        strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", &ltm);
        for (auto os : outputStreams) {
            (*os) << "[" << timeStr << "] [" << toString(level) << "] " << message << std::endl;
        }
    }
}

std::string Logger::toString(LogLevel level) {
    switch (level) {
    case LogLevel::DEBUG: return "DEBUG";
    case LogLevel::INFO: return "INFO";
    case LogLevel::WARNING: return "WARNING";
    case LogLevel::ERROR: return "ERROR";
    default: return "";
    }
}
