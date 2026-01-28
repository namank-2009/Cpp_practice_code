#ifndef CONFIG_H   // 1. Start of include guard
#define CONFIG_H

#include <iostream>

// 2. Define version
#define VERSION 2   

// 3. Version-dependent message
#if VERSION >= 3
    #define VERSION_MESSAGE "Stable version"
#else
    #define VERSION_MESSAGE "Beta version"
#endif

// 4. Optional inline function to print version
inline void printVersion() {
    std::cout << VERSION_MESSAGE << std::endl;
}

#endif // CONFIG_H  // End of include guard