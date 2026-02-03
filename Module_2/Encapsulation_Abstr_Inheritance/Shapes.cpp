#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class shape{
    public:
    virtual double area() const = 0;
    virtual double perimeter() const= 0;
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
    double perimeter() const override{
        return 2*M_PI*radius;
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

    double perimeter() const override {
        return 2 * (length + width);
    }

};

class Triangle : public shape {
    double a, b, c;

public:
    string name() const override {
    return "Triangle";
    }
    Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }

    double area() const override {
        double s = (a + b + c) / 2;   // semi-perimeter
        return sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
    }

    double perimeter() const override {
        return a + b + c;
    }
};

int main(){
     vector<unique_ptr<shape>> shapes;

        // Creating objects and storing them polymorphically
    shapes.push_back(make_unique<Circle>(5));
    shapes.push_back(make_unique<Rectangle>(4, 6));
    shapes.push_back(make_unique<Triangle>(3, 4, 5));


    // Polymorphic calls
    for (const auto& s : shapes) {
        cout << "Shape: " << s->name() << endl;
        cout << "Area: " << s->area() << endl;
        cout << "Perimeter: " << s->perimeter() << endl;
        cout << "-------------------" << endl;
    }   
    // No delete needed — unique_ptr handles memory automatically
    return 0;

}
