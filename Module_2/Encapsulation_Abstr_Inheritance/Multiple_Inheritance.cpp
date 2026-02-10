#include<iostream>
using namespace std;

// Printable with print as pure virtual function
class Printable{
    public:
    virtual void print() const = 0;
    virtual ~Printable() {}   // Virtual destructor
};

//Savable class with save as pure virtual function
class Savable{
    public:
    virtual void save() const = 0;
    virtual ~Savable() {}
};

// Document class inheriting printable and savable representing multiple inheritance
class Document: public Printable, public Savable{
   public:
    void print() const override{
        cout<<"We are printing the document"<<endl;
    }

    void save() const override {
        cout<<"We are saving the document"<<endl;
    }
};

int main(){
    Document dd;
    // Polymorphic usage through interface pointers
    Printable* p = &dd;
    Savable* s = &dd;

    p->print();   // Calls Document::print()
    s->save();    // Calls Document::save()
}