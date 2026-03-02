#include <iostream>
#include <functional>

auto makeLambda() {
    int temp = 5;
    // BAD: capturing local by reference!
    // As local value get destroyed when the function ends
    // So we should pass it by value to get the accurate result in the main
    // Here when we use the temp it no longer exist and goes out of scope so it value does not exist
    // So it results with undefined behavior
    return [&temp]() { return temp * 2; }; // Lambda holds a reference to a local
}

auto CorrectLambda() {
    int temp = 5;
    // Pass the local variable by value so a copy is created in lambda
    return [temp]() { return temp * 2; }; // Lambda holds a reference to a local
}
int main() {
    auto lambda = makeLambda();
    std::cout << "Calling lambda after temp is gone: " << lambda() << std::endl; // Undefined behavior!

    auto result = CorrectLambda();
    std::cout << "Calling lambda by passing it by value: " << result() << std::endl; // Undefined behavior!
    return 0;
}
