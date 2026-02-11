#include<iostream>
using namespace std;

class Printer{
    public:
    // Virtual function with a default parameter
    virtual void print(const std::string& msg = "Base Printer"){
        cout << "Printer prints: " << msg << endl;
    }

    virtual ~Printer() {} // Virtual destructor
};

class ColorPrinter : public Printer{
    public:
    // Virtual function with a default parameter
    void print(const std::string& msg = "Color Printer") override{
        cout << "ColorPrinter prints: " << msg << endl;
    }
};

int main(){
    // Direct call on derived object
    ColorPrinter cp;
    cp.print();

     // Call via base class pointer
    Printer* p = &cp;
    p->print();

//Default arguments = compile-time (depends on pointer/reference type)

// Virtual function = run-time (depends on actual object)

// Never change default arguments in derived classes when overriding virtual functions. It will confuse people (and your program!).
}