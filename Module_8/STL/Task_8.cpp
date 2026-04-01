#include <iostream>
#include <list>
#include <string>

// Define Task struct
struct Task {
    std::string name;
    int priority;
    int deadline;

    // Method to print task details
    void print() const {
        std::cout << "Task: " << name 
                  << " | Priority: " << priority 
                  << " | Deadline: " << deadline << std::endl;
    }
};

// Custom comparator function
bool taskCompare(const Task& a, const Task& b) {

    // If priorities are different → higher priority first
    if (a.priority != b.priority) {
        return a.priority > b.priority;  
        // Higher number = higher priority → comes first
    }

    // If priorities are same → earlier deadline first
    return a.deadline < b.deadline;  
    // Smaller deadline = sooner → comes first
}

int main() {

    // Initialize list of tasks
    std::list<Task> tasks = {
        {"Sending the Mail", 2, 5},
        {"Fix Critical bug", 1, 1},
        {"Team meeting", 2, 1},
        {"Code review", 2, 3},
        {"Update docs", 3, 4}
    };

    // Print before sorting
    std::cout << "Tasks BEFORE sorting:\n";
    for (const auto& t : tasks) {
        t.print();
    }

    // Sort using custom comparator
    tasks.sort(taskCompare);

    // Print after sorting
    std::cout << "\nTasks AFTER sorting:\n";
    for (const auto& t : tasks) {
        t.print();
    }

    return 0;
}