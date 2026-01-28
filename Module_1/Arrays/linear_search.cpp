#include <stdio.h>
#include <stdlib.h>

/* Function to input array elements */
void inputArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
}

// To check if the array is sorted or not
int isSorted(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] > arr[i + 1])
            return 0;   // Not sorted
    }
    return 1;           // Sorted
}
 
/* Linear Search Function */
int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

/* Binary Search Function (Array must be sorted) */
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/* Print Result Function */
void printResult(int index, int key) {
    if(index != -1)
        printf("Key %d found at index %d\n", key, index);
    else
        printf("Key %d not found in the array\n", key);
}

/* Comparator for qsort */
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[100], size, key, choice, index;

    printf("Enter size of array: ");
    scanf("%d", &size);

    if(size <= 0 || size > 100) {
        printf("Invalid array size!\n");
        return 0;
    }

    inputArray(arr, size);

    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("\nChoose Search Method:\n");
    printf("1. Linear Search\n");
    printf("2. Binary Search\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        index = linearSearch(arr, size, key);
        printResult(index, key);
    }
    else if(choice == 2) {
       if(!isSorted(arr, size)) {
        printf("Array is not sorted. Sorting array before Binary Search...\n");
        qsort(arr, size, sizeof(int), compare);
    } else {
        printf("Array is already sorted.\n");
    }

    index = binarySearch(arr, size, key);
    printResult(index, key);
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0;
}
