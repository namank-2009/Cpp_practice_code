#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;

//Printing the elements
void printTodoList(const std::vector<std::string>&tasks){
    cout << "\n--- Current To-Do List ---\n";
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void clearInputBuffer() { 
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}

std::string toUpperString(std::string s) { 
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ 
        return std::toupper(c); 
    });
    return s; 
}

std::string toLowerString(std::string s) { 
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ 
        return std::tolower(c); 
    });
    return s; 
}

// CLASS
class TodoList{
    std::vector<std::string>tasks;
    public:
    //Initialize
    void initializeTodoList(){
        tasks = {
            "SendingStatusUpdateMail",
            "PrepareForMeeting",
            "CompletingTrainings",
            "UrgerntCriticalBugFix",
            "KnowledgeTransferNotes"
        };
        cout << "Initialized To-Do List.\n";
        printTodoList(tasks);
    }

    void displayInitialList(){
        printTodoList(tasks);
    }

    void addNewTask(){
        string task;
        cout << "Enter new task: ";
        getline(cin >> ws, task);

        tasks.push_back(task);
        printTodoList(tasks);
    }

    void insertHighPriorityTask(){
    string task;
    int position;
    cout << "Enter high priority task: ";
    getline(cin >> ws, task);
    cout << "Enter position (1-" << tasks.size()+1 << "): ";
    cin >> position;
    
    if(cin.fail() || position < 1 || position > tasks.size()+1){
        cout << "Invalid position!\n";
        cin.clear();
        clearInputBuffer();
        return;
    }
    
    tasks.insert(tasks.begin() + position - 1, task);
    clearInputBuffer();
    printTodoList(tasks);
}

    // View first & last
    void viewFirstAndLastTasks(){
    if (tasks.empty()) {
        std::cout << "The list is empty. Cannot view first and last tasks.\n";
        return;
    }
    std::cout << "First Task: " << tasks.front() << std::endl;
    std::cout << "Last Task: " << tasks.back() << std::endl;
}

    void removeLastTask(){
        if (tasks.empty()) {
            cout<<"The list is empty. No tasks to remove."<<endl;
            return;
        }
        tasks.pop_back();
        printTodoList(tasks);
    }

    void markTaskComplete(){
        if (tasks.empty()) {
        std::cout << "The list is empty. No tasks to remove.\n";
        return;
        }
        int index;
        cout << "Enter task number to remove: ";
        cin >> index;

        if (cin.fail() || index < 1 || index > tasks.size()) {
            cout << "Invalid input!\n";
            cin.clear();
            clearInputBuffer();
            return;
        }

        tasks.erase(tasks.begin() + index - 1);
        printTodoList(tasks);
    }

    void sortTasksAlphabetically(){
    if (tasks.empty()) {
        std::cout << "The list is empty. No tasks to sort.\n";
        return;
    }

    std::sort(tasks.begin(), tasks.end());
    printTodoList(tasks);
}

    void reverseTaskOrder() {
        std::cout << "\n--- Reverse Task Order ---\n";      
        if (tasks.empty()) {
            std::cout << "The list is empty. No tasks to reverse.\n";
        } 
        else{
            std::cout << "Reversing task order...\n";
            std::reverse(tasks.begin(), tasks.end());
            printTodoList(tasks);
        }
    }
    
    // Should implement case-insensitive search:
void searchAndCountTasks(){
    string key;
    cout << "Enter task to search: ";
    getline(cin >> ws, key);
    
    string keyLower = toLowerString(key);
    int count = 0;
    int firstIndex = -1;
    
    for(int i = 0; i < tasks.size(); i++){
        if(toLowerString(tasks[i]).find(keyLower) != string::npos){
            if(firstIndex == -1) firstIndex = i;
            count++;
        }
    }
    
    if(firstIndex != -1){
        cout << "First occurrence at index: " << (firstIndex + 1) << endl;
        cout << "Total occurrences: " << count << endl;
    } else {
        cout << "Task not found.\n";
        cout << "Total occurrences: 0\n";
    }
}


    void transformToUppercase(){
    if (tasks.empty()) {
        std::cout << "The list is empty. No tasks to transform.\n";
        return;
    }

    std::transform(tasks.begin(), tasks.end(), tasks.begin(),
        [](std::string s) { return toUpperString(s); });

    printTodoList(tasks);
}

    // Should be:
void checkKeywordContainingTasks(){
    string userKeyword;
    cout << "Enter additional keyword to search: ";
    getline(cin >> ws, userKeyword);
    string userKeyLower = toLowerString(userKeyword);
    
    cout << "\nTasks containing URGENT, DEADLINE, or '" 
         << userKeyword << "':\n";
    
    bool found = false;
    for(int i = 0; i < tasks.size(); i++){
        string taskLower = toLowerString(tasks[i]);
        if(taskLower.find("urgent") != string::npos ||
           taskLower.find("deadline") != string::npos ||
           taskLower.find(userKeyLower) != string::npos){
            cout << (i+1) << ". " << tasks[i] << endl;
            found = true;
        }
    }
    
    if(!found) cout << "No matching tasks found.\n";
}


    void findLexicographicallyFirstLast(){
    if (tasks.empty()) {
        std::cout << "The list is empty. Cannot find lexicographically first/last tasks.\n";
        return;
    }

    auto minIt = std::min_element(tasks.begin(), tasks.end());
    auto maxIt = std::max_element(tasks.begin(), tasks.end());

    std::cout << "First: " << *minIt << std::endl;
    std::cout << "Last: " << *maxIt << std::endl;
}

    void finalCleanup(){
        tasks.clear();
        cout << "All tasks cleared.\n";
    }
};

int main(){
    TodoList myTodoList;
    myTodoList.initializeTodoList();
    int choice;
    clearInputBuffer();
    do {
        cout << "\n===== TO-DO LIST MENU =====\n";
        cout << "0. Exit\n";
        cout << "1. Initialize List\n";
        cout << "2. Display List\n";
        cout << "3. Add Task\n";
        cout << "4. Insert High Priority Task\n";
        cout << "5. View First & Last\n";
        cout << "6. Remove Last Task\n";
        cout << "7. Mark Task Complete\n";
        cout << "8. Sort Tasks\n";
        cout << "9. Reverse Tasks\n";
        cout << "10. Search & Count\n";
        cout << "11. Convert to UPPERCASE\n";
        cout << "12. Check Keyword Tasks\n";
        cout << "13. Lexicographical Min/Max\n";
        cout << "14. Clear All Tasks\n";
        

        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: myTodoList.initializeTodoList(); break;
            case 2: myTodoList.displayInitialList(); break;
            case 3: myTodoList.addNewTask(); break;
            case 4: myTodoList.insertHighPriorityTask(); break;
            case 5: myTodoList.viewFirstAndLastTasks(); break;
            case 6: myTodoList.removeLastTask(); break;
            case 7: myTodoList.markTaskComplete(); break;
            case 8: myTodoList.sortTasksAlphabetically(); break;
            case 9: myTodoList.reverseTaskOrder(); break;
            case 10: myTodoList.searchAndCountTasks(); break;
            case 11: myTodoList.transformToUppercase(); break;
            case 12: myTodoList.checkKeywordContainingTasks(); break;
            case 13: myTodoList.findLexicographicallyFirstLast(); break;
            case 14: myTodoList.finalCleanup(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}