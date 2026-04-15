#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

// Worker function (producer)
void worker(promise<int> p) {
    cout << "[Worker] Doing some work...\n";
    
    this_thread::sleep_for(chrono::seconds(2)); // simulate delay
    int result = 100;
    cout << "[Worker] Setting value in promise...\n";
    
    // Send value to main thread
    p.set_value(result);
}

int main() {
    cout << "[Main] Creating promise and future...\n";
    // Step 1: Create promise
    promise<int> p;
    
    // Step 2: Get future from promise
    future<int> fut = p.get_future();
    cout << "[Main] Launching worker thread...\n";
    
    // Step 3: Pass promise to thread (move required)
    thread t(worker, move(p));
    cout << "[Main] Waiting for value from worker...\n";
    
    // Step 4: Get value (blocks until set_value is called)
    int value = fut.get();
    cout << "[Main] Received value: " << value << endl;
    t.join();
    return 0;
}