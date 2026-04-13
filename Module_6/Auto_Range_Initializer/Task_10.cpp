#include<iostream>
#include<vector>
#include <initializer_list>

using namespace std;

class Number{
    vector<int>data;
  public:
  // Using initializer list to copy the value to data
  // initializer list help to take multiple value to the constructor
  Number(std::initializer_list<int>list):data(list){}  

// print function
  void print(){
    cout<<"Printing the data value"<<endl;
    for(auto& val:data){
        cout<<val<<" ";
    }
  }
};
int main(){
    // Passing the value in the constructor in {}
    Number num{1,2,3,4};
    // Calling print function
    num.print();
    return 0;
}