#include<iostream>
using namespace std;

int* allocation(){
    int* arr = new int(5); // dynamic allocation using new[]
    for(int i=0; i<5; i++){
        cin>>arr[i];
    }
    return arr;  // return pointer to caller
}
int main(){
    // Get dynamically allocated memory
    int* nums = allocation();
    
    //Use the array safely
    cout << "Array elements: ";
    for(int i = 0; i < 5; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // Delete the allocated memory
    delete[] nums;

    // Demonstrate undefined behavior 
    cout << "\nAttempting to access deleted memory\n";
    // Accessing nums now is unsafe
    cout << nums[0] << " (may crash or give garbage value)\n";

    //Prevent dangling pointer by nullifying
    nums = nullptr;

    cout << "\nPointer has been nullified to prevent dangling pointers.\n";

    return 0;
}
