#include<iostream>
using namespace std;

class LeakDemo{
    public:
    LeakDemo(){
        cout<<"Constructor is called"<<endl;
    }
    ~LeakDemo(){
        cout<<"Destructor is called"<<endl;
    }
};

int main(){
   for (int i = 0; i < 1000; i++) {
        LeakDemo* obj = new LeakDemo;
        // delete obj;  // Intentionally omitted to create memory leak
     delete obj; //  Proper deallocation
    }

    return 0;
}