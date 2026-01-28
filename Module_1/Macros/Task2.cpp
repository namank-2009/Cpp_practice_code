#include "debug.h"

int main() {
    int x = 42;
    DEBUG_PRINT("Program started");
    DEBUG_PRINT("Value of x = " << x);

    std::cout << "Program running normally..." << std::endl;

    DEBUG_PRINT("Program finished");    
    return 0;
}
