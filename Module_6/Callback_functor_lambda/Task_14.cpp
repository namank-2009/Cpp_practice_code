#include<iostream>
using namespace std;

int main() {
    int counter = 0;

    // Here mutable helps to change the value of counter inside the lambda function 
    // As value from local passed by value to lambda is const which cannot be changed but mutable make it possible to make increment inside the function
    auto inc = [counter]() mutable { counter++; };
    inc();
    // Here when we increment the counter it has no impact on outer counter as the copy of the counter is created inside the inc()
    // So the value of counter inside function changes not the outer counter
    std::cout << "After inc() (by value): counter = " << counter << std::endl; // Expect 0

    auto incRef = [&counter]() { counter++; };
    incRef();
    // Here when we pass the counter by reference the value of actual counter outside the function changes 
    // so when we print the counter the value of counter changes to 1
    std::cout << "After incRef() (by reference): counter = " << counter << std::endl; // Expect 1

    return 0;
}
