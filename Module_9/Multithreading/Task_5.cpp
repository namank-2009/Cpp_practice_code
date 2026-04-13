#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int counter = 0;
mutex mtx;

// Prefer lock_guard for simple, scope-based locking—lightweight and minimal.
void incrLockGuard(){
    for(int i=0; i<1000; i++){
        lock_guard<mutex>lock(mtx);
        counter++;
    }
}

// Prefer unique_lock when you need:
// manual unlock/relock
// locking multiple mutexes
// transferring locks between scopes (move semantics)
void incrUniqueLock(){
    for(int i=0; i<1000; i++){
        unique_lock<mutex> lock(mtx);
        counter++;  // critical section
    }
}
int main(){
    thread t1(incrLockGuard);
    thread t2(incrUniqueLock);

    t1.join();
    t2.join();

    cout<<"Counter Value: "<<counter<<endl;
}






// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <vector>

// using namespace std;

// int counter = 0;
// mutex mtx;

// // 🔒 lock_guard: simple, scoped locking
// void incrLockGuard() {
//     for (int i = 0; i < 1000; i++) {
//         lock_guard<mutex> lock(mtx);
//         counter++;
//     }
// }

// // 🔓 unique_lock: flexible, but here used like lock_guard (no manual unlock needed)
// void incrUniqueLock() {
//     for (int i = 0; i < 1000; i++) {
//         unique_lock<mutex> lock(mtx);
//         counter++;
//     }
// }

// int main() {

//     // ✅ Test 1: lock_guard
//     counter = 0;
//     vector<thread> threads1;

//     for (int i = 0; i < 4; i++) {
//         threads1.emplace_back(incrLockGuard);
//     }

//     for (auto &t : threads1) {
//         t.join();
//     }

//     cout << "lock_guard Counter Value: " << counter << endl;


//     // ✅ Test 2: unique_lock
//     counter = 0;
//     vector<thread> threads2;

//     for (int i = 0; i < 4; i++) {
//         threads2.emplace_back(incrUniqueLock);
//     }

//     for (auto &t : threads2) {
//         t.join();
//     }

//     cout << "unique_lock Counter Value: " << counter << endl;

//     return 0;
//}