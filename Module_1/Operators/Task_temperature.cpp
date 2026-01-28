#include<iostream>
using namespace std;

int main(){
    /* Temperature in fahrenheit it is stored in temperatureInFahrenheit variable which is of float data type*/
    float temperatureInFahrenheit = 37;

    /* Convert the fahrenheit temperature into Celsius  it is stored in temperatureInCelsius variable which is of float data type because due to calculation the value can even be in decimals*/
    float temperatureInCelsius = (temperatureInFahrenheit-32)*5 / 9;

    /*Printing the temperature in both fahrenheit and Celsius*/
    cout<<"Temperature in fahrenheit is "<< temperatureInFahrenheit<<" °F"<<endl;
    cout<<"Temperature in Celsius is "<< temperatureInCelsius<<" °C"<<endl;
    return 0;
}