#include <iostream>
#include <cstdlib>   // for qsort
using namespace std;

/* Function to print array elements */
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/* Bubble Sort */
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        // If no swaps happened, array is already sorted
        if (!swapped)
            break;
    }
}

/* Selection Sort */
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

/* Comparator function for qsort */
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

/* qsort wrapper */
void qsortWrapper(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare);
}

int main() {
    int arr[100];
    int size, choice;

    cout << "Enter size of array (1-100): ";
    cin >> size;

    // Input validation
    if (size <= 0 || size > 100) {
        cout << "Invalid array size!" << endl;
        return 0;
    }

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "\nOriginal Array:\n";
    printArray(arr, size);

    cout << "\nChoose sorting method:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. qsort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(arr, size);
            cout << "\nSorted using Bubble Sort:\n";
            break;

        case 2:
            selectionSort(arr, size);
            cout << "\nSorted using Selection Sort:\n";
            break;

        case 3:
            qsortWrapper(arr, size);
            cout << "\nSorted using qsort:\n";
            break;

        default:
            cout << "Invalid choice!" << endl;
            return 0;
    }

    printArray(arr, size);

    return 0;
}
