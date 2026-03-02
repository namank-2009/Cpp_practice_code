#include<iostream>
#include<string>

// greet function defined
void greet(const std::string &name){
    std::cout<<"Hello, "<<name<<"!"<<std::endl;
}

// Here the invoke function take the greet function and name as parameter
void invokeCallback(void (*callback)(const std::string&), const std::string &name){
    // here we are calling the greet functiona and passing the name
    callback(name);
}

int main(){
    // We are calling the invoke and passing the greet function and name
    invokeCallback(greet,"Naman");
    return 0;
}