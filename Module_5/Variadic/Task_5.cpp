#include<iostream>
using namespace std;

// Base case
void printAll(){
}

// Defined printAll with proper templates
template<typename... Args>
void printAll(int a, Args... args) {
    std::cout << a << " ";
    printAll(args...);
}

int main(){
    printAll(1, 2, 3); // OK
    cout<<endl; 
    printAll(42);      // OK (args... is empty, next call: printAll();)
    printAll();  // Added base case for this
}