#include<iostream>
#include<thread>
#include<atomic>

std::atomic<int> counter{0};

void increment(){
    for(int i=0; i<1000; i++){
        counter++;
    }
}

int main(){
    cout<<"Initial counter value: "<<counter<<endl;
    cout<<"Expected value counter: 5000"<<endl;

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

    cout<<"Final counter value: "<<counter<<endl;
}