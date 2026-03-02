#include<iostream>
using namespace std;

int main(){
    // Multiply() with x and factor as argument where factor default value is 2
    auto multiply = [](int x, int factor=2){
        return x*factor;
    };

    // We are only passing the x value and it will take the default value of factor
    cout<<"multiply(10): "<<multiply(10)<<endl;  // Output: 20

    //We are passing x and factor so it will take factor as 5
    cout<<"multiply(10,5): "<<multiply(10,5)<<endl; // Output: 50

    return 0;
}