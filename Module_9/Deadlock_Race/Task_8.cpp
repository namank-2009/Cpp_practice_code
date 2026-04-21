#include<iostream>
#include<atomic>
#include<thread>
#include<atomic>

using namespace std;
volatile int counter = 0; //Not thread safe
atomic<int>count{0}; // thread safe

void increment_Volatile(){
    for(int i=0; i<1000; i++){
        counter++;
    }
}

void increment_Atomic(){
    for(int i=0; i<1000; i++){
        count++;
    }
}

int main(){
    cout<<"Volatile vs atomic"<<endl;
    // We will see the difference in actual and expected ouput when using volatile
    cout<<"Using Volatile counter";
    cout<<"Initial value of the counter "<<counter<<endl;
    cout<<"Expected value of counter is 5000"<<endl;
    thread t1(increment_Volatile);
    thread t2(increment_Volatile);
    thread t3(increment_Volatile);
    thread t4(increment_Volatile);
    thread t5(increment_Volatile);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    cout<<"Counter actual value using volatile: "<<counter;

    // We will see the values are same as expected in actual and expected ouput when using atomic
    cout<<"Using Atomic counter";
    cout<<"Initial value of the count "<<count<<endl;
    cout<<"Expected value of count is 5000"<<endl;
    thread t11(increment_Atomic);
    thread t21(increment_Atomic);
    thread t31(increment_Atomic);
    thread t41(increment_Atomic);
    thread t51(increment_Atomic);

    t11.join();
    t21.join();
    t31.join();
    t41.join();
    t51.join();

    cout<<"Count actual value using volatile: "<<count;
    return 0;
}