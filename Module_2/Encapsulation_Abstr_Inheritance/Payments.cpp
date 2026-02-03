#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Payments{
    public:
    virtual void processPayment(double amount) = 0;
    virtual ~Payments(){}
};

class CreditCardPayment:public Payments{
    public:
    void processPayment(double amount) override{
        cout << "Processing credit card payment of ₹" << amount << endl;
    }
};

class PayPalPayment:public Payments{
    public:
    void processPayment(double amount) override{
         cout << "Processing PayPal payment of ₹"<< amount << endl;
    }
};

int main(){
    vector<unique_ptr<Payments>> payments;

    // Creating different payment methods
    payments.push_back(make_unique<CreditCardPayment>());
    payments.push_back(make_unique<PayPalPayment>());

    /*
        Client code ONLY knows about Payment interface.
        It does not care how the payment is processed.
    */
    for (const auto& payment : payments) {
        payment->processPayment(1500.0);
    }

    // No delete required — unique_ptr handles cleanup
    return 0;
}