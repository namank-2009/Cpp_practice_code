#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};

    // Use auto for iterator deduction
    // std::vector<int>::iterator it = v.begin();
    // Instead of using this we use auto as it increases readibility and maintain the code structure well
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for(auto val:v){
        std::cout<<val<<" ";
    }
    return 0;
}
