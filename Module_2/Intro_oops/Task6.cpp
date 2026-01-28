#include<iostream>
using namespace std;

class Counter{
    static int count;
    public:
    Counter(){
        count++;
    }
    ~Counter(){
        count--;
    }
    static int getCount(){
        cout<<"Count = "<<count<<endl;
        return count;
    }
};

int Counter :: count =0;

int main(){
    Counter* c1 = new Counter();
    Counter* c2 = new Counter();

    Counter::getCount(); // Count = 2

    delete c2;
    Counter::getCount(); // Count = 1

    delete c1;
    Counter::getCount(); // Count =0
}
