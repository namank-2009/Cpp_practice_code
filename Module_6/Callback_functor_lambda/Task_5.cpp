#include<iostream>
using namespace std;

// Struct Add with functor to add two integers
struct Add{
    int operator()(int a, int b)const{
        return a+b;
    }
};
int main(){
    // Making the object of Add
    Add add;
    // Calling through obj by passing the value
    int result = add(10,20);

    //Print final result
    cout<<"Sum: "<<result<<endl;
    return 0;
}