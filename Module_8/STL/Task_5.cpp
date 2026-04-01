#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int main(){
    std::vector<std::string>students;
    students.push_back("Alice");
    students.push_back("Bob");
    students.push_back("Charlie");
    students.push_back("Diana");
    students.push_back("Eve");

    for(auto name:students){
        std::cout<<name<<" ";
    }
    std::cout<<std::endl;

   auto it = std::find(students.begin(), students.end(), "Charlie");
    if(it != students.end()){
        students.erase(it);
    }
    for(auto name : students) {
    std::cout << name << " ";
    }
    std::cout << std::endl;

     if(std::find(students.begin(), students.end(), "Eve") != students.end()){
        std::cout<<"Eve is present"<<std::endl;
    }

    // Edge Case: Remove non-existent student
    auto it2 = std::find(students.begin(), students.end(), "Frank");
    if(it2 != students.end()){
        students.erase(it2);
        std::cout << "Frank removed" << std::endl;
    } else {
        std::cout << "Frank not found in the list" << std::endl;
    }

    std::sort(students.begin(), students.end());
    
    std::cout<<"Sorted list: ";
    for(auto name : students){
        std::cout<<name<<" ";
    }
    std::cout<<std::endl;

    students.clear();
    if(students.empty()){
        std::cout<<"The students list is empty"<<std::endl;
    }
}