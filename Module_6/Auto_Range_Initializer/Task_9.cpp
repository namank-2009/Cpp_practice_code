#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};   // Uniform initialization

    std::cout << "Vector elements initialized with { } : ";
    for (auto x : vec)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
