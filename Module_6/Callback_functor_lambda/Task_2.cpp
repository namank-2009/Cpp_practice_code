#include<iostream>
#include<string>
using namespace std;

void greetMorning(const std::string& name){
    cout<<"Good morning, "<<name<<"!"<<endl;
}

void greetEvening(const std::string& name){
    cout<<"Good evening "<<name<<"!"<<endl;
}

// Taking the function and name as parameter
void invokeCallback(void (*callback)(const std::string&), const std::string& name){
    callback(name);
}

int main(){
    // firstly calling the greetMorining function through callback
    invokeCallback(greetMorning,"Naman");
    // Then calling the greetEvening function through callback
    invokeCallback(greetEvening,"Naman");
}