#include<iostream>
#include<memory>
#include<string>
using namespace std;

class Logger{
    string name;
    bool isOpen = true;
    public:
    Logger(const string& name){
        this->name = name;
        isOpen = true;
        cout << "Logger \'" << name << "' created\n";
    }
    void log(const string& message){
        if(isOpen)
            cout << "[" << name << "]: " << message << endl;
        else
            cout << "[" << name << "] is closed\n";
    }
    void close(){
         if(isOpen) {
            cout << "Closing Logger \'" << name << "'\n";
            isOpen = false;
        }
    }

    ~Logger(){
        close();
        cout<<"Logger \'"<< name<<"\' destroyed. "<<endl;
    }
    string getName() const{
        return name;
    }
};

int main(){
   cout << "\n--- Basic Creation ---\n";
    unique_ptr<Logger> logger = make_unique<Logger>("MainLogger");
    logger->log("Hello from MainLogger");


    cout << "\n--- Assignment Replacement ---\n";
    logger = make_unique<Logger>("SecondaryLogger");
    logger->log("Hello from SecondaryLogger");


    cout << "\n--- Reset with New Object ---\n";
    logger.reset(new Logger("TemporaryLogger"));
    logger->log("I replaced the previous logger");


    cout << "\n--- Reset to Null ---\n";
    logger.reset();
    cout << "Logger is now " << (logger ? "not null" : "nullptr") << "\n";


    cout << "\n--- Null Assignment ---\n";
    logger = nullptr;


    cout << "\n--- Reassignment ---\n";
    logger = make_unique<Logger>("NewLogger");
    logger->log("Back in business");


    cout << "\n--- Move Semantics ---\n";
    auto logger2 = make_unique<Logger>("Logger2");
    logger = move(logger2);
    logger->log("Now I own Logger2's resource");

    cout << "logger2 is " << (logger2 ? "not null" : "nullptr") << "\n";


    cout << "\n--- Self Move ---\n";
    logger = move(logger);   // self move
    logger->log("Self-move didn't destroy me!");

    return 0;
}