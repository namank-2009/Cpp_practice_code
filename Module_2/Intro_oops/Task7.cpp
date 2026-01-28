#include<iostream>
using namespace std;

#define SQUARE(x) ((x)*(x))
class Math{
    public:
    int square(int x){return x*x;}
};

int main(){
    Math m;

    // Simple value
    cout << "Macro SQUARE(4) = " << SQUARE(4) << endl;
    cout << "Inline square(4) = " << m.square(4) << endl;

    // Expression
    cout << "Macro SQUARE(1+2) = " << SQUARE(1+2) << endl;
    cout << "Inline square(1+2) = " << m.square(1+2) << endl;
}