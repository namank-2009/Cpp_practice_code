#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

class MyString {
    char* data;
public:
    MyString(const char* str) {
        data = new char[std::strlen(str)+1];
        std::strcpy(data, str);
        std::cout << "Constructed '" << data << "'\n";
    }
    MyString(const MyString& other) {
        data = new char[std::strlen(other.data)+1];
        std::strcpy(data, other.data);
        std::cout << "Copied '" << data << "'\n";
    }
    MyString(MyString&& other) noexcept : data(other.data) {
        other.data = nullptr;
        std::cout << "Moved! (resource at " << static_cast<void*>(data) << ")\n";
    }
    ~MyString() {
        std::cout << "Destructed '" << (data ? data : "null") << "'\n";
        delete[] data;
    }
};

int main() {
    std::vector<MyString> vec;
    MyString a("first");
    MyString b("second");

    std::cout << "\n-- push_back(a) (copy): --" << std::endl;
    vec.push_back(a);         // Calls copy constructor
    std::cout << "\n-- push_back(std::move(b)) (move): --" << std::endl;
    vec.push_back(std::move(b)); // Calls move constructor

    std::cout << "\n-- emplace_back(\"temp\"): --" << std::endl;
    vec.emplace_back("temp"); // Constructs in-place (calls direct constructor)
    

    std::cout << "\n-- End of main (destructors fire) --" << std::endl;
    return 0;
}
