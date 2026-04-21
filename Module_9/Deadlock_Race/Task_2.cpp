#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex m1, m2;

// Function using std::lock 
void FirstLock() {
    cout << "Thread 1 trying to lock...\n";

    // Atomically locks both mutexes without deadlock
    lock(m1, m2);

    // Adopt ownership since already locked
    lock_guard<mutex> lg1(m1, adopt_lock);
    lock_guard<mutex> lg2(m2, adopt_lock);

    cout << "Thread 1 acquired both locks\n";

    // Simulate work
    this_thread::sleep_for(chrono::milliseconds(200));

    cout << "Thread 1 releasing locks\n";
}

// Function using std::scoped_lock (modern approach)
void SecondLock() {
    cout << "Thread 2 trying to lock...\n";

    // Deadlock-safe locking (recommended)
    scoped_lock lock(m1, m2);

    cout << "Thread 2 acquired both locks\n";

    // Simulate work
    this_thread::sleep_for(chrono::milliseconds(200));

    cout << "Thread 2 releasing locks\n";
}

int main() {
    thread t1(FirstLock);
    thread t2(SecondLock);

    t1.join();
    t2.join();

    cout << "Execution completed without deadlock\n";
    return 0;
}