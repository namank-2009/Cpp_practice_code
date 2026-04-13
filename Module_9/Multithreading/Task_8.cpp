#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

int counter = 1;
std::mutex mtx;
std::condition_variable cv;
const int MAX = 20;


void OddThread() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [] {
            return counter % 2 == 1 || counter > MAX;
        });

        if (counter > MAX) break;

        std::cout << counter << " ";
        counter++;

        cv.notify_one();
    }
}

void EvenThread() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [] {
            return counter % 2 == 0 || counter > MAX;
        });

        if (counter > MAX) break;

        std::cout << counter << " ";
        counter++;

        cv.notify_one();
    }
}

int main() {
    std::thread odd(OddThread);
    std::thread even(EvenThread);

    odd.join();
    even.join();

    return 0;
}