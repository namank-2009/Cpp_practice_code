#include<iostream>
#include<vector>
#include<list>

int main(){
    //Created a list
    std::list<int>nums;
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(9);

    std::cout << "Original List: ";
    for (int x : nums) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

   int number;
std::cout << "Enter the value to remove from the list: ";
while (!(std::cin >> number)) {
    std::cout << "Invalid input! Please enter an integer: ";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

    std::list<int> list1 = nums;
    list1.remove(number);  // removes ALL occurrences

    std::cout << "\nAfter remove() function: ";
    for (int x : list1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::list<int> list2 = nums;  // copy original

    for (auto it = list2.begin(); it != list2.end(); ) {

        if (*it == number) {
            // erase() returns next valid iterator
            it = list2.erase(it);
        } else {
            ++it;  // move forward only if not erased
        }
    }

    std::cout << "\nAfter manual removal using iterator: ";
    for (int x : list2) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}