#include<iostream>
#include<thread>
#include <shared_mutex>
#include <vector>
#include <chrono>
#include<mutex>

int sharedValue = 0;
std::shared_mutex s_mtx;
std::mutex cout_mtx;

void reader(int id){
   for (int i = 0; i < 5; i++) {
        {
            // Shared lock → multiple readers allowed
            std::shared_lock<std::shared_mutex> lock(s_mtx);

            std::lock_guard<std::mutex> cout_lock(cout_mtx);
            std::cout << "[Reader " << id 
                 << "] reads sharedValue = " 
                 << sharedValue << std::endl;
        } // lock released here

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

void writer(int id){
     for (int i = 0; i < 5; i++) {
        {
            // Unique lock → exclusive access
            std::unique_lock<std::shared_mutex> lock(s_mtx);

            sharedValue++;
            std::lock_guard<std::mutex> cout_lock(cout_mtx);
            std::cout << ">>> [Writer " << id 
                 << "] updates sharedValue to " 
                 << sharedValue << std::endl;
        } // lock released here

        std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }
}

int main() {
    std::vector<std::thread> threads;

    threads.emplace_back(reader, 1);
    threads.emplace_back(reader, 2);
   
    threads.emplace_back(reader, 3);
    threads.emplace_back(writer, 1);
    for (auto &t : threads) t.join();

    return 0;
}