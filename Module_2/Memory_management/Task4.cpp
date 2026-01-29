#include<iostream>
using namespace std;

//Item Class created with constructor and destructor
class Item{
    public:
    Item(){
        cout<<"Constructor is called"<<endl;

    }
    ~Item(){
        cout<<"Destructor is called"<<endl;
    }
};

int main(){
    //Single object allocation
    cout << "=== Single Object Allocation ===\n";
    Item* single = new Item;
    delete single; // delete single object
    cout<<"\n";

    // We have to use delete[] arr bcz it consist of multiple object so we need to freed memory from all of them
    cout << "=== Array Allocation ===\n";
    Item* arr = new Item[3];
    delete[] arr;  // array of 3 objects deleted dynamically
    cout<<"\n";

     /*
    Item* arr2 = new Item[3];
    cout << "Deleting array with delete (INCORRECT)\n";
    delete arr2;  // may call destructor only for first element
    // This can cause problem such that the heap memory is not freed up properly
    */
}