#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

// Step 1: Long computation function
int longComputation() {
    cout << "Computation started...\n";

    this_thread::sleep_for(chrono::seconds(2)); // simulate work

    cout << "Computation finished\n";
    return 42;
}

int main() {
    // No manual thread management
    // In thread we need to use join after that instead we can use this.
    // Step 2: Launch async task
    future<int> fut = async(launch::async, longComputation);
    // launch::async tells C++:
    // “Run this function in a NEW thread immediately.”
    cout << "Main thread continues working...\n";

    cout << "[Main] Waiting for result (this will block if not ready)...\n";
    // Step 3: Get result (blocks here if not ready)
    int result = fut.get();

    cout << "Result received: " << result << endl;

    return 0;
}