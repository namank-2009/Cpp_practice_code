#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

// Default LOG_LEVEL if not defined
#ifndef LOG_LEVEL
#define LOG_LEVEL 1  // ERROR only
#endif

// Logging levels
#define ERROR 1
#define WARN  2
#define INFO  3
#define DEBUG 4

// Advanced macro: compile-time filtering using #if/#elif/#else
#if LOG_LEVEL >= DEBUG
    #define LOG(level, msg) \
        do { \
            if(level == ERROR) std::cout << "[ERROR] " << msg << std::endl; \
            else if(level == WARN) std::cout << "[WARN] " << msg << std::endl; \
            else if(level == INFO) std::cout << "[INFO] " << msg << std::endl; \
            else if(level == DEBUG) std::cout << "[DEBUG] " << msg << std::endl; \
        } while(0)
#elif LOG_LEVEL == INFO
    #define LOG(level, msg) \
        do { \
            if(level == ERROR) std::cout << "[ERROR] " << msg << std::endl; \
            else if(level == WARN) std::cout << "[WARN] " << msg << std::endl; \
            else if(level == INFO) std::cout << "[INFO] " << msg << std::endl; \
        } while(0)
#elif LOG_LEVEL == WARN
    #define LOG(level, msg) \
        do { \
            if(level == ERROR) std::cout << "[ERROR] " << msg << std::endl; \
            else if(level == WARN) std::cout << "[WARN] " << msg << std::endl; \
        } while(0)
#elif LOG_LEVEL == ERROR
    #define LOG(level, msg) \
        do { \
            if(level == ERROR) std::cout << "[ERROR] " << msg << std::endl; \
        } while(0)
#else
    #define LOG(level, msg) // LOG_LEVEL = 0 or invalid, do nothing
#endif

#endif // LOGGER_H
