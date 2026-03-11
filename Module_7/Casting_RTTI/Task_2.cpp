#include<iostream>
#include<typeinfo>
using namespace std;

class Shape{
    public:
    virtual ~Shape(){};
    virtual void draw() const {
        std::cout << "Drawing Shape\n"; 
    }
};

class Circle:public Shape{
    public:
    void draw() const override{
        std::cout << "Drawing Circle\n"; 
    }

    void circleSpecific() const{
        std::cout << "Circle-specific method\n";
    }
};

class Rectangle:public Shape{
public:
    void draw() const override { 
        std::cout << "Drawing Rectangle\n"; 
    }
    void rectangleSpecific() const { 
        std::cout << "Rectangle-specific method\n";
    }
};

int main() {
    Shape* s = new Circle();

    std::cout << "--- static_cast ---\n";
    Circle* c1 = static_cast<Circle*>(s); // No check, assumes correct type!
    if (c1) {
        c1->circleSpecific();
    }

    // Rectangle* c1 = static_cast<Rectangle*>(s); // This will fail as it is not of correct type as object is of circle class but we are trying it for another deriveed class i.e. rectangle
    // if (c1) {
    //     c1->circleSpecific();
    // }
    // Now, demonstrate bad static_cast (if type is wrong):
    Shape* s2 = new Rectangle();
    // Circle* c2 = static_cast<Circle*>(s2); // This is UNDEFINED BEHAVIOR if called!
    // Uncommenting the next two lines would cause errors or crashes if you wrongly cast:
    // c2->circleSpecific();

    std::cout << "--- dynamic_cast ---\n";
    Circle* c3 = dynamic_cast<Circle*>(s); // Succeeds because s actually points to a Circle
    if (c3) {
        c3->circleSpecific();
        std::cout << "dynamic_cast to Circle* succeeded.\n";
    } else {
        std::cout << "dynamic_cast to Circle* failed.\n";
    }

    Rectangle* r = dynamic_cast<Rectangle*>(s); // Fails
    if (r) {
        r->rectangleSpecific();
    } else {
        std::cout << "dynamic_cast to Rectangle* failed (nullptr)\n";
    }

    delete s;
    delete s2;

    /*
    static_cast blindly converts, and is UNDEFINED BEHAVIOR unless you know s points to the correct type.
    dynamic_cast checks types at runtime (for polymorphic hierarchies) and returns nullptr on failure.

    Use dynamic_cast for safe downcasting in polymorphic hierarchies when type safety matters.
    */

    return 0;
}