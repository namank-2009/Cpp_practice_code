#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int counter = 0;

void increment(){
    for(int i=0; i<1000; i++){
        counter++;
    }
}

int main(){
    cout<<"Initial value of counter "<<counter<<endl;
    cout<<"Expected value of counter is 5000"<<endl;
    thread t1(increment);
    thread t2(increment);
    thread t3(increment);
    thread t4(increment);
    thread t5(increment);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

// The expected value is 5000 but the value we get is different due to race condition
// Two threads incremented the value at the same time and it cause such problem so the value is less than 5000
    cout<<"The actual value of counter is "<<counter<<endl;
    return 0;
}