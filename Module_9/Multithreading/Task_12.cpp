#include <iostream>
#include <vector>
#include <thread>
#include <numeric>  // for accumulate

using namespace std;

// Worker function: computes sum of a chunk
void partialSum(const vector<int>& arr, int start, int end, int& result) {
    result = 0;
    for (int i = start; i < end; i++) {
        result += arr[i];
    }
}

int main() {
    vector<int> arr;
    for (int i = 1; i <= 100; i++) {
        arr.push_back(i);  // sum should be 5050
    }

    int n = arr.size();
    int numThreads = 4;  // you can change this

    //Result storage (each thread writes separately)
    vector<int> partialResults(numThreads, 0);

    vector<thread> threads;

    //  Divide work into chunks
    int chunkSize = n / numThreads;

    for (int i = 0; i < numThreads; i++) {
        int start = i * chunkSize;
        int end = (i == numThreads - 1) ? n : start + chunkSize;

        threads.emplace_back(partialSum, cref(arr), start, end, ref(partialResults[i]));
    }

    // Join threads
    for (auto &t : threads) {
        t.join();
    }

    // Combine results
    int finalSum = 0;
    for (int val : partialResults) {
        finalSum += val;
    }

    cout << "Final Parallel Sum = " << finalSum << endl;

    //Validate with single-threaded sum
    int checkSum = accumulate(arr.begin(), arr.end(), 0);
    cout << "Single-threaded Sum = " << checkSum << endl;

    return 0;
}