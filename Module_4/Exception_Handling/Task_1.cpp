#include<iostream>
#include<stdexcept>
using namespace std;

// Divide function for handling the exception well
int divide(int numerator, int denominator) {
    if (denominator == 0) {
        // throws an expection 
        throw runtime_error("Division by zero cannot be performed!!");
    }
    return numerator / denominator;
}

int main(){
    int numerator;
    int denominator;
    cout<<"Enter the value of numerator and denominator\n";
    cin>>numerator;
    cin>>denominator;
    try {
        int result = divide(numerator, denominator);
        cout << "The result is: " << result << endl;
    }
    
    // Here we catch the exception
    catch(const std::runtime_error& e){
        cout<<"Exception caught: "<<e.what()<<endl;
    }  
    
    return 0;
}