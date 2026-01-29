#include<iostream>
#include <cstdlib>
using namespace std;

int main(){
    //Allocate the c++ new[]
    // new[] automatically allocates memory for 5 integers
    // No explicit typecasting needed in C++ (type-safe)
    // If we used objects instead of ints, constructors would run automatically
    int* arr1 = new int[5];

    //Allocate the c malloc
    // malloc allocates raw memory, does NOT call constructors
    // In C++, malloc returns void*, so we must cast to int* explicitly
    int* arr2 = (int*)malloc(5*sizeof(int));

    //Intialize both the arrays
    cout << "Enter 5 integers for arr1 (new[]): ";
    for(int i=0; i<5; i++){
        cin>>arr1[i];
    }

    cout << "Enter 5 integers for arr2 (malloc): ";
    for(int i=0; i<5; i++){
        cin>>arr2[i];
    }
    
    //Print contents
    cout << "\nContents of arr1 (new[]): ";
    for(int i = 0; i < 5; i++) {
        cout << arr1[i] << " ";
    }

    cout << "\nContents of arr2 (malloc): ";
    for(int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Deallocate memory
    // delete[] frees memory allocated by new[]
    // If arr1 were an array of objects, destructors would be called automatically
    delete[] arr1;

    // free() releases memory allocated by malloc
    // Destructors are NOT called for objects allocated with malloc
    free(arr2);      // does NOT call destructor
    return 0;
}