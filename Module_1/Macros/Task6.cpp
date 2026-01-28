#include "myheader.h"

void printMessage() {
    std::cout << "This is a message from file1.cpp" << std::endl;
}


#include "myheader.h"

void useConstant() {
    std::cout << "Value of PI: " << PI << std::endl;
}

#include "myheader.h"

int main() {
    printMessage();
    useConstant();
    return 0;
}
