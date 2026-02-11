#include<iostream>
using namespace std;

class Complex{
    double real;
    double img;

    public:
        Complex(double real =0, double img = 0){
            this->real = real;
            this->img = img;
        }
        double getReal() const { return real; }
        double getImag() const { return img; }

        // overloaded + operator
        Complex operator+(const Complex obj){
            return Complex(this->real + obj.real, this->img + obj.img);
        }
};

// Overloaded << operator 
ostream& operator<<(ostream& out, const Complex& obj) {
    out << obj.getReal();
    if (obj.getImag() >= 0)
        out << " + " << obj.getImag() << "i";
    else
        out << " - " << -obj.getImag() << "i";
    return out;
}

int main(){ 

    Complex c1(2.5, 4.5);
    Complex c2(3.5, -1.5);

    // Calling the overloaded + operator
    Complex c3 = c1 + c2;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    // Here the cout is taken as operator<<(cout,c3)
     cout << "Result of c1 + c2 = c3: " << c3 << endl;

     
}