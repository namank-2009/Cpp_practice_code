#include<iostream>
#include<memory>
#include<string>
using namespace std;

// Creating the filehandler class with its constructor and destructor and write method
class FileHandler{
    public:
    FileHandler(){
        cout<<"File Opened"<<endl;
    }

    void write(const string message){
        cout<<"Writing: "<<message<<endl;
    }

    ~FileHandler(){
        cout<<"File Closed"<<endl;
    }
};

// Returning the unique pointer
std::unique_ptr<FileHandler> createFileHandler(){
    unique_ptr<FileHandler>ptr = make_unique<FileHandler>();
    return ptr;
}

// Function where the another file takes the ownership and call the method the class method
void processFileHandler(std::unique_ptr<FileHandler>handler){
    handler->write("Processing log in another function");
}

int main(){
    // Creating a unique pointer
    unique_ptr<FileHandler>ptr = createFileHandler();

    // calling the write
    ptr->write("Initial log message");

    // Passing the ownership
    processFileHandler(move(ptr));
    
    // Checking the ptr is nullnow i.e. its ownerhsip is transfered properly
    if(ptr == nullptr){
        cout<<"Ptr no longer owns the file handler."<<endl;
    }
    return 0;
}