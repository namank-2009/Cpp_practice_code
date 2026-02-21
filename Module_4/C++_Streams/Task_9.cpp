#include<iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
using namespace std;

class Logger{
    private:
    ofstream logFile;

    string getCurrentTimeStamp(){
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);

        tm* localTime = localtime(&currentTime);

        stringstream ss;
        ss << "[" 
           << put_time(localTime, "%Y-%m-%d %H:%M:%S") 
           << "]";
        return ss.str();
    }

    public:
    // Constructor (RAII)
    Logger(const string& filename) {
        logFile.open(filename, ios::app);

        if (!logFile.is_open()) {
            cerr << "Error: Unable to open log file!" << endl;
            exit(1);
        }
    }
    
    void log(const string &msg){
        logFile<<getCurrentTimeStamp()<<" "<<msg<<endl;
    }
    ~Logger(){
        if(logFile.is_open()){
            logFile.close();
        }
    }
};

int main(){
    Logger logger("app.log");

    logger.log("Application started");
    logger.log("User logged in");
    logger.log("Processing data...");
    logger.log("Application finished successfully");

    cout << "Logs written to app.log file." << endl;
}