#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    // Defining a vector of pair of int, string and intialising their values in {} braces
    std::vector<std::pair<int, std::string>> v{{1, "A"}, {2, "B"}};

    // Printing the value of pair belongs to v
    // for (auto &[num, str] : v) {
    //     std::cout << "num: " << num << ", str: " << str << std::endl;
    // }
    
    // Printing the value of pair by using .first and .second
    for (auto &num: v) {
        std::cout << "num: " << num.first << ", str: " << num.second << std::endl;
    }
    return 0;
}
