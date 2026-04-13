#include<iostream>
#include<thread>
#include<vector>
#include<mutex>

class Logger{
    private:
        Logger(){
            std::cout<<"Logger Constructor"<<std::endl;
        }

        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
    public:
        static Logger* instance;
        static std::once_flag initFlag;

        static Logger& getInstance(){
            std::call_once(initFlag, &Logger::initLogger);
            return *instance;
        }
        static void initLogger(){
            instance = new Logger();
        }
        void log(int threadId) {
        std::cout << "Thread " << threadId 
             << " using Logger instance at address: " 
             << this << std::endl;
        }
};

Logger* Logger::instance = nullptr;
std::once_flag Logger::initFlag;

void threadTask(int id) {
    Logger& logger = Logger::getInstance();
    logger.log(id);
}

int main() {
    std::vector<std::thread> threads;

    // Launch multiple threads
    for (int i = 1; i <= 4; i++) {
        threads.emplace_back(threadTask, i);
    }

    // Join all threads
    for (auto &t : threads) {
        t.join();
    }

    return 0;
}