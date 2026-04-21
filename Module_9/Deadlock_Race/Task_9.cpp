#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

using namespace std;

/*
Release-Acquire Synchronization Example

- Producer writes data and sets a flag (ready)
- Consumer waits for flag and then reads data

release (Producer):
    Ensures all previous writes (data = 42) are visible

acquire (Consumer):
    Ensures once ready is true, it sees updated data
*/
atomic<bool> ready(false);
int sharedData = 0;  // ✅ renamed

void Producer() {
    cout << "[Producer] Writing data...\n";

    this_thread::sleep_for(chrono::milliseconds(100));

    sharedData = 42;
    cout << "[Producer] Data set to 42\n";

    ready.store(true, memory_order_release);
}

void Consumer() {
    cout << "[Consumer] Waiting...\n";

    while (!ready.load(memory_order_acquire)) {
        this_thread::yield();
    }

    cout << "[Consumer] Data received: " << sharedData << endl;
}

int main() {

    thread t1(Producer);
    thread t2(Consumer);

    t1.join();
    t2.join();

    return 0;
}