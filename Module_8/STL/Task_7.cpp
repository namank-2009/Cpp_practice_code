#include <iostream>
#include <list>
#include <algorithm>  

const int CACHE_CAPACITY = 6;

// Function to print cache
void printCache(const std::list<int>& cache) {
    std::cout << "Cache (MRU -> LRU): ";
    for (auto val : cache) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

// Function to access cache
void accessCache(std::list<int>& cache, int value) {

    // Check if value already exists in cache
    auto it = std::find(cache.begin(), cache.end(), value);

    if (it != cache.end()) {
        // Value found → remove from current position
        cache.erase(it);

        // Move to front (most recently used)
        cache.push_front(value);
    } 
    else {
        // Value not found → add to front
        cache.push_front(value);

        // If capacity exceeded → remove least recently used
        if (cache.size() > CACHE_CAPACITY) {
            cache.pop_back();
        }
    }
}

int main() {

    // Initialize cache
    std::list<int> cache;

    int value;

    // User input loop
    while (true) {
        std::cout << "Access value (-1 to stop): ";
        std::cin >> value;

        if (value == -1) break;

        accessCache(cache, value);
        printCache(cache);
    }

    return 0;
}