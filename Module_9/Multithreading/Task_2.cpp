#include<iostream>
#include<thread>
#include <chrono>

void worker(){
    std::this_thread::sleep_for(std::chrono::seconds(2));
     std::cout << "Worker finished | Thread ID: "
              << std::this_thread::get_id() << std::endl;
}

int main(){
    std::thread t(worker);
    t.detach();

    std::cout<<"Main ends"<<std::endl;
}