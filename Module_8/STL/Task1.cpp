#include<iostream>
#include<vector>
#include<exception>

int main(){
    std::vector<int>grades;
    if(grades.empty()){
        std::cout<<"Vector is empty"<<std::endl;
    }
    grades.push_back(80);
    grades.push_back(70);
    grades.push_back(60);
    grades.push_back(50);
    grades.push_back(40);
    grades.push_back(30);

    std::cout << "\nGrades: ";
    for(auto grade:grades){
        std::cout<<grade<<" ";
    }
    std::cout<<"Size of vector "<<grades.size()<<std::endl;

    std::cout<<"First grade in grades: "<<grades.front()<<std::endl;
    std::cout<<"Last grade in grades: "<<grades.back()<<std::endl;

    std::cout<<"Grade at index 2 using operator[]: "<<grades[2]<<std::endl;
    std::cout<<"Grade at index 2 using at(): "<<grades.at(2)<<std::endl;

    // Modify index 2
    grades[2] = 80;
    std::cout << "Modified grade at index 2: " << grades[2] <<std::endl;

    try{
        std::cout<<"Access invalid index: "<<grades.at(10)<<std::endl;
    }
    catch (std::out_of_range &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
     // Inserting Grades
    grades.insert(grades.begin(), 100); // beginning
    grades.insert(grades.end() - 1, 75); // before last

    grades[2] = 100; // Inserting grade at specific position

    for(auto grade:grades){
        std::cout<<grade<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Size of vector "<<grades.size()<<std::endl;

    grades.pop_back(); // removes last element
    grades.erase(grades.begin() + 1); // remove second element

    //After deletion
     for(auto grade:grades){
        std::cout<<grade<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Size of vector "<<grades.size()<<std::endl;

    // Clearing
    grades.clear();
    std::cout << "\nAfter clear, size: " << grades.size() <<std::endl;
    std::cout << "Is vector empty? " << (grades.empty() ? "Yes" : "No") <<std::endl;
}