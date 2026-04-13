#include<queue>
#include<thread>
#include<iostream>
#include<condition_variable>
#include<mutex>

using namespace std; 
queue<int>buffer;
mutex mtx;
condition_variable cv;
bool done = false;

 void Producer(){
    for(int i=1; i<=20; i++){
        {
            lock_guard<mutex>lock(mtx);
            buffer.push(i);
            cout << "Produced: " << i << endl;
        }
        cv.notify_one();
    }
    {
        lock_guard<mutex> lock(mtx);
        done = true;
    }
    cv.notify_one(); 
 }

 void consumer(){
    while (true) {
        unique_lock<mutex> lock(mtx);

        // wait until buffer not empty OR producer is done
        cv.wait(lock, [] {
            return !buffer.empty() || done;
        });

        // process all available items
        while (!buffer.empty()) {
            int val = buffer.front();
            buffer.pop();
            cout << "Consumed: " << val << endl;
        }

        // exit condition
        if (done && buffer.empty()) {
            break;
        }
    }
 }

 int main(){
    thread t1(Producer);
    thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
 }