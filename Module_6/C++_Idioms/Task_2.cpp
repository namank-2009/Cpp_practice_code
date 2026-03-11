#include <iostream>
#include <stdexcept>

class IntArray {
    int* arr;
    size_t size;
public:
    IntArray(size_t n) : size(n), arr(new int[n]) {
        std::cout << "Allocated array of size " << size << " at " << static_cast<void*>(arr) << std::endl;
        for (size_t i = 0; i < size; ++i) arr[i] = static_cast<int>(i * 10);
    }
    ~IntArray() {
        std::cout << "Destructor called, freeing array at " << static_cast<void*>(arr) << std::endl;
        delete[] arr;
    }
    int& operator[](size_t i) { return arr[i]; }
    size_t getSize() const { return size; }
};

void testEarlyReturn() {
    IntArray a(5);
    a[0] = 42;
    std::cout << "testEarlyReturn: value[0] = " << a[0] << std::endl;
    return; // Destructor will be called automatically
}

void testException() {
    IntArray a(5);
    throw std::runtime_error("Oops! Exception triggered.");
}

int main() {
    try {
        IntArray arr(3);
        std::cout << "Normal usage: value[1] = " << arr[1] << std::endl;
    } catch (...) { }

    std::cout << "-- Testing early return --\n";
    testEarlyReturn();

    try {
        std::cout << "-- Testing exception --\n";
        testException();
    } catch (const std::exception& ex) {
        std::cerr << "Caught exception: " << ex.what() << std::endl;
    }

    std::cout << "End of main reached.\n";
    return 0;
}


// Output
// Allocated array of size 3 at 0x11117a0
// Normal usage: value[1] = 10
// Destructor called, freeing array at 0x11117a0
// -- Testing early return --
// Allocated array of size 5 at 0x11117a0
// testEarlyReturn: value[0] = 42
// Destructor called, freeing array at 0x11117a0
// -- Testing exception --
// Allocated array of size 5 at 0x11117a0
// Destructor called, freeing array at 0x11117a0
// Caught exception: Oops! Exception triggered.
// End of main reached.