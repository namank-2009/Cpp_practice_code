#include<iostream>
#include<typeinfo>
using namespace std;

// Defined generic templates
// Checking the type deduction according to varible 
template<typename T>
void showType(T t){
    std::cout << "Value: " << t << "\n";
    std::cout << "Deduced type: " << typeid(decltype(t)).name() << "\n";
}
int main(){
    // Calling showType for diff value
    showType(3);
    showType(3.24);
    return 0;
}