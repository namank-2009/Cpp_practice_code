#include<iostream>
using namespace std;

// Here we can see that the calculator class has three member function of same name but 
// but different parameter but when we call them in main through the instance of calculator
// it will call the member according to its parameter and provides the accurate results.

class Calculator{
    public:
    // add function with int parameter
    int add(int a, int b){
        cout<<"The addition of number of int type "<<a<<" and "<<b<<" = "<<a+b<<endl;
        return a+b;
    }

    // add function with double parameter
    double add(double a, double b){
        cout<<"The addition of number of double type "<<a<<" and "<<b<<" = "<<a+b<<endl;
        return a+b;
    }

    // add function with string parameter
    string add(string a, string b){
        cout<<"The addition of number of string type "<<a<<" and "<<b<<" = "<<a+b<<endl;
        return a+b;
    }
};

int main(){
    Calculator cc;
    cc.add(2,3);
    cc.add(5.0,9.0);
    cc.add("4","5");
}