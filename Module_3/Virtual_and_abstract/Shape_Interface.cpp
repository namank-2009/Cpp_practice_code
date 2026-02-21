#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class shape{
    public:
    shape(){
        cout<<"Shape constructor";
    }
    virtual double area() const = 0;
    virtual double perimeter() const= 0;
    virtual string name() const = 0;
    virtual ~shape(){
        cout<<"Shape destroyed\n";
    }
};

class Circle : public shape{
    double radius;

public:
    Circle(double r) {
        radius = r;
        cout<<"Circle constructor";
    }
    string name() const override {
    return "Circle";
    }
    double area() const override {
        return M_PI  * radius * radius;
    }
    double perimeter() const override{
        return 2*M_PI*radius;
    }

    ~Circle(){
        cout<<"Circle destroyed\n";
    }
};

class Rectangle : public shape{
    double length, width;
public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
        cout<<"Rectangle constructor\n";
    }

    string name() const override {
    return "Rectangle";
    }
    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }

    ~Rectangle(){
        cout<<"Rectangle destroyed\n";
    }
};

class Triangle : public shape {
    double base , height;

public:
    string name() const override {
    return "Triangle";
    }
    Triangle(double x, double y) {
        base = x;
        height = y;
        cout<<"Triangle Constructor"<<endl;
    }

    double area() const override {
      return 0.5*base*height;
    }

    double perimeter() const override {
        return base+height ;
    }

    ~Triangle(){
        cout<<"Triangle destroyed\n";
    }
};

int main(){
       vector<shape*> shapes;

    // Creating objects and storing them polymorphically
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));
    shapes.push_back(new Triangle(3, 4));


    // Polymorphic calls
    for (const auto& s : shapes) {
        cout << "Shape: " << s->name() << endl;
        cout << "Area: " << s->area() << endl;
        cout << "-------------------" << endl;
    }   
    
    for(const auto s:shapes){
        delete s;
    }
    return 0;
}
