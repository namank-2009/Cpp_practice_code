#include<iostream>
#include<semaphore>
#include<vector>
#include<thread>

using namespace std;
counting_semaphore<2>sem(2);

// Counting semaphore ensure only 2 threads can enter at at time
void worker(int id){
    cout << "Thread " << id << " is WAITING to acquire resource\n";
    // Acquire decrements the count which ensure the no of threads acquired
    sem.acquire();

    cout << "Thread " << id << " ENTERED critical section\n";
    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "Thread " << id << " is EXITING critical section\n";
    // release increments the count which ensure the no of threads release
    sem.release();
    cout << "Thread " << id << " has RELEASED resource\n";
}
int main(){
    vector<thread>threads;

    for(int i=1; i<=5; i++){
        threads.emplace_back(worker,i);
    }

    for(auto &t:threads){
        t.join();
    }
    return 0;
}