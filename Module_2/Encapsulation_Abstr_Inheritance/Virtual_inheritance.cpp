#include<iostream>
using namespace std;

class Device{
    protected:
    int id;
    string name;
    public:
    Device(int id, string name){
        this->id = id;
        this->name = name;
        cout<<"In Device constructor"<<endl;
    }
};

class Phone : virtual public Device{
    protected:
    int phone_model;
    public:

    Phone(int id, string name, int phone_m) :Device(id,name){
        this->phone_model = phone_m;
        cout<<"In Phone constructor"<<endl;
    }
};

class Camera : virtual public Device{
    int camera_a;
    public:
    Camera(int id, string name, int cam) : Device(id,name) {
        this->camera_a = cam;
        cout<<"In Camera constructor"<<endl;
    }
};

class SmartPhone : public Phone, public Camera{
    int model;
    public:
    SmartPhone(int id, string name, int phone_model, int cam, int model)
        : Device(id, name),   //virtual base constructed here
          Phone(id,name,phone_model),
          Camera(id,name,cam){
        this->model = model;
        cout<<"In smartphone constructor"<<endl;
    }
};

int main(){
    SmartPhone d(21,"Oppo", 21, 52,7);

}