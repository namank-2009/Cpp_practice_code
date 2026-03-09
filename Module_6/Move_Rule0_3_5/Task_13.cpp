#include <iostream>
#include <cstring>
#include <utility>

class MyString {
    char* data;
public:
    MyString(const char* str) {
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
    }
    //Copy Constructor
    MyString(const MyString& other) {
        data = new char[std::strlen(other.data) + 1];
        std::strcpy(data, other.data);
    }
    //Move Constructor
    MyString(MyString&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }
    //Destructor
    ~MyString() {
        delete[] data;
    }
    //Printing the value
    void print(const char* label) const {
        std::cout << label << " [data@" << static_cast<const void*>(data)
                  << "] " << (data ? data : "null") << std::endl;
    }

    //Reset function to change the value
    void safeReset(const char* str) {
        delete[] data;
        data = new char[std::strlen(str) + 1];
        std::strcpy(data, str);
    }
};

int main() {
    MyString s1("hello");
    MyString s2 = std::move(s1);

    s1.print("s1 (moved-from): ");
    s2.print("s2 (moved-to): ");

    // Safe: assign, reset, or destroy moved-from object
    s1.safeReset("reset ok");
    s1.print("s1 (after reset): ");

    // Unsafe: using data pointer directly (may be nullptr)
    // std::cout << s1.data[0];  // Dangerous! Don't do this!

    return 0;
}
