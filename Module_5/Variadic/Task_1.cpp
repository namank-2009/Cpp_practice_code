#include<iostream>
using namespace std;

// Defined the base function for printall
void printAll(){
}

// defined a templeate that take all the arguments
template<typename T, typename... args>
void printAll(T first, args... rst){
    std::cout<<first <<" ";
    printAll(rst...);
}

int main(){
    // Calling the printAll function with different data types
    printAll(1, 2.5, "Hello");
    std::cout << std::endl;
}