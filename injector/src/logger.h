#pragma once 
#include <stdio.h>
#include <cstdarg>

class Logger {
public:
    enum class EErrorType {
        INFO,
        ERR,
        DEBUG,
        SUCCESS
    };

    static void log(const char* format, EErrorType errortype, ...) {
        va_list args;
        va_start(args, errortype);
        
        switch (errortype) {
            case EErrorType::INFO:
                printf("[*] ");
                break;
            case EErrorType::ERR:
                printf("[-] ");
                break;  
            case EErrorType::DEBUG:
                printf("[DEBUG] ");
                break;
            case EErrorType::SUCCESS:
                printf("[+] ");
                break;
        }
        vprintf(format, args);
        printf("\n");
        
        va_end(args);
    }
};

#define LOG_INFO(format, ...) Logger::log(format, Logger::EErrorType::INFO, ##__VA_ARGS__)
#define LOG_ERROR(format, ...) Logger::log(format, Logger::EErrorType::ERR, ##__VA_ARGS__)
#define LOG_DEBUG(format, ...) Logger::log(format, Logger::EErrorType::DEBUG, ##__VA_ARGS__)
#define LOG_SUCCESS(format, ...) Logger::log(format, Logger::EErrorType::SUCCESS, ##__VA_ARGS__)
