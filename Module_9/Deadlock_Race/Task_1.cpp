#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>

std::mutex m1, m2;

void FirstLock(){
    // Locked m1
    m1.lock();
    std::cout<<"Locked m1"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    // Here we will see the thread will keep waiting for m2 but thread 2 has already locked so it will cause deadlock
    m2.lock();
    std::cout<<"Locked m2"<<std::endl;
    m2.unlock();
    m1.unlock();
}

void SecondLock(){
    m2.lock();
    std::cout<<"Locked m2"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    // Here we will see the thread will keep waiting for m1 but thread 1 has already locked so it will cause deadlock
    m1.lock();
    std::cout<<"Locked m1"<<std::endl;
    m1.unlock();
    m2.unlock();
}

int main(){
    std::thread t1(FirstLock);
    std::thread t2(SecondLock);
    t1.join();
    t2.join();
    return 0;
}
