#include<iostream>
using namespace std;

int main(){
    int x = 10;
    int* ptr = &x; // ptr is a pointer to int
    auto p = ptr; // auto deduces the type of ptr, which is int*, so p becomes int*.
    auto& r = x; /// auto& deduces reference type → int&
    r = 120;
    cout<<"Modified the value of x using r via reference\n";
    cout<<"The value of x: "<<x<<endl;
    cout<<"The value of *p: "<<*p<<endl;
    cout<<"The value of r: "<<r<<endl;
    cout<<"---------------------\n";

    *p = 30;
    cout<<"Modified the value of x using *p via pointer\n";
    cout<<"The value of x: "<<x<<endl;
    cout<<"The value of *p: "<<*p<<endl;
    cout<<"The value of *ptr: "<<*ptr<<endl;
    cout<<"The value of r: "<<r<<endl;


}