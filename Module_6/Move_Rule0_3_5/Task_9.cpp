#include <iostream>
#include <cstring>
#include <utility>

class MyString {
    char* data;
public:
    MyString(const char* str) {
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
        std::cout << "Constructor for " << data << std::endl;
    }
    MyString(const MyString& other) {
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
        std::cout << "Copy constructor for " << data << std::endl;
    }

    MyString(MyString&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Move constructor\n";
    }

    ~MyString() {
        std::cout << "Destructor for " << (data ? data : "null") << std::endl;
        delete[] data;
    }
    
    void print() const {
        std::cout << "MyString: " << (data ? data : "null") << std::endl;
    }
};

//When returning a local object by value, compiler treats it as:
//It can be moved instead of copied.
MyString makeString() {
    MyString temp("Hello from makeString!");
    return temp; // May trigger move or RVO
}

// Return value optimisation RVO
int main() {
    MyString s = makeString(); // here it will call the move as object of local obj when return treat it as move
    s.print();
    return 0;
}
