#include<iostream>
#include<cstring>
#include<utility>
using namespace std;

class MyString{
    char* str;
    public:

    //Constructor
    MyString(const char* data) {
        str = new char[std::strlen(data) + 1];
        std::strcpy(str, data);
        std::cout << "Constructed: " << str 
                  << " at " << static_cast<const void*>(str) << "\n";
    }

    // Copy Constructor
    MyString(const MyString& other) {
        str = new char[std::strlen(other.str) + 1];
        std::strcpy(str, other.str);
        std::cout << "Copied: " << str 
                  << " at " << static_cast<const void*>(str) << "\n";
    }

    //Move constructor
    MyString(MyString&& obj){
        str = obj.str;
        obj.str = NULL;
        std::cout << "Moved! at "<< static_cast<const void*>(str) << "\n";
    }

    // Destructor
    ~MyString() {
        std::cout << "Destructed "<< (str ? str : "null")<< " at "<< static_cast<const void*>(str) << "\n";
        delete[] str;
    }

    void printAddress(const string msg = ""){
        cout<<msg<<" buffers@ "<<static_cast<const void*>(str)<<endl;
    }
};

// Accept only rvalue
void printAddress(MyString&& s){
    s.printAddress("printAddress recieves");
}

// perfect forwarding
template<typename T>
void forwardToPrint(T&& str){
    printAddress(std::forward<T>(str));
}


int main(){
    std::cout << "---- LVALUE with std::move ----\n";
    MyString s1("lvalue");
    printAddress(std::move(s1));   // Cast to rvalue

    std::cout << "\n---- Temporary rvalue ----\n";
    printAddress(MyString("rvalue"));

    std::cout << "\n---- Perfect Forwarding ----\n";
    forwardToPrint(MyString("temp"));
      // rvalue forwarded

    MyString s2("hello");
    forwardToPrint(std::move(s2));     // moved rvalue

    return 0;
}