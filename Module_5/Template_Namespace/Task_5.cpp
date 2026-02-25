#include<iostream>
using namespace std;

// Generic template
template<typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    void print() const {
        std::cout << value << std::endl;
    }
};

// template class only for string
template<>
class Box<std::string> {
    std::string value;
public:
// std::move converts v into an rvalue so that:
// Instead of copying the string
// It moves the internal buffer
    Box(std::string v) : value(std::move(v)) {}
    void print() const {
        for (char c : value)
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        std::cout << std::endl;
    }
};

int main() {
    // Calling to specialized boxStr class
    Box<std::string> boxStr("hello, Templates!");
    //Calling print function
    boxStr.print(); 
    return 0;
}
