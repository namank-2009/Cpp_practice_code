#include<iostream>
using namespace std;

int main(){
    int days;
    cout<<"Enter the number of days"<<endl;
    cin>>days;

    int years;
    int weeks;
    int remainingDays;

    /* Total years */
    years = days/365;

    //Remaining days
    remainingDays = days%365;

    // Weeks in remaining days 
    weeks = remainingDays/7;

    // Leftover Days
    remainingDays = remainingDays%7;

    //Printing values of years, week and days
    cout<<"The number of years = "<<years<<" Years"<<endl;
    cout<<"The number of weeks= "<<weeks<<" Weeks"<<endl;
    cout<<"The number of days = "<<remainingDays<<" Days"<<endl;

    return 0;
}