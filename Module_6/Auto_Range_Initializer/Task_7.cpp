#include <iostream>
#include <vector>
#include<string>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};

    // Const reference range-based for loop
    std::cout << "Elements (const ref): ";
    for (const auto& x : v) {
        std::cout << x << " ";
       // x = 42; // Uncommenting this line causes a compile-time error!
    }
    std::cout << std::endl;

    std::vector<std::string>names{"Naman","Harsh","Harman"};

    // Const reference range-based for loop
    std::cout << "Names (const ref): ";
    for (const auto& x : names) {
        std::cout << x << " ";
       // x = "Gopal" // Uncommenting this line causes a compile-time error!
    }
    std::cout << std::endl;
    return 0;
}
