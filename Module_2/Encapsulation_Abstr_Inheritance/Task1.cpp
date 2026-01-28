#include<iostream>
using namespace std;

class BankAccount{
    //Private members of bankaccount class
    int accountNumber;
    double balance;

    public:
    //Constructor to intialise the value
    BankAccount(int ac){
        accountNumber = ac;
        balance = 0.0;
    }
    void deposit(double amount){
        if(amount>0){
            balance += amount;
        }else{
            cout<<"Insufficient Balance"<<endl;
        }
    }
    
    void withdraw(double amount){
        if(balance>=amount){
            balance -= amount;
        }
    }

    int getbalance(){
        cout<<"Balance for "<<accountNumber<<" is "<<balance<<endl;
        return balance;
    }
};
int main(){
    BankAccount b(101);
    b.deposit(1000);
    b.withdraw(299);
    b.getbalance();
}