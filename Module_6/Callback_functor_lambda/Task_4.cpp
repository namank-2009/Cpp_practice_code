#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

// Created the struct MultiplyBy and used functors to multiply val by factor
struct MultiplyBy{
    int factor;
    void operator()(int& x)const{
        x *= factor;
    }
};

int main(){
    // Created a vector of elements
    vector<int>arr{1,2,3,4,5,6};
    cout << "Original vector: ";
    for(auto val:arr){
        cout<<val<<" ";
    }
    cout<<endl;
    // used for_each to multiply the value by 3
    for_each(arr.begin(), arr.end(), MultiplyBy{3});

    cout << "Modified vector: ";
    for(auto val:arr){
        cout<<val<<" ";
    }
    return 0;
}