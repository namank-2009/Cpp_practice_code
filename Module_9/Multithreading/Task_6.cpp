#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <optional>

using namespace std;

optional<int> buffer;          // single-slot buffer
mutex mtx;
condition_variable cv;

void producer() {
    for (int i = 1; i <= 10; i++) {
        unique_lock<mutex> lock(mtx);

        // wait until buffer is empty
        cv.wait(lock, []() {
            return !buffer.has_value();
        });

        buffer = i;
        cout << "Produced: " << i << endl;

        // notify consumer
        cv.notify_one();
    }
}

void consumer() {
    for (int i = 1; i <= 10; i++) {
        unique_lock<mutex> lock(mtx);

        // wait until buffer is full
        cv.wait(lock, []() {
            return buffer.has_value();
        });

        cout << "Consumed: " << *buffer << endl;

        buffer.reset();  // empty buffer

        // notify producer
        cv.notify_one();
    }
}

int main() {
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}