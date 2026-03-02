#include<iostream>
#include<cstring>
using namespace std;

class MyString{
    char* str;

    public:
        // Constructor 
        MyString(const char* ch){
            // allocating memory to str and then copying the value in str
            str = new char[strlen(ch) + 1];
            strcpy(str, ch);
        }

        // Copy constructor
        MyString(const MyString& obj){
            str = new char[strlen(obj.str)+1];
            strcpy(str,obj.str);
        }

        // Copy Assignment
        MyString& operator=(const MyString& obj){
            if(this != &obj){
                delete[] str;
                str = new char[strlen(obj.str)+1];
                strcpy(str,obj.str);
            }
            else{
                cout<<"There is self assignment both the objects are same"<<endl;
            }
            return *this;
        }

        // Destructor
        ~MyString(){
            delete[] str;
        }


        void display(const char* label) const {
            std::cout << label << "String: " << str<< " (at: " << static_cast<const void*>(str) << ")\n";
    }
};

int main(){
    // Calling will allocate the memory
    MyString m1("Naman");
    // Copy constructor will be called
    MyString m2(m1);
    // Displaying both
    m1.display("m1: ");
    m2.display("m2: ");
    //Calling the constructor
    MyString m3("Ram");
    m3.display("m3: ");
    // Copy Assignment
    m3 = m1;
    m3.display("m3: ");
    m1.display("m1: ");
    
    m1 = m1; // Self assignment
    m1.display("m1: ");
}