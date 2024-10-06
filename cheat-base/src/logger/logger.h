#pragma once

#include <iostream>
#include <cstdio>
#include <cstdarg>

class Logger {
public:
    enum class LogLevel {
        ERR,
        WARNING,
        INFO,
        DEBUG
    };

    static void log(LogLevel level, const char* format, ...) {
        va_list args;
        va_start(args, format);

        switch (level) {
        case LogLevel::ERR:
            printf("\x1b[31m[*] ERROR:\x1b[0m "); // red prefix
            break;
        case LogLevel::WARNING:
            printf("\x1b[33m[*] WARNING:\x1b[0m "); // yellow prefix
            break;
        case LogLevel::INFO:
            printf("\x1b[32m[*] INFO:\x1b[0m "); // green prefix
            break;
        case LogLevel::DEBUG:
            printf("\x1b[34m[*] DEBUG:\x1b[0m "); // blue prefix
            break;
        }

        vprintf(format, args);
        printf("\n");

        va_end(args);
    }
};

#define LOG_ERROR(format, ...) Logger::log(Logger::LogLevel::ERR, format, __VA_ARGS__)
#define LOG_WARN(format, ...) Logger::log(Logger::LogLevel::WARNING, format, __VA_ARGS__)
#define LOG_INFO(format, ...) Logger::log(Logger::LogLevel::INFO, format, __VA_ARGS__)
#define LOG_DEBUG(format, ...) Logger::log(Logger::LogLevel::DEBUG, format, __VA_ARGS__)