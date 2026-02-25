#include<iostream>
using namespace std;

// the declared variable are already int& but undeclared are only int 
// Overloaded process according to lvalue and rvalue
void process(int& x) {
    cout << "int lvalue: " << x << endl;
}

void process(int&& x) {
    cout << "int rvalue: " << x << endl;
}

void process(const string& s) {
    cout << "string lvalue: " << s << endl;
}

void process(string&& s) {
    cout << "string rvalue: " << s << endl;
}

// Making a template that passes the argument to process
// Args&& -> forwarding (universal) references
template<typename... Args>
void forwardAll(Args&&... args){
    (process(std::forward<Args>(args)),...);
}

int main(){
    int x = 10;
    string name = "Naman";

    cout << "---- First Call ----" << endl;
    forwardAll(x, 20, name, string("temp"));

    cout << "\n---- Second Call ----" << endl;
    forwardAll(100, string("hello"));
}