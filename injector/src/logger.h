#pragma once 
#include <stdio.h>
#include <cstdarg>

class Logger {
public:
    enum class EErrorType {
        INFO,
        ERR
    };

    static void log(const char* format, EErrorType errortype, ...) {
        va_list args;
        va_start(args, errortype);
        
        printf(errortype == EErrorType::INFO ? "[+] " : "[-] ");
        vprintf(format, args);
        printf("\n");
        
        va_end(args);
    }
};

#define LOG_INFO(format, ...) Logger::log(format, Logger::EErrorType::INFO, ##__VA_ARGS__)
#define LOG_ERROR(format, ...) Logger::log(format, Logger::EErrorType::ERR, ##__VA_ARGS__)
