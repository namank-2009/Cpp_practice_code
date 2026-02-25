#include <iostream>


//int val = 42;
// If we pass reference of val by not declaring it static it will destroy when the function ends
// so we need to declare its static to pass the value
int& funcReturningReference() {
    static int val = 42; // Static for safe demonstration; if not static, BAD!
    return val;
}


int main() {
    auto x = funcReturningReference();   // x is an int (copy)
    auto& y = funcReturningReference();  // y is an int& (reference)
    
    std::cout << "x = " << x << " (address: " << &x << ")" << std::endl;
    std::cout << "y = " << y << " (address: " << &y << ")" << std::endl;

    y = 100; // modifies static int in function
    std::cout << "After y = 100, x = " << x << ", y = " << y << std::endl;
    
    return 0;
}
