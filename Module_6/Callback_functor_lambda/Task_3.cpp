#include<iostream>
#include<string>
#include<functional>
using namespace std;

// invokeCallback function taking the normal as well as lambda function as argument along with name
void invokeCallback(function<void(const string&)>callback, const string& name){
    callback(name);
}

// Greet function defined 
void greet(const string& name){
    cout<<"Hello from regular function by "<<name<<endl;
}

int main(){
    const string name = "Naman";
    // Calling the invoke by passing normal function 
    invokeCallback(greet,name);
    // Calling the invoke by passing the lambda function
    invokeCallback([](const string& name){
    cout<<"Hello from lamda function by "<<name<<endl;
},name);
}