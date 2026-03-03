#include<iostream>
#include<cstring>
using namespace std;

class MyString{
    char* str;
    public:
        //Constructor
        MyString(const char* val){
            str = new char[strlen(val)+1];
            strcpy(str,val);
        }

        // Copy Constructor
        MyString(const MyString& obj1){
            str = new char[strlen(obj1.str)+1];
            strcpy(str,obj1.str);
        }

        // Copy Assignment
        MyString& operator=(const MyString& obj1){
            if(this != &obj1){
                delete[]str;
                str = new char[strlen(obj1.str)+1];
                strcpy(str,obj1.str);
            }
            return *this;
        }

        // Move constructor
        MyString(MyString&& obj){
            str = obj.str;
            obj.str = nullptr;
        }

        //Move Assignment
        MyString& operator=(MyString&& obj){
            if(this != &obj){
                delete[] str;      // purani memory delete
                str = obj.str;     // pointer steal
                obj.str = nullptr; // source nullify
            }   
            return *this;
        }

        // Destructor
        ~MyString() {
            std::cout << "Destructing: " << (str ? str : "null")<< " at " << static_cast<const void*>(str) << std::endl;
            delete[] str;
        }

        //Displaying the str
        void display(const char* label) const {
            std::cout << label << (str ? str : "null")
                  << " (at " << static_cast<const void*>(str) << ")\n";
        }
};

int main(){
    MyString s1("test");
    MyString s2 = s1;
    MyString s3 = std::move(s1);
    s1.display("s1: ");
    s2.display("s2: ");
    s3.display("s3: ");
    // Destructor output will show which objects hold memory,
    // which are null, and no double delete happens.
    return 0;
}