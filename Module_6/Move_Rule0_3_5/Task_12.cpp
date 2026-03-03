#include <iostream>
#include <vector>
#include <chrono>
#include <utility>

class LargeArray {
    std::vector<int> data;
public:
    LargeArray(size_t n) : data(n, 42) {
        std::cout << "Constructed LargeArray with " << n << " elements\n";
    }
    LargeArray(const LargeArray& other) : data(other.data) {
        std::cout << "Copied LargeArray (deep copy)\n";
    }
    LargeArray(LargeArray&& other) noexcept : data(std::move(other.data)) {
        std::cout << "Moved LargeArray (shallow/efficient move)\n";
    }
    
    size_t size() const {
        return data.size();
    }
};

int main() {
    const size_t N = 10'000'000;
    LargeArray arr1(N);

    auto start = std::chrono::high_resolution_clock::now();
    LargeArray arr2 = arr1; // Copy
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Copy time: "
              << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    start = std::chrono::high_resolution_clock::now();
    LargeArray arr3 = std::move(arr1); // Move
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Move time: "
              << std::chrono::duration<double, std::milli>(end - start).count() << " ms\n";

    std::cout << "arr1 size after move: " << arr1.size() << "\n";
    std::cout << "arr3 size after move: " << arr3.size() << "\n";

    return 0;
}
