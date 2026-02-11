#include<iostream>
using namespace std;

// We have made a base class device 
class Device{
    public:
    int id;
    // Constructor for Device
    Device(int id){
        this->id = id;
       cout<<"Device Constructor and id is "<<id<<endl;
    }
    virtual ~Device(){
        cout<<"Device Destructor"<<endl;
    }
};

// Phone inherited the device virtually
class Phone: virtual public Device{
    public:
    // Constructor for Phone
    Phone(int id) : Device(id){
        cout<<"Phone Constructor"<<endl;
    }
    ~Phone(){
        cout<<"Phone Destructor"<<endl;
    }
};

// Camera inherited the device virtually
class Camera: virtual public Device{
    public:
    // Constructor for Camera
    Camera(int id):Device(id){
        cout<<"Camera Constructor"<<endl;
    }
    ~Camera(){
        cout<<"Camera Destructor"<<endl;
    }
};

// Smartphone inherited the Phone and camera 
class Smartphone : public Phone, public Camera{
    public:
    // Constructor for Smartphone
    Smartphone(int id):Device(id),Phone(id),Camera(id){
        cout<<"SmartPhone Constructor"<<endl;
    }

    ~Smartphone(){
        cout<<"Smartphone Destructor"<<endl;
    }
};

int main(){
    // Created the object of smartphone 
    Smartphone sp(221);
    // The constructor of base class is called first
    // Device->Phone->Camera->SmartPhone
    //Then the constructor of the derived class are called

    // but in destructor the destructor of derived class are called first then at last the base class destructor is called
}