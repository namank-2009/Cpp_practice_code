#include<iostream>
#include<set>
#include <string>

void populateAndDemonstrateUniqueness(std::set<int>&StudentIDs){
    std::cout << "\n--- Populating Student Roster ---\n";
    std::cout << "Initial size: " << StudentIDs.size() << std::endl;
    StudentIDs.insert(101);
    StudentIDs.insert(105);
    StudentIDs.insert(103);
    StudentIDs.insert(102);

    std::cout<<"The size of set: "<<StudentIDs.size()<<std::endl;
    StudentIDs.insert(105); //Trying to insert duplicate value but set only contain unique elements
    std::cout<<"The size of set after insertion: "<<StudentIDs.size()<<std::endl;
}   

void printSetContents(std::set<int>&StudentIDs, std::string title){
    std::cout<<"\n"<<title<<"\n";

    if (StudentIDs.empty()) {
        std::cout << "Roster is empty.\n";
        return;
    }

    for(auto &it:StudentIDs){
        std::cout<<it<<std::endl;
    }
}

void checkIfStudentExists(const std::set<int>& studentIDs, int id) {
    std::cout << "Checking ID " << id << ": ";

    auto it = studentIDs.find(id);

    if (it != studentIDs.end())
        std::cout << "Found\n";
    else
        std::cout << "Not Found\n";
}

void removeStudents(std::set<int>& studentIDs) {
    std::cout << "\n--- Removing Students ---\n";

    // Remove existing
    std::cout << "Removing ID 102...\n";
    studentIDs.erase(102);
    std::cout << "Size after removal: " << studentIDs.size() <<std::endl;

    // Remove non-existing
    std::cout<< "\nAttempting to remove ID 108...\n";
    int removed = studentIDs.erase(108);

    std::cout<< "Elements removed: " << removed << std::endl;
    std::cout<< "Size after attempt: " << studentIDs.size() << std::endl;
}

int main(){
    // Step 1: Declare set
    std::set<int> studentIDs;
    std::cout << "Student ID set declared.\n";

    // Step 2: Populate
    populateAndDemonstrateUniqueness(studentIDs);

    // Step 3: Print initial roster
    printSetContents(studentIDs, "Initial Student Roster");

    // Step 4: Check existence
    std::cout << "\n--- Checking Student Existence ---\n";
    checkIfStudentExists(studentIDs, 103);
    checkIfStudentExists(studentIDs, 999);

    // Step 5: Remove elements
    removeStudents(studentIDs);

    // Step 6: Final roster
    printSetContents(studentIDs, "Final Student Roster");

    std::cout << "\nFinal size: " << studentIDs.size() << std::endl;
    std::cout << "Expected remaining IDs: 101, 103, 105\n";

    return 0;
}