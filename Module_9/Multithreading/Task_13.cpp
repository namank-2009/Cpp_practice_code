#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx1, mtx2;

// Thread A
void threadA() {
    cout << "Thread A trying to lock mtx1\n";
    mtx1.lock();

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "Thread A trying to lock mtx2\n";
    mtx2.lock();

    cout << "Thread A acquired both locks\n";

    mtx2.unlock();
    mtx1.unlock();
}

// Thread B
void threadB() {
    cout << "Thread B trying to lock mtx2\n";
    mtx2.lock();

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "Thread B trying to lock mtx1\n";
    mtx1.lock();

    cout << "Thread B acquired both locks\n";

    mtx1.unlock();
    mtx2.unlock();
}

int main() {
    thread t1(threadA);
    thread t2(threadB);

    t1.join();
    t2.join();

    return 0;
}

// Using lock and adopt_lock 
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx1, mtx2;

void safeTask(int id) {
    cout << "Thread " << id << " trying to lock both mutexes\n";

    // Lock both mutexes safely (no deadlock)
    lock(mtx1, mtx2);

    // Adopt already locked mutexes
    lock_guard<mutex> lock1(mtx1, adopt_lock);
    lock_guard<mutex> lock2(mtx2, adopt_lock);

    cout << "Thread " << id << " acquired both locks\n";
}

int main() {
    thread t1(safeTask, 1);
    thread t2(safeTask, 2);

    t1.join();
    t2.join();

    return 0;
}


// Fix with scoped_lock in c++17
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx1, mtx2;

void safeTask(int id) {
    cout << "Thread " << id << " trying to lock both mutexes\n";

    // Automatically locks both without deadlock
    scoped_lock lock(mtx1, mtx2);

    cout << "Thread " << id << " acquired both locks\n";
}

int main() {
    thread t1(safeTask, 1);
    thread t2(safeTask, 2);

    t1.join();
    t2.join();

    return 0;
}