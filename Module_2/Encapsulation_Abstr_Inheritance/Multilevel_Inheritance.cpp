#include<iostream>
using namespace std;

// Vehicle base class
class Vehicle{
    protected:
    string make;
    string model;
     public:
    Vehicle(string make, string model){
        this->make =make;
        this->model = model;
        cout<<"Constructor of vechicle class is called"<<endl;
    }

};

// Car class inherits Vechicle class
class Car: public Vehicle{
    protected:
    int add_doors;
     public:
    Car(string make, string model, int doors) : Vehicle(make, model){
        this->add_doors = doors;
        cout<<"Constructor of Car class is called"<<endl;
    }
};

// Electric car class inherits Car class
class Electric_Cars: public Car{

    double batterCapacity;
    public:
    Electric_Cars(string make, string model, int doors, double batteryCapacity) : Car(make, model, doors) {
        this->batterCapacity = 12;
    cout<<"Constructor of Electric Cars class is called"<<endl;
    }
};



int main(){
    Electric_Cars ec("Tesla", "Model 3", 4, 75.0);
    // When we make the object of the derived we can see that the base class constructor is called first beacuse the derived class
}