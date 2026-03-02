#include<iostream>

int main() {
    // defining the lambda function to add two elements
    auto add = [](int a, int b){ return a + b; };
    int result = add(5, 10);
    std::cout << "Sum: " << result << std::endl;
    return 0;
}
