#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex m1, m2, m3;

void deadlock_thread1(){
    cout << "T1 locking m1\n";
    m1.lock();

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "T1 locking m2\n";
    m2.lock();

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "T1 locking m3\n";
    m3.lock();
}

void deadlock_thread2(){
    cout << "T2 locking m2\n";
    m2.lock();

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "T2 locking m3\n";
    m3.lock();

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "T2 locking m1\n";
    m1.lock();
}

void deadlock_thread3(){
    cout << "T3 locking m3\n";
    m3.lock();

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "T3 locking m1\n";
    m1.lock();

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "T3 locking m2\n";
    m2.lock();
}

void safe_thread(int id){
    cout << "Thread " << id << " trying to lock\n";

    // Deadlock-free locking
    scoped_lock lock(m1, m2, m3);

    cout << "Thread " << id << " acquired all locks\n";

    this_thread::sleep_for(chrono::milliseconds(200));

    cout << "Thread " << id << " releasing locks\n";
}

int main(){

    cout << "----- Deadlock Demonstration -----\n";

    thread t1(deadlock_thread1);
    thread t2(deadlock_thread2);
    thread t3(deadlock_thread3);

    // Uncomment below to SEE deadlock (program will hang)
    // t1.join(); t2.join(); t3.join();

    this_thread::sleep_for(chrono::seconds(2));
    cout << "\nDeadlock occurred (threads stuck)\n\n";

    cout << "----- Deadlock-Free Version -----\n";

    thread s1(safe_thread, 1);
    thread s2(safe_thread, 2);
    thread s3(safe_thread, 3);

    s1.join();
    s2.join();
    s3.join();

    cout << "Execution completed successfully\n";

    return 0;
}