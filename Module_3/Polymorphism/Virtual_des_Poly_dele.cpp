#include<iostream>
using namespace std;

class BaseLogger{
    public:
    BaseLogger() { 
        cout << "BaseLogger Resource initialized.\n";
    }

    virtual ~BaseLogger(){
        cout<<"Baselogger destroyed"<<endl;
    }
};

class FileLogger : public BaseLogger{
    private:
    string* fileName;
public:
    FileLogger(string name = "file.txt") {
        fileName = new string(name);
        cout << "FileLogger Opening file: " << *fileName << "\n";
    }
    
    ~FileLogger() {
        cout << "FileLogger Closing file and deleting filename string: " << *fileName << "\n";
        delete fileName;
    }
};

class ConsoleLogger : public BaseLogger{
    public:
    ConsoleLogger(){ 
        cout << "ConsoleLogger Terminal stream attached.\n"; 
    }
    ~ConsoleLogger(){
        cout<<"The console logger destructor is called"<<endl;
    }
};

int main(){
    cout << "--- Scenario 1: Successful Polymorphic Deletion ---\n";
    
    // Upcasting: Base pointer to Derived object
    BaseLogger* logger1 = new FileLogger("system_log.txt");
    BaseLogger* logger2 = new ConsoleLogger();

    cout << "\nDeleting logger1 (FileLogger via BaseLogger*):\n";
    delete logger1; // Calls ~FileLogger() then ~BaseLogger()

    cout << "\nDeleting logger2 (ConsoleLogger via BaseLogger*):\n";
    delete logger2; // Calls ~ConsoleLogger() then ~BaseLogger()

    return 0;    
}
