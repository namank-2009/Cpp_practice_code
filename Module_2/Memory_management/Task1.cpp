#include<iostream>
#include <unordered_set>
using namespace std;

//Made a counter 
// Used unordered set for allocation check 
class Tracker{
    static int counter;
    static unordered_set<void*>allocations;

    public:
    // Overloaded new member function
    static void* operator new(size_t size){
        void* ptr = malloc(size);
        counter++;
        allocations.insert(ptr);
        cout<<"Memory is allocated "<<ptr<<endl;
        return ptr;
    }
    
    // Overloaded delete member function
    static void operator delete(void* ptr){
        counter--;
        allocations.erase(ptr);
        cout << "[DEL ] Memory freed at: " << ptr << endl;
        free(ptr);
    }

    // Checking for memory leak
    static void reportLeaks(){
        if (counter == 0) {
            cout << "\n No memory leaks detected\n";
        } else {
            cout << "\n Memory Leaks Detected: " << counter << endl;
            cout << "Leaked addresses:\n";
            for (auto addr : allocations) {
                cout << "  -> " << addr << endl;
            }
        }
    }
};

// Initialise the value
int Tracker::counter = 0;
unordered_set<void*> Tracker::allocations; 

int main(){
    Tracker* t1 = new Tracker();
    Tracker* t2 = new Tracker();
    Tracker* t3 = new Tracker();
    Tracker* t4 = new Tracker();
    
    delete t1;
    delete t3;


    Tracker::reportLeaks();

}