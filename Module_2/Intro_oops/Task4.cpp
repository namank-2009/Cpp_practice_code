#include<iostream>
using namespace std;

class DynamicArray{
    int* data;
    int size;
    public:

    DynamicArray(int s=5){
        size = s;
        data = new int[size];
        for(int i=0; i<size; i++){
            data[i] = i+1;
        }
        cout<<"Memory allocated in default constructor"<<endl;
    }

    DynamicArray(const DynamicArray& other){
        size = other.size;
        data = new int[size];
        for(int i=0; i<size; i++){
            data[i] = other.data[i];
        }
         cout<<"Memory allocated in copy constructor"<<endl;
    }

    ~DynamicArray(){
        delete[] data;
        cout<<"Memory deallocated(Destructor)"<<endl;        
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    DynamicArray arr;
    arr.display();

    //Copy Constructor
    DynamicArray arr1 = arr;
    arr1.display();
    return 0;
}