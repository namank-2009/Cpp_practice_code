#include<iostream>
using namespace std;

int main(){
    int counter = 0;
    // Made the lambda mutable
    auto next = [counter]()mutable{
        counter++;
        return counter;
    };
    
    // We are calling the next() the value of counter is updated each time
    // The value is changing because we had made them mutable 
    // The copy of counter is passed to the lambda no reference to outer counter
    cout<<"next() value: "<<next()<<endl;
    cout<<"next() value: "<<next()<<endl;
    cout<<"next() value: "<<next()<<endl;
    cout<<"next() value: "<<next()<<endl;

    // No change to outer counter as we passed the counter by value to the next()
    cout<<"Outer counter: "<<counter<<endl;
}