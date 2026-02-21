#include<iostream>
#include<string>
#include<limits>

int main(){
    std::string name;
    int age;
    std::string city;
    // The cout is used to print the statement
    std::cout<<"Enter the name: ";
    // cin is used to take the input from the user
    std::getline(std::cin,name);

    std::cout<<"Enter the age: ";
    std::cin>>age;

    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::cout<<"Enter the city: ";
    std::getline(std::cin,city);

    std::cout<<"Hello "<<name<<", you are "<<age<<" years old and live in "<<city<<std::endl;
}