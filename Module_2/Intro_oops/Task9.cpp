#include<iostream>
using namespace std;

class Logger{
    mutable int accessCount;
    string message;
    public:

   Logger(string msg) : accessCount(0), message(msg) {}

    // const member function
    void print() const{
        ++accessCount;
        cout << message << endl;
        cout<<"The access count is = "<<accessCount<<endl;
    }

    int getAccessCount() const{
        return accessCount;
    }
};

int main(){
    const Logger log("Logging message"); // const object

    cout << "Before print(): " << log.getAccessCount() << endl;

    log.print();   // allowed because print() is const
    log.print();

    cout << "After print(): " << log.getAccessCount() << endl;
}