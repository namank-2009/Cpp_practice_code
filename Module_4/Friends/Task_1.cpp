#include<iostream>
using namespace std;

// Box class with length, width, height
class Box{
    private:
    double length;
    double width;
    double height;

    public:
    // Parameterized constructor
    Box(double l, double b, double h){
        length = l;
        width = b;
        height = h;
    }

    // Setting up the friend function
    friend double volume(const Box& b);
};

// Friend function declared outside the class
// Function accesing private member of box class
double volume(const Box& b){
    cout<<"Length: "<<b.length<<endl;
    cout<<"Width: "<<b.width<<endl;
    cout<<"Height: "<<b.height<<endl;
    // Calculating the volume
    double vol = b.length*b.width*b.height;
    cout<<"Volume = "<<vol<<endl;

    return vol;
}

int main(){
    Box b(3,4,5);
    // Calling the friend function
    double v = volume(b);
    return 0;
}