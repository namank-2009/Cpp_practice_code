#include<iostream>
#include<stdexcept>
using namespace std;

class BankAccount{
    private:
        string owner;
        int accountNumber;
        double balance;
    public:
        BankAccount(string own, int an, double bal): owner(own),accountNumber(an),balance(bal){}

        // Strong Gurantee
        void deposit(double amount){
            if(amount<0){
                throw invalid_argument("Deposit amount cannot be negitive.");
            }
           double newBalance = balance + amount;  // commit-style change
            balance = newBalance;  
        }   

        // Basic Gurantee
        void withdraw(double amount){
            if(amount<0){
                throw invalid_argument("Deposit amount cannot be negitive.");
            }
            if(balance<amount){
                throw runtime_error("Insufficient funds");
            }
            balance -= amount;
        }

        //No throw gurantee
        bool transferTo(BankAccount& targetAccount, double amount) noexcept{
            if(amount<0){
                return false;
            }
            if(balance<amount){
                return false;
            }
            targetAccount.balance+=amount;
            balance -= amount;
            return true;
        } 

        double getBalance() const{
            return balance;
        }
        void print(){
            cout<<"Account Owner: "<<owner<<endl;
            cout<<"Account Number: "<<accountNumber<<endl;
            cout<<"Balance: "<<balance<<endl;
            cout << "---------------------------\n";
        }
};

int main(){
    BankAccount alice("Alice", 1001, 500.0); 
    BankAccount bob("Bob", 1002, 300.0);

    cout << "----Testing Deposit (Strong Guarantee)----\n";
    try { 
        alice.deposit(200.0); 
        alice.print(); 

        alice.deposit(-50.0); // Should throw 
    } 
    catch (const std::exception& e) { 
        std::cout << "Deposit error: " << e.what() << std::endl; 
    } 
    alice.print();

    cout << "\n---- Testing Withdraw (Basic Guarantee) ----\n";
    try { 
        alice.withdraw(200.0); 
        alice.print();
        alice.withdraw(600.0);
    } 
    catch (const std::exception& e) { 
        std::cout << "Invalid Withdrawal error: " << e.what() << std::endl; 
    } 
    alice.print();

    cout << "\n----Testing Transfer (No-throw Guarantee) ----\n";
    
    bool success1 = alice.transferTo(bob,100);
    cout << "Transfer 100 successful? " << success1 << endl;
    alice.print();
    bob.print();

    bool success2 = alice.transferTo(bob, 1000);
    cout << "Transfer 1000 successful? " << success2 << endl;
    alice.print();
    bob.print();

    return 0;
}