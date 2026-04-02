#include<iostream>
#include<thread>
#include<mutex>

int counter = 0;
std::mutex m;

void increment(){
    for(int i = 0; i < 1000; i++){
        std::lock_guard<std::mutex> lock(m);  // Lock per iteration
        counter++;
    }
}

int main(){
    std::thread t1(increment);
    std::thread t2(increment);
    std::thread t3(increment);
    std::thread t4(increment);

    // Wait for all threads
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "The counter value is " << counter << std::endl;
}