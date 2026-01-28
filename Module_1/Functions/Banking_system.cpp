#include <iostream>
using namespace std;

/* Global static variable to store balance */
static float balance = 0.0f;

/* Deposit Function */
void deposit(float amount) {
    if (amount <= 0) {
        cout << "Invalid amount! Deposit amount must be positive.\n";
        return;
    }
    balance += amount;
    cout << "Amount Deposited: ₹" << amount << endl;
    cout << "Updated Balance: ₹" << balance << endl;
}

/* Withdraw Function */
void withdraw(float amount) {
    if (amount <= 0) {
        cout << "Invalid amount! Withdrawal amount must be positive.\n";
        return;
    }
    if (amount > balance) {
        cout << "Insufficient funds! Current Balance: ₹" << balance << endl;
        return;
    }
    balance -= amount;
    cout << "Amount Withdrawn: ₹" << amount << endl;
    cout << "Updated Balance: ₹" << balance << endl;
}

/* Check Balance Function */
float checkBalance() {
    return balance;
}

/* Main Function */
int main() {
    int choice;
    float amount;

    do {
        cout << "\n------ Banking System Menu ------\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                withdraw(amount);
                break;

            case 3:
                cout << "Current Balance: ₹" << checkBalance() << endl;
                break;

            case 4:
                cout << "Thank you for using the Banking System. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please select a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}
