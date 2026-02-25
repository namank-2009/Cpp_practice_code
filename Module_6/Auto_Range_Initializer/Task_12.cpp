#include<iostream>
#include<vector>

int main(){
    // Declaring the vector of vector and intialising its values
    std::vector<std::vector<int>>mat{{1,2},{3,4}};

    // Printing the value of vector
    std::cout << "Matrix elements:" << std::endl;
    for(const auto& row:mat){
        for(const auto& val:row){
            std::cout<<val<<" ";
        }
        std::cout<<std::endl;
    }
}