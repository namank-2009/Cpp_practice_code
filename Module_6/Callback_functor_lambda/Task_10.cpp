#include<iostream>
#include<string>
#include<functional>
using namespace std;


// Functors taking lambda function and name as argument
void invokeCallback(std::function<void(const std::string&)>callback, const std::string &name){
    // Calling the function to print the lambda function expression
    callback(name);
}

int main(){
    // Lambda function passed as an argument to invokeCallback 
    invokeCallback([](const std::string &name){
        std::cout<<"Lambda callback says: Welcome, "<<name<<"!"<<endl;
    },"Naman");

    return 0;
}