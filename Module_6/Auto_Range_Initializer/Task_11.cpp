#include <iostream>
#include <vector>
#include <initializer_list>

// Number class defined with initializer list in its constructor
class Numbers {
public:
    std::initializer_list<int> list;
    Numbers(std::initializer_list<int> ilist) : list(ilist) {}
};
int main() {
    // Initialising by passing the value to constructor
    Numbers nums{1, 2, 3, 4, 5};

    //Directly printing each value by calling nums.list
    std::cout << "Numbers: ";
    for (auto x : nums.list) { // auto deduces as int
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
