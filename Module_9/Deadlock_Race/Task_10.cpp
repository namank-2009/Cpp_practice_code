#include<iostream>
#include<thread>
#include<mutex>
#include<atomic>

using namespace std;

std::atomic<int> value{10};

int main(){
    cout<<"Initial value: "<<value<<endl;
    int prev = value.fetch_add(5);
    //It add 5 to the value so now prev is 15
    cout<<"prev value after using fetch_add: "<<prev<<endl;

    prev = value.fetch_sub(3);
    //prev should be 15, value is now 12
    cout<<"prev value after using fetch_sub: "<<prev<<endl;

    prev = value.exchange(42);
    //prev should be 12, value is now 42

    cout<<"prev value after using exchange: "<<prev<<endl;
    cout<<"value: "<<value<<endl;
}