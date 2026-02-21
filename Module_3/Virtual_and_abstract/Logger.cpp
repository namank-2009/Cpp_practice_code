#include<iostream>
using namespace std;

// Logger class with virtual log function and destructor for the logger
class Logger{
    public:
    virtual void log(const std::string& message) = 0;
    virtual ~Logger(){
        cout<<"Logger Destroyed"<<endl;
    }
};

// Filelogger class inheriting logger class
// Made a destructor for filelogger
class FileLogger : public Logger{
    public:
    void log(const std::string &msg) override{
        cout<<"The message of filelogger is"<<msg<<endl;
    }
    ~FileLogger(){
        cout<<"Filelogger Destroyed"<<endl;
    }
};

//Consolelogger class with logger class
//log class overridden and destructor made for this class
class ConsoleLogger : public Logger{
    public:
    void log(const std::string &msg) override{
        cout<<"The message of Consolelogger is"<<msg<<endl;
    }

    ~ConsoleLogger(){
        cout<<"ConsoleLogger Destroyed"<<endl;
    }
};

int main(){
    Logger* logger1 = new FileLogger();
    Logger* logger2 = new ConsoleLogger();
    // Calls filelogger 
    // First destructor of filelogger then logger destructor
    logger1->log("Hello from files");
    // Calls consolelogger
    // First destructor of derived then base
    logger2->log("Hello from console");

    delete(logger1);
    delete(logger2);

}