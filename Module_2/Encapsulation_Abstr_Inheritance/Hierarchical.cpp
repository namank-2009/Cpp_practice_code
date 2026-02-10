#include <iostream>
using namespace std;

/*
 Base Class: Shape
 - Represents a general shape
 - Provides a common interface for all shapes
*/
class Shape {
protected:
    string shapeName;

public:
    Shape(string name) {
        shapeName = name;
    }

    void displayName() {
        cout << "Shape: " << shapeName << endl;
    }
};

/*
 Derived Class: Circle
*/
class Circle : public Shape {
    double radius;

public:
    Circle(double r) : Shape("Circle") {
        radius = r;
    }

    double area() {
        return 3.14159 * radius * radius;
    }

    double perimeter() {
        return 2 * 3.14159 * radius;
    }
};

/*
 Derived Class: Square
*/
class Square : public Shape {
    double side;

public:
    Square(double s) : Shape("Square") {
        side = s;
    }

    double area() {
        return side * side;
    }

    double perimeter() {
        return 4 * side;
    }
};

/*
 Derived Class: Rectangle
*/
class Rectangle : public Shape {
    double length;
    double width;

public:
    Rectangle(double l, double w) : Shape("Rectangle") {
        length = l;
        width = w;
    }

    double area() {
        return length * width;
    }

    double perimeter() {
        return 2 * (length + width);
    }
};

int main() {
    Circle c(5);
    Square s(4);
    Rectangle r(6, 3);

    c.displayName();
    cout << "Area: " << c.area() << endl;
    cout << "Perimeter: " << c.perimeter() << endl;
    cout << "-------------------" << endl;

    s.displayName();
    cout << "Area: " << s.area() << endl;
    cout << "Perimeter: " << s.perimeter() << endl;
    cout << "-------------------" << endl;

    r.displayName();
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;

    return 0;
}
