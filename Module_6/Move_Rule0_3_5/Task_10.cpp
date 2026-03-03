#include<iostream>
#include<string>
using namespace std;

template<typename T>
void forwardToPrint(T&& str){
    forward<T>(str);
}

class MyString{
    char* str;
    public:
    MyString(MyString& obj){
        str = obj.str;
        obj.str = NULL;
    }
    void printAddress(MyString&& s){
        cout<<"Address: "<<static_cast<void*>(s.str)<<endl;
    }
};

int main(){

}