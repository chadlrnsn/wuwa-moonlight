#include "logger.h"

std::unordered_map<Logger::LogLevel, std::string> Logger::lastMessages;
std::mutex Logger::logMutex;