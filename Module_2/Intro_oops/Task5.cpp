#include<iostream>
using namespace std;

class DynamicArray{
    int id;
    int size;
    int* data;

    public:
    DynamicArray(int id, int s=5){
        this->id = id;
        size = s;
        data = new int[size];
        cout<<"Default constructor called for id "<<id<<endl;
    }

    ~DynamicArray(){
        delete []data;
        cout<<"Destructor called for id = "<<id<<endl;
    }
};

void demoDestructors(){
    cout<<"Enter demo destructor"<<endl;

    DynamicArray arr[3] = {
        DynamicArray(1),
        DynamicArray(2),
        DynamicArray(3)
    };

    cout<<"Exiting destructor"<<endl;
}
int main(){

    cout<<"Program started"<<endl;
    demoDestructors();
    cout<<"Program ended"<<endl;
}