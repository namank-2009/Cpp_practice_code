// #include<iostream>
// using namespace std;

// class Animal{
//     public:
//     virtual ~Animal(){};
//     virtual void Speaks() const{
//         cout<<"Animal speaks"<<endl;
//     }
// };

// class Dog:public Animal{
//     public:
//     void Speaks() const override{
//         cout<<"Dog barks"<<endl;
//     }
// };

// class Cat:public Animal{
//     public:
//     void Speaks() const override{
//         cout<<"Cat meaows"<<endl;
//     }
// };

// int main(){
//     Animal* a = new Dog();
//     Dog* d = dynamic_cast<Dog*>(a);

//     if(d!=nullptr){
//         d->Speaks();
//     }
//     else{
//         cout<<"Fails"<<endl;
//     }

//     Cat* c  = dynamic_cast<Cat*>(a);

//     if(c!=nullptr){
//         c->Speaks();
//     }
//     else{
//         cout<<"Fails"<<endl;
//     }
// }

#include <iostream>
#include <typeinfo>

class Animal {
public:
    virtual ~Animal() {} // Required for RTTI/dynamic_cast
    virtual void speak() const { std::cout << "Animal speaks\n"; }
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << "Woof!\n"; }
    void fetch() const { std::cout << "Dog fetching...\n"; }
};

class Cat : public Animal {
public:
    void speak() const override { std::cout << "Meow!\n"; }
    void scratch() const { std::cout << "Cat scratching...\n"; }
};

void identifyAnimal(Animal* a) {
    // typeid: Prints dynamic type
    std::cout << "typeid: " << typeid(*a).name() << std::endl;
    // dynamic_cast to test/convert safely
    if (Dog* dog = dynamic_cast<Dog*>(a)) {
        dog->fetch();
    } else if (Cat* cat = dynamic_cast<Cat*>(a)) {
        cat->scratch();
    } else {
        std::cout << "Unknown animal." << std::endl;
    }
}

int main() {
    Animal* animals[2] = { new Dog(), new Cat() };
    for (Animal* a : animals) {
        a->speak();
        identifyAnimal(a);
    }
    // Clean up
    for (Animal* a : animals) delete a;

    /*
    - Use typeid to simply query/display an object's dynamic type at runtime.
    - Use dynamic_cast to safely downcast and access derived-class-specific methods or fields.
    - If RTTI is disabled (e.g. with -fno-rtti), typeid and dynamic_cast won't work for polymorphic types and may result in compile or runtime errors.
    - dynamic_cast returns nullptr (for pointers) when the cast fails.
    - Never use static_cast for polymorphic downcasts unless you're 100% sure of the type.
    */
    return 0;
}
