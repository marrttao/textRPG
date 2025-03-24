#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <vector>
#include <mutex>

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger {
public:
    static Logger& getInstance();

    void setLogLevel(LogLevel level);
    void addOutputStream(std::ostream& os);
    void log(LogLevel level, const std::string& message);

private:
    Logger();
    std::string toString(LogLevel level);

    LogLevel logLevel;
    std::vector<std::ostream*> outputStreams;
    std::mutex mtx;
};

#define LOG_DEBUG(message) Logger::getInstance().log(LogLevel::DEBUG, message)
#define LOG_INFO(message) Logger::getInstance().log(LogLevel::INFO, message)
#define LOG_WARNING(message) Logger::getInstance().log(LogLevel::WARNING, message)
#define LOG_ERROR(message) Logger::getInstance().log(LogLevel::ERROR, message)

#endif // LOGGER_H
