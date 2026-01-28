#include<iostream>
#include<string>
using namespace std;

int main(){
    int choice;
    cout<<"Enter the desired operation you want to perform"<<endl;
    cout<<"[1]. Addition"<<endl;
    cout<<"[2]. Subtraction"<<endl;
    cout<<"[3]. Multiplication"<<endl;
    cout<<"[4]. Division"<<endl;
    cin>>choice;

    /* Taking input*/
    cout<<"Enter two integers";
    int number1, number2;
    cin>>number1;
    cin>>number2;

    int result;
    /* Using the switch case*/
    switch(choice){
        case 1:
        result  = number1+number2;
        cout<<"The addition of number1 and number2 is = "<<result <<endl;
        break;

        case 2:
        result = number1-number2;
        cout<<"The subtraction of number1 and number2 is = "<<result <<endl;
        break;

        case 3:
        result  = number1*number2;
        cout<<"The multiplication of number1 and number2 is = "<<result <<endl;
        break;

        case 4:
        if (number2 == 0) {
        cout << "Error: Division by zero not allowed" << endl;
        }
        else {
        result = number1/number2;
        cout<<"The division of number1 and number2 is = "<<result <<endl;
        }
        break;
        default:
        cout<<"Invalid input"<<endl;
    }
    return 0;
}