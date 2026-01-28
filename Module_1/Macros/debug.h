#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG 42
#include <iostream>

// Conditional macro definition
#ifdef DEBUG
    #define DEBUG_PRINT(x) std::cout << "[DEBUG] " << x << std::endl
#else
    #define DEBUG_PRINT(x) // Does nothing in production
#endif

#endif // DEBUG_H
 