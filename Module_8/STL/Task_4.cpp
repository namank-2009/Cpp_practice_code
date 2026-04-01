#include<iostream>
#include<string>
#include<list>


int main(){
    std::list<std::string> Warehouse1 = {"A100", "A200", "A300"}; 
    std::list<std::string> Warehouse2 = {"A150", "A250", "A350"};

    for(auto product: Warehouse1){
        std::cout<<product<<" ";
    }
    std::cout<<std::endl;

    for(auto product: Warehouse2){
        std::cout<<product<<" ";
    }
    std::cout<<std::endl;

    Warehouse1.sort();
    Warehouse2.sort();

    Warehouse1.merge(Warehouse2);

    std::cout << "\nMerged Inventory (Warehouse1): ";
    for(auto product: Warehouse1){
        std::cout<<product<<" ";
    }
    std::cout<<std::endl;

    std::cout << std::endl;

    if (Warehouse2.empty()) {
        std::cout << "Warehouse2 is now empty after merge." << std::endl;
    } else {
        std::cout << "Warehouse2 is NOT empty." << std::endl;
    }
}