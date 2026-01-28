#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>

#if defined(WINDOWS)
    #define PLATFORM_MESSAGE "This is a Windows operating system."
#elif defined(LINUX)
    #define PLATFORM_MESSAGE "This is a Linux operating system."
#elif defined(MAC)
    #define PLATFORM_MESSAGE "This is a macOS operating system."
#else
    #define PLATFORM_MESSAGE "Unknown OS"
#endif

// Single function definition
inline void printPlatform() {
    std::cout << PLATFORM_MESSAGE << std::endl;
}

#endif // PLATFORM_H
