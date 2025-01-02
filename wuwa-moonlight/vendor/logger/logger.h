#pragma once

#include <iostream>
#include <cstdio>
#include <cstdarg>
#include <string>
#include <mutex>
#include <unordered_map>

// First declare enum class
enum class LogLevel
{
    ERR,
    WARNING,
    INFO,
    DEBUG
};

// Then specialize hash
namespace std
{
    template <>
    struct hash<LogLevel>
    {
        size_t operator()(const LogLevel &level) const
        {
            return hash<int>()(static_cast<int>(level));
        }
    };
}

class Logger
{
public:
    using LogLevel = ::LogLevel; // Use the declared enum

private:
    static std::unordered_map<LogLevel, std::string> lastMessages;
    static std::mutex logMutex;

    static std::string formatMessage(LogLevel level, const char *format, va_list args)
    {
        char messageBuffer[1024];
        vsnprintf(messageBuffer, sizeof(messageBuffer), format, args);
        return std::string(messageBuffer);
    }

public:
    static void log(LogLevel level, const char *format, ...)
    {
        std::lock_guard<std::mutex> lock(logMutex);

        va_list args;
        va_start(args, format);
        std::string currentMessage = formatMessage(level, format, args);
        va_end(args);

        // Check if the message is different from the last one for this level
        if (lastMessages[level] != currentMessage)
        {
            const char *prefix;
            switch (level)
            {
            case LogLevel::ERR:
                prefix = "\x1b[31m[*] ERROR:\x1b[0m ";
                break;
            case LogLevel::WARNING:
                prefix = "\x1b[33m[*] WARNING:\x1b[0m ";
                break;
            case LogLevel::INFO:
                prefix = "\x1b[32m[*] INFO:\x1b[0m ";
                break;
            case LogLevel::DEBUG:
                prefix = "\x1b[34m[*] DEBUG:\x1b[0m ";
                break;
            }

            printf("%s%s\n", prefix, currentMessage.c_str());
            lastMessages[level] = currentMessage;
        }
    }
};

#define LOG_ERROR(format, ...) Logger::log(Logger::LogLevel::ERR, format, __VA_ARGS__)
#define LOG_WARN(format, ...) Logger::log(Logger::LogLevel::WARNING, format, __VA_ARGS__)
#define LOG_INFO(format, ...) Logger::log(Logger::LogLevel::INFO, format, __VA_ARGS__)
#define LOG_DEBUG(format, ...) Logger::log(Logger::LogLevel::DEBUG, format, __VA_ARGS__)