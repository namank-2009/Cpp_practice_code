#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>

using namespace std;

bool ready = false;
std::mutex m;
std::condition_variable cv;

void waiter(){
    unique_lock<mutex>lock(m);
    cout << "[Waiter] Waiting for signal...\n";
    // The cv waits and sleeps till the tym it get notified
    cv.wait(lock, [&]{ return ready; });
    cout << "[Waiter] Woke up! Condition met.\n";
}

void Signaler(){
    this_thread::sleep_for(std::chrono::milliseconds(2000));
    unique_lock<mutex> lock(m);
    ready = true;
    cout<<"Signaler sets ready and notifies,"<<endl;
    //Notifies that the value of ready is set
    cv.notify_one();
    cout << "[Signaler] Notified one thread\n";
}
int main(){
    thread t1(Signaler);
    thread t2(waiter);
    t1.join();
    t2.join();

    return 0;
}