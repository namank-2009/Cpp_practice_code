#include<iostream>
#include<thread>
#include<mutex>
#include<queue>
#include<condition_variable>

using namespace std;

std::queue<int>buffer;
std::mutex mtx;
std::condition_variable cv;
bool done = false;

void Producer(){
    for(int i=1; i<=20; i++){
        {
            unique_lock<mutex>lock(mtx);
            buffer.push(i);
            cout << "Produced: " << i << endl;
        }
        cv.notify_one();
    }
    {
        unique_lock<mutex> lock(mtx);
        done = true;
    }
    cv.notify_all();
}

void Consumer(){
    while(true){
        unique_lock<mutex>lock(mtx);
        cv.wait(lock, []{
            return !buffer.empty() || done;
        });

        if (buffer.empty() && done) {
            break; // safe exit
        }

        int val = buffer.front();
        buffer.pop();
        lock.unlock();
        cout<<"Consumed: "<<val<<endl;
        
    }
}

int main(){
    thread t1(Producer);
    thread t2(Consumer);
    t1.join();
    t2.join();
}