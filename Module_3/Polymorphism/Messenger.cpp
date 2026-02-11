#include<iostream>
using namespace std;

class Messenger {
public:
    // Overload 1
    void send(const std::string &msg) {
        cout << "[send(msg)] Message: " << msg << endl;
    }

    // Overload 2 (with default value)
    void send(const std::string &msg, int priority = 1) {
        cout << "[send(msg, priority)] Message: "
             << msg << " | Priority: " << priority << endl;
    }
};

int main() {
    Messenger mm;
    //mm.send("Hello"); // <--- Compiler Error Here
    mm.send("Hello", 2);
}