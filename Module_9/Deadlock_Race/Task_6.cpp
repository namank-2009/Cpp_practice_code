#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

std::string sharedStr = "Start";
std::shared_mutex rw_mtx;

void writer(){
    std::unique_lock<std::shared_mutex> lock(rw_mtx);
    cout << "[Writer] Writing safely...\n";
    sharedStr = "End";
    this_thread::sleep_for(std::chrono::milliseconds(100));
}

void reader(int id){
    std::shared_lock<std::shared_mutex> lock(rw_mtx);
    cout << "[Reader " << id << "] reads safely: " << sharedStr << endl;
    this_thread::sleep_for(std::chrono::milliseconds(100));
}
int main(){
    thread t1(reader,1);
    thread t2(writer);
    thread t3(reader,2);

    t1.join();
    t2.join();
    t3.join();
    return 0;
}