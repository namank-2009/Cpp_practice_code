#include<iostream>
#include<thread>
#include<string>
#include<vector>
#include<mutex>

std::mutex m; // mutex so that when one thread is working ono other can interrupt
void printMessage(const std::string &msg){
    std::lock_guard<std::mutex>lock(m);
    std::cout<<msg<<" Thread: "<<std::this_thread::get_id()<<std::endl;

}

int main(){
    // Threads are lightweight execution of the process
    std::vector<std::thread>Threads;
    for(int i = 0; i < 3; i++){
        std::string msg = "Hello from thread " + std::to_string(i);
        Threads.emplace_back(printMessage, msg);
    }

    // We are using join so that it should wait for all the thread
    for(auto &t : Threads){
        t.join();
    }

}