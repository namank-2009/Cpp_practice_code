#include<iostream>
using namespace std;

void addition(float number1, float number2){
    float sum = number1+number2;
    cout<<"The sum of numbers is = "<<sum<<endl;
}

void subtraction(float number1, float number2){
    float difference = number1-number2;
    cout<<"The subtration of numbers is = "<<difference<<endl;
}

void multiplication(float number1, float number2){
    float product = number1*number2;
    cout<<"The multiplication of numbers is = "<<product<<endl;
}

void division(float number1, float number2){
    if(number2 == 0){
        cout<<"Enter a valid number";
        return;
    }
   float quotient= number1/number2;
    cout<<"The division of numbers is = "<<quotient<<endl;
}

int main(){
    float number1;
    float number2;

    cout<<"Enter the two numbers";
    cin>>number1;
    cin>>number2;

    cout<<"Tell the operation you want to perform"<<endl;
    cout<<"[1]. Addition"<<endl;
    cout<<"[2]. Subtraction"<<endl;
    cout<<"[3]. Multiplication"<<endl;
    cout<<"[4]. Division"<<endl;

    int choice;
    cin>>choice;

    switch(choice){
       case 1:
        addition(number1,number2);
        break;
       case 2:
        subtraction(number1,number2);
        break;
       case 3:
        multiplication(number1,number2);
        break;
       case 4: 
        division(number1,number2);
        break;
       default:
        cout<<"Enter valid numbers";
    }
    
    return 0;
}