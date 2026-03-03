#include<iostream>
#include<cstring>
#include <utility> 
using namespace std;

class MyString{
    char* data;
    public:
    // Constructor
    MyString(const char* str){
        data = new char[strlen(str)+1];
        strcpy(data,str);
    }

    // Move Constructor
    MyString(MyString&& other) noexcept{
        data = other.data;
        other.data = nullptr;
    }

    // Destructor
    ~MyString(){
        if(data){
            delete[] data;
        }
    }
    void display(const string label){
        cout<<"Calling by object "<<label<<" data: ";
        if(data)
            cout<<data;
        else
            cout<<"nullptr";
        cout<<endl;
    }
};

int main(){
    MyString obj1("Naman");
    obj1.display("obj1");

    // Using the move 
    MyString obj2 = move(obj1);
    obj1.display("obj1");
    obj2.display("obj2");
}