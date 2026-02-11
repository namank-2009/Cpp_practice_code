#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class shape{
    public:
    virtual double area() const = 0;
    virtual string name() const = 0;
    virtual ~shape(){}
};

class Circle : public shape{
    double radius;

public:
    Circle(double r) {
        radius = r;
    }
    string name() const override {
        return "Circle";
    }
    double area() const override {
        return M_PI  * radius * radius;
    }
};

class Rectangle : public shape{
    double length, width;
public:
    string name() const override {
    return "Rectangle";
    }
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double area() const override {
        return length * width;
    }
};

class Triangle : public shape {
    double base,height;
public:
    string name() const override {
    return "Triangle";
    }
    Triangle(double x, double y) {
        base = x;
        height = y;
    }

    double area() const override {
      return 0.5*base*height;
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
