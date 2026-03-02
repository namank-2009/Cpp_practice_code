#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    // Defining the lambda function and multiplying each value of vector by using for_each
    std::for_each(v.begin(), v.end(), [](int& x) { x *= 2; });

    std::cout << "Updated vector: ";
    for (auto x : v)
        std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
