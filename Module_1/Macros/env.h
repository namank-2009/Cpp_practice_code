#ifndef ENV_H   // Include guard
#define ENV_H

#include <iostream>

// Conditional API_URL definition based on environment
#if defined(DEV)
    #define API_URL "http://localhost"
#elif defined(TEST)
    #define API_URL "http://test-server"
#else
    #define API_URL "http://prod-server"  // Default production environment
#endif

// Optional inline function to print API_URL
inline void printAPIUrl() {
    std::cout << "The API URL for this environment is: " << API_URL << std::endl;
}

#endif // ENV_H