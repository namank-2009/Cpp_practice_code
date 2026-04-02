#include<iostream>
#include<thread>

using namespace std;

int counter = 0;

// Shared resource (not thread-safe)
// Multiple threads will modify this simultaneously → race condition
void increment(){
    for(int i = 0; i < 1000; i++){
        counter++;  // Not atomic → causes race condition
    }
}

int main(){

    thread t1(increment);
    thread t2(increment);
    thread t3(increment);
    thread t4(increment);

    // Wait for all threads to finish
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    // Expected = 4000
    // Actual = less than 4000 due to race condition
    cout << "Counter value: " << counter << endl;

    return 0;
}