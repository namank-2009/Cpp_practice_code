#include<iostream>
using namespace std;

int main(){
    /* Principal value on which we will calculate the simple interest */
    float principalAmount;
    cout<<"Enter the principalAmount Value";
    cin>>principalAmount;

    /*Rate tells about the percentage of interest on the principal*/
    float interestRate;
    cout<<"Enter the interestRate Value";
    cin>>interestRate;

    /* Time Period*/
    float timePeriod;
    cout<<"Enter the timePeriod Value";
    cin>>timePeriod;

    /* For simple interest we will use the formula SI = (P * R * T) / 100  */
    float simpleInterestOnPrincipalAmount = (principalAmount*interestRate*timePeriod)/100;

    /*Printing the principalAmountvalue*/
    cout<<"The principal amount = "<<principalAmount<<endl;
    /*Printing the interestRate value*/
    cout<<"The Interest rate  = "<<interestRate<<endl;
    /*Printing the timePeriod value*/
    cout<<"The time period = "<<timePeriod<<endl;
    /*Printing the simpleInterestOnPrincipalAmount value*/
    cout<<"The Simple Interest = "<<simpleInterestOnPrincipalAmount<<endl;
    return 0;
}