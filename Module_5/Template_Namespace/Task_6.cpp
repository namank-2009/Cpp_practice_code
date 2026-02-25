#include<iostream>
#include<typeinfo>
using namespace std;

// Defining default type template
// If no type is send from main it take it as int
template<typename T = int>
class Number{
    T value;
    public:
    Number(T v): value(v){}

    void print(){
        cout<<"Number "<<typeid(T).name()<<": "<<value<<endl;

        // cout << "Number: " << value;

        // // Show type clearly
        // if constexpr (is_same_v<T, int>)
        //     cout << " (Type: int)";
        // else if constexpr (is_same_v<T, double>)
        //     cout << " (Type: double)";
        // else
        //     cout << " (Type: other)";

        // cout << endl;
    }
};
int main(){
    Number<> n1(100);           // Uses default type int
    Number<double> n2(3.14);    // Uses double

    n1.print();                 // Prints: 100
    n2.print();                 // Prints: 3.14

    return 0;
}