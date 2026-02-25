#include<iostream>
#include<string>
#include <typeinfo>
using namespace std;

// Defining template
template<typename T>
class Box{
    T val;
public:
    // Box constructor
    Box(T v): val(v){}

    // to print the value 
    void print() const{
        cout<<"The value is: "<<val<<endl;
    }
};

int main(){
    // Calling box class for int
    Box<int>b(10);
    // Calling box for string 
    Box<string>b1("Hello");
    //Calling print function for both int and string
    b.print();
    b1.print();
    return 0;
}