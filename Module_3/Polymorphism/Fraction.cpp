#include<iostream>
using namespace std;

class Fraction{
    private:
    int numerator;
    int denominator;
    public:
    Fraction(int n=0, int d=1){
         if (d == 0) {
            cout << "Denominator cannot be zero. Setting to 1.\n";
            d = 1;
        }
        this->numerator = n;
        this->denominator = d;
    }

     // Overload == operator
    bool operator==(const Fraction& other) const {
        // Cross multiplication
        return numerator * other.denominator ==
               other.numerator * denominator;
    }

    // Overload < operator
    bool operator<(const Fraction& other) const {
        // Cross multiplication
        return numerator * other.denominator <
               other.numerator * denominator;
    }

    // For displaying the fraction
    void print() const {
        cout << numerator << "/" << denominator;
    }
};


int main(){
   Fraction f1(1, 2);
    Fraction f2(2, 4);
    Fraction f3(1, 3);

    cout << "Comparing ";
    f1.print();
    cout << " and ";
    f2.print();
    cout << endl;

    if (f1 == f2)
        cout << "They are equal\n";
    else
        cout << "They are not equal\n";

    cout << "\nComparing ";
    f3.print();
    cout << " and ";
    f1.print();
    cout << endl;

    if (f3 < f1)
        cout << "1/3 is less than 1/2\n";
    else
        cout << "1/3 is not less than 1/2\n";

    return 0;
}