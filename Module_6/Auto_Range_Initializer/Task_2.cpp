#include<iostream>
#include<typeinfo>
using namespace std;

int main(){
    auto first = 5;
    auto sec = 2.5;

    auto sum = first+sec; // type deduced to double
    cout<<"The sum of first and sec = "<<sum<<" of type: "<<typeid(sum).name()<<endl;

    auto first1 = 3;
    auto sec1 = 1.5f;

    auto multiply = first1*sec1;   // type deduced to float
    cout<<"The multiply of first1 and sec1 = "<<multiply<<" of type: "<<typeid(multiply).name()<<endl;

    auto a = 5 + 2.5;    // int + double: deduced as double
    auto b = 3 * 1.5f;   // int * float: deduced as float
    
    std::cout << "auto a = 5 + 2.5; value: " << a << ", type: " << typeid(a).name() << std::endl;
    std::cout << "auto b = 3 * 1.5f; value: " << b << ", type: " << typeid(b).name() << std::endl;
    return 0;
}

// The sum of first and sec = 7.5 of type: d
// The sum of first1 and sec1 = 4.5 of type: d
// auto a = 5 + 2.5; value: 7.5, type: d
// auto b = 3 * 1.5f; value: 4.5, type: f