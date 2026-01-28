#include <iostream>
using namespace std;

const int MAX_STEPS = 100; // Predefined maximum steps for cache
int cache[MAX_STEPS + 1] = {0}; // Global cache for memoization

// Recursive function to count ways to climb stairs
int stairCaseCounter(int totalSteps) {
    // Base cases
    if (totalSteps == 0) return 1; // Already at top
    if (totalSteps == 1) return 1;
    if (totalSteps == 2) return 2;

    // Check if result is already in cache
    if (cache[totalSteps] != 0)
        return cache[totalSteps];

    // Recursive computation: 1 step or 2 steps
    cache[totalSteps] = stairCaseCounter(totalSteps - 1) + stairCaseCounter(totalSteps - 2);

    return cache[totalSteps];
}

int main() {
    int totalSteps;
    cout << "Enter total number of steps: ";
    cin >> totalSteps;

    // Input validation
    if (totalSteps < 0) {
        cout << "Invalid input! Number of steps cannot be negative.\n";
        return 0;
    }

    if (totalSteps > MAX_STEPS) {
        cout << "Number of steps exceeds maximum supported (" << MAX_STEPS << ").\n";
        return 0;
    }

    int totalWays = stairCaseCounter(totalSteps);
    cout << "Total number of ways to climb " << totalSteps << " steps: " << totalWays << endl;
    return 0;
}
