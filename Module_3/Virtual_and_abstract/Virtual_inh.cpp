#include<iostream>
using namespace std;

class LivingBeing{
    public:
    int id;
    string name;
    void show(){
        cout<<"The id is "<<id<<endl;
        cout<<"The name is "<<name<<endl;
        cout <<"Address of this: " << this << endl;
    }
    virtual ~LivingBeing(){};
};

class Animal: virtual public LivingBeing{

};

class Plant : virtual public LivingBeing{

};

class Hybrid : public Animal, public Plant{
    public:
    Hybrid(int i, const string& n) {
        id = i;
        name = n;  // single LivingBeing instance, thanks to virtual inheritance
    }
};

int main(){
    Hybrid hb(109,"Chimera");

    cout << "--- Access via Hybrid object directly ---" << endl;
    hb.show();

    cout << "\n--- Access via Animal path ---" << endl;
    Animal* aPtr = &hb;
    aPtr->show();  // still refers to the same LivingBeing

    cout << "\n--- Access via Plant path ---" << endl;
    Plant* pPtr = &hb;
    pPtr->show();  // same LivingBeing instance

    cout << "\n--- Confirm addsresses of LivingBeing via different paths ---" << endl;
    cout << "Address via Animal*: " << static_cast<LivingBeing*>(aPtr) << endl;
    cout << "Address via Plant*: " << static_cast<LivingBeing*>(pPtr) << endl;
    cout << "Address via Hybrid: " << static_cast<LivingBeing*>(&hb) << endl;
}   