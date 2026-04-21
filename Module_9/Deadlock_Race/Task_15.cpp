#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<shared_mutex>
#include<chrono>

using namespace std;

int shared_data = 0;   
shared_mutex rw_mutex;
mutex cout_mutex;

void reader(int id){
    for(int i = 0; i < 5; i++){
        shared_lock<shared_mutex> lock(rw_mutex);

        {
            lock_guard<mutex> guard(cout_mutex);
            cout << "Reader " << id << " read data: " << shared_data << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void writer(int id){
    for(int i = 0; i < 5; i++){
        unique_lock<shared_mutex> lock(rw_mutex);

        shared_data++;  
        {
            lock_guard<mutex> guard(cout_mutex);
            cout << "Writer " << id << " updated data to: " << shared_data << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(250));
    }
}

int main(){
    vector<thread> threads;

    for(int i = 1; i <= 3; i++){
        threads.emplace_back(reader, i);
    }

    for(int i = 1; i <= 2; i++){
        threads.emplace_back(writer, i);
    }

    for(auto &t : threads){
        t.join();
    }

    return 0;
}