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

        // Destructor
        ~MyString(){
            delete[] str;
        }


        void display(){
            cout<<"Name: "<<str<<endl;
        }
};

int main(){
    // Calling will allocate the memory
    MyString m("Naman");
    // Copy constructor will be called
    MyString mm(m);
    // Displaying both
    m.display();
    mm.display();
}