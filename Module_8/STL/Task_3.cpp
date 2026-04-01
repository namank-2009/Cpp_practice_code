#include<iostream>
#include<list>

int main(){
    //List created
    std::list<int>grades;
    
    //Checking for list is empty or not
    if(grades.empty()){
        std::cout<<"List is empty!"<<std::endl;
    }

    grades.push_back(80);
    grades.push_back(90);
    grades.push_back(75);
    grades.push_back(98);
    grades.push_back(89);
    grades.push_back(85);

    //Printing the list elements
   for(auto grade : grades) {
        std::cout << grade << " ";
    }
    std::cout<<std::endl;

    std::cout<<"The size of list is "<<grades.size()<<std::endl;

    std::cout<<"First element of grades list "<<grades.front()<<std::endl;
    std::cout<<"Last element of grades list "<<grades.back()<<std::endl;

    auto it = grades.begin(); 
    std::advance(it, 2);    
    std::cout<<"Third element of grades list "<<*it<<std::endl;

    *it = 99;
    std::cout<<"Updated third element of grades list "<<*it<<std::endl;

    //Checking for out of bound access
    try {
        auto it = grades.begin();
        std::advance(it, 100);
        // Demonstrate that no exception is thrown
        if(it == grades.end()) {
            std::cout << "No exception thrown by advance()" << std::endl;
        }
    } catch(...) {
        std::cout << "This won't catch anything" << std::endl;
    }

    grades.insert(grades.begin(),100);
    auto it2 = std::prev(grades.end());
    grades.insert(it2, 98);
    
    for (auto it = grades.begin(); it != grades.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout<<std::endl;

    std::cout<<"The size of updated list is "<<grades.size()<<std::endl;

    grades.pop_back();

    if(grades.size() >= 3) {
        auto it = grades.begin();
        std::advance(it, 2);
        grades.erase(it);
    } else {
        std::cout << "Not enough elements" << std::endl;
    }


    for (auto grade:grades) {
        std::cout << grade << " ";
    }
    std::cout<<std::endl;

    std::cout<<"The size of list is "<<grades.size()<<std::endl;

    grades.clear();

    for (auto it = grades.begin(); it != grades.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout<<std::endl;

    std::cout<<"The size of list is "<<grades.size()<<std::endl;
}


/*
#include<iostream>
#include<list>
#include<iterator>  // for std::advance, std::prev

int main(){

    // 1. Create list
    std::list<int> grades;

    // Check if empty
    if(grades.empty()){
        std::cout<<"List is empty!"<<std::endl;
    }

    // 2. Add elements
    grades.push_back(80);
    grades.push_back(90);
    grades.push_back(75);
    grades.push_back(98);
    grades.push_back(89);
    grades.push_back(85);

    // Print list (range-based loop)
    std::cout<<"Grades: ";
    for(auto grade : grades){
        std::cout<<grade<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Size of list: "<<grades.size()<<std::endl;

    // 3. Access elements safely
    if(!grades.empty()){
        std::cout<<"First element: "<<grades.front()<<std::endl;
        std::cout<<"Last element: "<<grades.back()<<std::endl;
    }

    // Access 3rd element safely
    if(grades.size() >= 3){
        auto it = grades.begin();
        std::advance(it, 2);   // FIXED (3rd element)
        std::cout<<"Third element: "<<*it<<std::endl;

        // Modify
        *it = 99;
        std::cout<<"Updated third element: "<<*it<<std::endl;
    }
    else{
        std::cout<<"Not enough elements to access third position"<<std::endl;
    }

    // 4. Demonstrate iterator behavior (CORRECT WAY)
  try {
        auto it = grades.begin();
        std::advance(it, 100);
        // Demonstrate that no exception is thrown
        if(it == grades.end()) {
            std::cout << "No exception thrown by advance()" << std::endl;
        }
    } catch(...) {
        std::cout << "This won't catch anything" << std::endl;
    }

    // 5. Insert elements
    grades.insert(grades.begin(), 100);

    if(!grades.empty()){
        auto it2 = std::prev(grades.end()); // before last
        grades.insert(it2, 98);
    }

    std::cout<<"\nAfter insertion: ";
    for(auto grade : grades){
        std::cout<<grade<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Updated size: "<<grades.size()<<std::endl;

    // 6. Remove elements

    // Remove last safely
    if(!grades.empty()){
        grades.pop_back();
    }

    // Remove 3rd element safely
    if(grades.size() >= 3){
        auto it3 = grades.begin();
        std::advance(it3, 1);
        grades.erase(it3);
    }
    else{
        std::cout<<"Not enough elements to remove third position"<<std::endl;
    }

    std::cout<<"\nAfter deletion: ";
    for(auto grade: grades){
        std::cout<<grade<<" ";
    }
    std::cout<<std::endl;

    std::cout<<"Size after deletion: "<<grades.size()<<std::endl;

    // 7. Clear list
    grades.clear();

    // Final check
    if(grades.empty()){
        std::cout<<"\nIs the list empty? Yes"<<std::endl;
    }

    std::cout<<"Size after clear: "<<grades.size()<<std::endl;

    return 0;
}
*/