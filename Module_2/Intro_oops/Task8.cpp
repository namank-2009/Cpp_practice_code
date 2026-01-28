#include<iostream>
using namespace std;

class Box{
    int length;
    int breadth;
    int height;
    public:
   
    void setDimensions(int l, int b, int h){
        this->length = l;
        this->breadth = b;
        this->height = h;
    }

    Box compareVolume(const Box& b){
        int thisVolume = this->length * this->breadth * this->height;
        int otherVolume = b.length * b.breadth * b.height;

        if (thisVolume >= otherVolume)
            return *this; // return calling object
        else
            return b; 
    }
    void printDimensions() {
        cout << "Length = " << length
             << ", Breadth = " << breadth
             << ", Height = " << height
             << ", Volume = " << length * breadth * height << endl;
    }
};

int main(){
    Box b1;
    b1.setDimensions(2,3,4);
    Box b2;
    b2.setDimensions(3,4,5);

    cout << "Box 1: ";
    b1.printDimensions();
    cout << "Box 2: ";
    b2.printDimensions();

    Box largerBox = b1.compareVolume(b2);
    cout << "\nLarger Box: ";
    largerBox.printDimensions();
}