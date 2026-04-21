#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int counter = 0;
mutex m;
void increment(){
    for(int i=0; i<1000; i++){
        // Lock guard help to automatically lock and unlock the mutex
        // So only one thread can increment the counter value at a time.
        lock_guard<mutex>lock(m);
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

    cout<<"The actual value of counter is "<<counter<<endl;
    return 0;
}