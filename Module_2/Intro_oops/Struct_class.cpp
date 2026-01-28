#include<iostream>
using namespace std;

/*
  STRUCT:
  In C++, members of a struct are PUBLIC by default.
  This means x and y can be accessed directly from outside the struct.
*/
// Defining point struct
struct Point{
    //Public member 
    int x;
    int y;
};

/*
  CLASS:
  In C++, members of a class are PRIVATE by default.
  This means length and width cannot be accessed directly
  from outside the class.
*/
// Defining rectangle class
class Rectangle{
    // Private members are defined
    int length;
    int width;
    //Public member functions are defined
 public:
    // Function to set private values
    void setDimensions(int l, int w){
        length = l;
        width = w;
    }
    void print(){
        cout<<"The length = "<<length<<endl;
        cout<<"The width = "<<width<<endl;
    }
};


int main(){
    Point p;
    p.x = 10;      // direct access allowed
    p.y = 20;
    cout<<"Output of Point Struct"<<endl;
    cout << "Point x = " << p.x << endl;
    cout << "Point y = " << p.y << endl;

    // Accessing rectangle class
    cout<<"Output of Rectangle class"<<endl;
    Rectangle r;
    r.setDimensions(10,20);
    r.print();
    return 0;
}