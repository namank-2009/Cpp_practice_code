#include<iostream>
using namespace std;

int main() {
    int a = 2, b = 3;
    // Here we are using b by reference so it is giving the accurate result even when we chnge the value of b later
    // Here if we use b by value it gives the same result even when we change the value of b 
    // because it creates the copy of b instead reference uses the actual value of variqable at that time
    auto op = [a, &b](int x) { return x * a + b; };

    std::cout << "op(5): " << op(5) << std::endl; // uses b=3

    b = 100; // Change b by reference
    std::cout << "op(5) after b=100: " << op(5) << std::endl; // uses b=100

    // Making both of them by reference
    auto op2 = [&a, &b](int x) {
        return x * a + b;
    };

    a = 10;

    std::cout << "\nAfter modifying a to 10 (reference capture):\n";
    std::cout << "op2(5) = " << op2(5) << "\n";

    return 0;
}
