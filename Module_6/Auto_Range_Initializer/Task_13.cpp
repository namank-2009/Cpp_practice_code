#include<iostream>
#include<vector>

    // Returning the vector
    std::vector<int> getNumbers(){
        return {1,2,3,4,5};
    }

    int main(){
        // Calling the getNumber function to get the vector
        // Here we have used auto so it automatically work as vector
        // auto helps to make the code more clean and concise
        auto nums = getNumbers();

        //Printing the values of nums
        std::cout<<"Value of nums"<<std::endl;
        for(auto val:nums){
            std::cout<<val<<" ";
        }
    }