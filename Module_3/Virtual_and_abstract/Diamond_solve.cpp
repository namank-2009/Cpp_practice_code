#include<iostream>
using namespace std;

class Device {
public:
    int id;

    Device() : id(0) {}

    void showId() const {
        std::cout << "Device ID: " << id << '\n';
    }
};

// Virtual inheritance
class Phone : virtual public Device {
};

class Camera : virtual public Device {
};

// Diamond resolved here
class Smartphone : public Phone, public Camera {
};

int main(){
    // Created the object of smartphone which is the derived class
    Smartphone sp;
    sp.id = 202;
    sp.showId();

    // Access Device subobject via different inheritance paths
    Device* viaPhone  = static_cast<Device*>(static_cast<Phone*>(&sp));
    Device* viaCamera = static_cast<Device*>(static_cast<Camera*>(&sp));

    std::cout << "Device address via Phone:  " << viaPhone << '\n';
    std::cout << "Device address via Camera: " << viaCamera << '\n';

    if (viaPhone == viaCamera) {
        std::cout << "Confirmed: Only ONE Device subobject exists.\n";
    }

    return 0;
}