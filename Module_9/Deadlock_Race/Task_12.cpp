#include <iostream>
#include <thread>
#include <barrier>
#include <vector>
#include <chrono>

using namespace std;

// Barrier for 3 threads
std::barrier sync_point(3);

void worker(int id) {
    // Phase 1 work
    cout << "Thread " << id << " before barrier\n";
    this_thread::sleep_for(chrono::milliseconds(100 * id));

    // Wait for all threads
    sync_point.arrive_and_wait();

    // Phase 2 work (only after all threads reach barrier)
    cout << "Thread " << id << " after barrier\n";
}

int main() {
    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker, 3);

    t1.join();
    t2.join();
    t3.join();

    cout << "\nAll threads completed\n";
    return 0;
}