#include<iostream>
using namespace std;

template<typename T>
T sumAllRecursive(T value) {
    return value;
}

// Recursive case
template<typename T, typename... Rest>
auto sumAllRecursive(T first, Rest... rest) {
    return first + sumAllRecursive(rest...);
}

// Fold expression
// Here we dont need to separately take one element then call the recursion for another one.
template<typename... Args>
auto sumAll(Args... arg){
    return (arg + ...); // Unary left fold
}
int main(){
    // Calling the sum template function
    auto ans1 = sumAll(1,2,3.5,4.5);
    cout<<"The sum is "<<ans1<<endl;

    auto ans2 = sumAllRecursive(3.5,4.5);
    cout<<"The sum is "<<ans2<<endl;
}