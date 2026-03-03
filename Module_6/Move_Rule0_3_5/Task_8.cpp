#include <iostream>
#include <vector>
#include <string>
#include<cstring>

// Rule of 0: This class contains only STL types (std::vector, std::string)
// that manage their own resources. We do NOT need to define:
// - Destructor
// - Copy constructor
// - Copy assignment operator
// - Move constructor
// - Move assignment operator
// The compiler-generated versions are correct and safe!
class Wrapper {
public:
    std::vector<int> data;
    std::string label;

    Wrapper(std::string l, std::initializer_list<int> il)
        : data(il), label(std::move(l)) {}

    void print(const char* tag) const {
        std::cout << tag << " label: " << label << " data: ";
        for (auto x : data) std::cout << x << " ";
        std::cout << " [data@" << static_cast<const void*>(data.data()) << "]" << std::endl;
    }
};

class ManualRuleOf3 {
    char* buf;

public:
    ManualRuleOf3(const char* str = "") {
        buf = new char[std::strlen(str) + 1];
        std::strcpy(buf, str);
    }

    // Copy Constructor (Deep Copy)
    ManualRuleOf3(const ManualRuleOf3& other) {
        buf = new char[std::strlen(other.buf) + 1];
        std::strcpy(buf, other.buf);
    }

    // Copy Assignment Operator
    ManualRuleOf3& operator=(const ManualRuleOf3& other) {
        if (this != &other) {
            delete[] buf;
            buf = new char[std::strlen(other.buf) + 1];
            std::strcpy(buf, other.buf);
        }
        return *this;
    }

    // Destructor
    ~ManualRuleOf3() {
        delete[] buf;
    }

    void print(const char* tag) const {
        std::cout << tag << ": " << buf 
                  << " [buf@" 
                  << static_cast<const void*>(buf) 
                  << "]" << std::endl;
    }
};

int main() {
    Wrapper w1("first", {1,2,3});
    w1.print("w1:");

    Wrapper w2 = w1;        // Copy
    w2.label = "copy";
    w2.print("w2:");

    Wrapper w3 = std::move(w1); // Move
    w3.label = "moved";
    w3.print("w3:");
    w1.print("w1 after move:"); // w1's data is valid but unspecified (empty/moved-from)

    std::cout << "\n===== MANUAL RULE OF 3 =====\n";

    ManualRuleOf3 m1("hello");
    ManualRuleOf3 m2 = m1;  // Copy constructor
    m1.print("m1");
    m2.print("m2");

    std::cout << "\nNotice:\n";
    std::cout << "- ManualRuleOf3 required 3 special functions.\n";
    std::cout << "- Wrapper required NONE.\n";
    return 0;
}
