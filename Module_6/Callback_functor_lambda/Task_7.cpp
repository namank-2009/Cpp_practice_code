#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int factor = 3;
    std::vector<int> v{1, 2, 3};

    // Here we using the copy of factor in the lambda function
    std::for_each(v.begin(), v.end(), [factor](int& x) { x *= factor; });
    std::cout << "After value-capture lambda (factor=3): ";
    for (auto x : v) std::cout << x << " ";
    std::cout << std::endl;

    // Now change factor in outer scope, and use reference capture
    factor = 10;
    // Here we using the reference of factor in the lambda function
    std::for_each(v.begin(), v.end(), [&factor](int& x) { x *= factor; });
    std::cout << "After reference-capture lambda (factor=10): ";
    for (auto x : v) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
