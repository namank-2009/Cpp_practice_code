#include<iostream>
#include <stdexcept>
#include <string>
#include <cmath>
using namespace std;

class InsufficientFundsException : public runtime_error{
    string accountNumber;
    double currentBalance;
    double requestedAmount;
    string message;
    public:
    InsufficientFundsException(const std::string& account, double balance, double amount) : std::runtime_error("Insufficient funds"), accountNumber(account),currentBalance(balance), requestedAmount(amount){
        message = "InsufficientFundsException: Account [" + accountNumber +
                  "] Balance: Rs." + to_string(currentBalance) +
                  ", Requested: Rs." + to_string(requestedAmount);
    }
    
    const char* what() const noexcept override{
        return message.c_str();
    }
};

class InvalidAmountException: public invalid_argument{
    double amount;
    string operation;
    string message;
    public:
    InvalidAmountException(double amount, const std::string& operation): std::invalid_argument("Invalid amount"), amount(amount), operation(operation){
        message = "InvalidAmountException: Operation [" + operation +
                  "] Invalid Amount: Rs." + to_string(amount);
    }
    
    const char* what() const noexcept override{
        return message.c_str();
    }
};

class AccountNotFoundException : public out_of_range{
    string accountNumber;
    string message;
    public:
    AccountNotFoundException(const std::string& accountNumber) : std::out_of_range("Account not found"), accountNumber(accountNumber){
         message = "AccountNotFoundException: Account [" + accountNumber + "] not found.";
    }

    const char* what() const noexcept override{
        return message.c_str();
    }
};

class TransactionLimitExceededException : public logic_error{
    double amount;
    double limit;
    string message;
    public:
    TransactionLimitExceededException(double amount, double limit): std::logic_error("Transaction limit exceeded"), amount(amount), limit(limit){
         message = "TransactionLimitExceededException: Attempted Rs." +
                  to_string(amount) + ", Daily Limit Rs." +
                  to_string(limit);
    }
    const char* what() const noexcept override{
        return message.c_str();
    }
};

class BankSystemException : public runtime_error{
    string component;
    string error;
    string message;
    public:
    BankSystemException(const std::string& component, const std::string& error): std::runtime_error("Bank system error"), component(component), error(error){
         message = "BankSystemException: Component [" + component +
                  "] Error: " + error;
    }
    const char* what() const noexcept override{
        return message.c_str();
    }
};

class BankAccount{
    private:
        string accountNumber;
        string holderName;
        double balance;
        double dailyWithdrawalLimit;
        double dailyWithdrawn;
        void validateAmount(double amount, const string& operation) const {
        if (amount <= 0)
            throw InvalidAmountException(amount, operation);

        if (isnan(amount) || isinf(amount))
            throw invalid_argument("Invalid numeric value.");
    }
    public:
    BankAccount(const string& accNo,
                const string& name,
                double initialBalance)
        : accountNumber(accNo),
          holderName(name),
          balance(initialBalance),
          dailyWithdrawalLimit(50000),
          dailyWithdrawn(0)
    {
        if (accNo.empty() || name.empty())
            throw invalid_argument("Account details cannot be empty.");

        if (initialBalance < 0)
            throw InvalidAmountException(initialBalance, "initial balance");
    }

    void deposit(double amount) {
        validateAmount(amount, "deposit");

        if (amount > 1000000)
            throw BankSystemException("Verification System",
                                      "Large deposit requires verification.");

        balance += amount;
    }

    void withdraw(double amount) {
        validateAmount(amount, "withdraw");

        if (amount > balance)
            throw InsufficientFundsException(accountNumber, balance, amount);

        if (dailyWithdrawn + amount > dailyWithdrawalLimit)
            throw TransactionLimitExceededException(amount, dailyWithdrawalLimit);

        if (amount > 100000)
            throw BankSystemException("Fraud Detection",
                                      "Large withdrawal detected.");

        balance -= amount;
        dailyWithdrawn += amount;
    }

    void transferTo(BankAccount& recipient, double amount) {
        validateAmount(amount, "transfer");

        if (this == &recipient)
            throw logic_error("Self-transfer not allowed.");

        if (amount > balance)
            throw InsufficientFundsException(accountNumber, balance, amount);

        withdraw(amount);
        recipient.deposit(amount);
    }

    void printAccountInfo() const {
        cout << "\nAccount: " << accountNumber
             << "\nHolder: " << holderName
             << "\nBalance: Rs." << balance
             << "\nDaily Limit: Rs." << dailyWithdrawalLimit
             << "\nWithdrawn Today: Rs." << dailyWithdrawn
             << "\nAvailable Today: Rs." 
             << (dailyWithdrawalLimit - dailyWithdrawn)
             << "\n---------------------------\n";
    }

    string getAccountNumber() const { return accountNumber; }
    
};
int main(){
     try {

        // Successful operations
        BankAccount acc1("1001", "Alice", 200000);
        BankAccount acc2("1002", "Bob", 50000);

        acc1.deposit(10000);
        acc1.withdraw(20000);
        acc1.transferTo(acc2, 10000);

        acc1.printAccountInfo();
        acc2.printAccountInfo();

        // Duplicate account simulation
        throw logic_error("Duplicate account creation.");

    }
    catch (const InsufficientFundsException& e) {
        cout << e.what() << endl;
    }
    catch (const InvalidAmountException& e) {
        cout << e.what() << endl;
    }
    catch (const AccountNotFoundException& e) {
        cout << e.what() << endl;
    }
    catch (const TransactionLimitExceededException& e) {
        cout << e.what() << endl;
    }
    catch (const BankSystemException& e) {
        cout << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << "Out_of_range: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Invalid_argument: " << e.what() << endl;
    }
    catch (const logic_error& e) {
        cout << "Logic_error: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cout << "Runtime_error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Standard exception: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unknown exception caught!" << endl;
    }

    return 0;
}