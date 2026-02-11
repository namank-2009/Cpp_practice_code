#include<iostream>
using namespace std;

// We have made a base class device which has id as protected member
// We have its constructor to initialise the id
// We have also made showId function to display the id
class Device{
    protected:
    int id;
    public:
    Device(int id){
        this->id = id;
    }

    void showID(){
        cout<<"The id is = "<<id<<endl;
    }
};

// Phone inherited the device but it should be inherited virtually
class Phone: virtual public Device{
    public:
    Phone(int id) : Device(id){}
};

// Camera inherited the device but it should be inherited virtually
class Camera: virtual public Device{
    public:
    Camera(int id) : Device(id){}
};

// Smartphone inherited the Phone and camera 
class Smartphone : public Phone, public Camera{
    public:
    Smartphone(int id) :Device(id), Phone(id), Camera(id){}
};

int main(){
    // Created the object of smartphone which is the derived class
    Smartphone sp(23);
    // As of now we are not inheriting the base class device virtually which cause the problem that 
    // it becomes ambiguous for compiler to know which function should be called like from phone->device or camera->device
    // so it is an ambiguity and diamond problem in multiple inheritance
    sp.showID();
}