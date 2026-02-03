#include<iostream>
using namespace std;

//   The internal data (celsius) is kept private to prevent
//   direct modification from outside the class.
//   Access to the data is provided only through controlled
//   public methods (getters and setters).

class Temperature{
    private:
    double celsius;

    public:
     // Constructor to ensure safe initial state
    Temperature() {
        celsius = 0.0;
    }

    // Function to set the value of celsius which is a private member
    bool setCelsius(double temp){
        if(temp >= -273.15){
            celsius = temp;
            return true;
        }
        else{
            cout<<"Error: Temperature cannot be below absolute zero (-273.15°C)"<<endl;
            return false;
        }
    }

    // Member function to return the celsius value
    double getCelsius(){
        cout<<"The temperature in celsius = "<<celsius<<endl;
        return celsius;
    }

    // Member function to convert the celsius value to farenheit
    double getFahrenheit(){
        double fahrenheit = celsius*9/5+32;
        cout<<"The temperature in farenheit is = "<<fahrenheit<<endl;
        return fahrenheit;
    }
};

int main(){
    // Valid temperature object
    Temperature temp;
    if (temp.setCelsius(20)) {
        cout << "Celsius: " << temp.getCelsius() << endl;
        cout << "Fahrenheit: " << temp.getFahrenheit() << endl;
    }

    cout << endl;

    // Invalid temperature object
    Temperature temp2;
    temp2.setCelsius(-300);   // rejected

    cout << "Celsius after invalid input: " << temp2.getCelsius() << endl;
    cout << "Fahrenheit: " << temp2.getFahrenheit() << endl;
}