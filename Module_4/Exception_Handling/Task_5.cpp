#include<iostream>
using namespace std;

class InvalidDataException {
public:
    const char* what() const {
        return "Invalid Data";
    }
}; 

class SystemError {
public:
    const char* what() const {
        return "System Error: Critical system failure occurred.";
    }
};

class NetworkError {
public:
    const char* what() const {
        return "Network Error: Unable to connect to server.";
    }
};

class LogSession{
    int id;
    public:
    LogSession(int sessionId) : id(sessionId){
        cout<<"[LogSession "<<id<<"] tarted."<<endl;
    }
    ~LogSession(){
       cout << "[LogSession " << id << "] ended." << endl;
    }
};

void performDataValidation(int data){
    LogSession log(3);
    cout << "[LogSession 3] checking data..." << endl;

    if(data<0){
        throw InvalidDataException();;
    }
    else if (data == 0) {
        throw SystemError();
    }
    else if (data == 999) {
        throw NetworkError();
    }
    cout<<"[LogSession 3] data validated successfully."<<endl;
}

void processTransaction(int data_value) {
    LogSession log(2);
    performDataValidation(data_value);
    cout << "[LogSession 2] transaction processed." << endl;
}

void startCriticalOperation(int data_value) {
    LogSession log(1);
    processTransaction(data_value);
    cout << "[LogSession 1] critical operation completed." << endl;
}

int main(){
    cout << "Starting main block." << endl;

    try {
        startCriticalOperation(10);   // Change to positive value to test normal flow
    }
    catch (InvalidDataException e) {
        cout << "Inside the main Catch handler: " << e.what() << endl;
    }
    catch (NetworkError e) {
        cout << "Inside main Catch handler: " << e.what() << endl;
    }

    catch (SystemError e) {
        cout << "Inside main Catch handler: " << e.what() << endl;
    }
    return 0;
    
}