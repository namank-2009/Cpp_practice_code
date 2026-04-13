#include<iostream>
#include<thread>
#include<vector>

// Meyers Singleton: static local variable ensures lazy initialization
// and thread safety in C++11 and later. Constructor is private to prevent
// external instantiation, and copy/move are deleted to prevent duplicates.

class Logger{
    private:
        Logger(){
            std::cout << "Logger Constructor Called\n";
        }
        Logger (const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
    public:
        static Logger& getInstance(){
            static Logger instance;
            return instance;
        }
        void log() {
            std::cout << "Logger Instance Address: " << this <<std::endl;
        }
};

void threadTask(int id) {
    Logger& logger = Logger::getInstance();
    std::cout << "Thread " << id << " -> ";
    logger.log();
}

int main(){
    std::vector<std::thread> threads;

    // Create multiple threads
    for (int i = 1; i <= 5; i++) {
        threads.push_back(std::thread(threadTask, i));
    }

    // Join threads
    for (auto &t : threads) {
        t.join();
    }
    return 0;
}