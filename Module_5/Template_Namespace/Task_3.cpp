#include<iostream>
using namespace std;

// template defined which can take various data type in single definition
// no need to declare separate function for each data types
// Here T is used as data type of the function and variable
template<typename T> T add(T first, T sec){
    return first+sec;
}

int main(){
    // Taking int value input
    int first1;
    int second1;
    cout<<"Enter two int type numbers";
    cin>>first1;
    cin>>second1;
    cout<<"The sum of int numbers: "<<add(first1,second1)<<endl;

    // Taking double value input
    double first2;
    double second2;
    cout<<"Enter two double type numbers";
    cin>>first2;
    cin>>second2;
    cout<<"The sum of double numbers: "<<add(first2,second2)<<endl;

    // Taking float value input
    float first3;
    float second3;
    cout<<"Enter two float type numbers";
    cin>>first3;
    cin>>second3;
    cout<<"The sum of float numbers: "<<add(first3,second3)<<endl;

}