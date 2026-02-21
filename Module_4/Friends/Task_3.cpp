#include<iostream>
#include<cmath>
using namespace std;

class Circle; 
class Rectangle{
    private:
    double length;
    double width;
    public:
    Rectangle(double l, double w){
        length = l;
        width = w;
    }
    friend double compareArea(const Rectangle& r, const Circle& c);
};

class Circle{
    private:
    double radius;
    public:
    Circle(double r){
        radius = r;
    }
    friend double compareArea(const Rectangle& r, const Circle& c);
};

double compareArea(const Rectangle& r, const Circle& c){
    cout<<"Length and width of Rectangle: "<<endl;
    cout<<"Length: "<<r.length<<" Width: "<<r.width<<endl;
    double rec_area = r.length*r.width;
    cout<<"The area of rectangle: "<<rec_area<<endl;

    cout<<"Radius of Circle"<<endl;
    cout<<"Radius: "<<c.radius<<endl;
    double cir_area = M_PI*c.radius*c.radius;
    cout<<"The area of Circle: "<<cir_area<<endl;

    if(cir_area>rec_area){
        cout<<"Circle area is greater"<<endl;
    }
    else if (rec_area > cir_area) {
        cout << "Rectangle area is greater." << endl;
    } else {
        cout << "Both areas are equal." << endl;
    }

    return cir_area - rec_area;   
}

int main(){
    Rectangle r(2,4);
    Circle c(5);
    double difference = compareArea(r, c);

    cout << "Area Difference: " << difference << endl;
}