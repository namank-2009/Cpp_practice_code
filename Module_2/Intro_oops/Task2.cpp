#include<iostream>
using namespace std;

/*
  BankAccount class demonstrates ENCAPSULATION
  - accountNumber and balance are PRIVATE (default in class)
  - ownerName is PROTECTED (accessible in derived classes)
*/
class BankAccount {
    int accountNumber;
    double balance;

    protected:
    string ownerName;

    public:

       BankAccount(int ac, string name)
        : accountNumber(ac), balance(0.0), ownerName(name) {}

    void deposit(double amount){
        if(amount>0){
            balance += amount;
        }
    }

    void withDraw(double amount){
        if(amount>0 && amount<=balance){
            balance -= amount;
        }
    }

    void getBalance(){
        cout<<"Balance = "<<balance<<endl;
    }
};

class VIPAccount: public BankAccount{
    public:
    VIPAccount(int ac, string name)
    : BankAccount(ac,name){}

    void getOwnerName(){
        cout<<"Owner name = "<<ownerName<<endl;
    }
};
int main(){
    BankAccount Ba(101,"Naman");
    Ba.deposit(1000);
    Ba.withDraw(500);
    Ba.getBalance();
    VIPAccount vp(1023,"Ravi");
    vp.getOwnerName();
}