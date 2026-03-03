#include <iostream>
#include <cstring>
#include <utility>

class Buffer {
    int* data;
    size_t size;
public:
    // Regular constructor
    Buffer(size_t sz) : size(sz) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) data[i] = i * 10;
        std::cout << "Constructor: allocated at " << static_cast<void*>(data) << "\n";
    }
    // Copy constructor
    Buffer(const Buffer& other) : size(other.size) {
        data = new int[size];
        std::memcpy(data, other.data, size * sizeof(int));
        std::cout << "Copy ctor: copy to " << static_cast<void*>(data) << "\n";
    }
    // Copy assignment
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::memcpy(data, other.data, size * sizeof(int));
            std::cout << "Copy assign: copy to " << static_cast<void*>(data) << "\n";
        }
        return *this;
    }
    // Move constructor
    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Move ctor: take " << static_cast<void*>(data) << "\n";
    }
    // Move assignment
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            size = other.size;
            other.data = nullptr;
            other.size = 0;
            std::cout << "Move assign: take " << static_cast<void*>(data) << "\n";
        }
        return *this;
    }
    // Destructor
    ~Buffer() {
        std::cout << "Destructor: freeing " << static_cast<void*>(data) << std::endl;
        delete[] data;
    }
    void print(const char* label) const {
        std::cout << label << " [data@" << static_cast<const void*>(data) << "] size=" << size << " values:";
        for (size_t i = 0; i < size; ++i) std::cout << " " << data[i];
        std::cout << std::endl;
    }
};

int main() {
    Buffer a(3);   // Regular
    Buffer b = a;  // Copy constructor
    Buffer c(2);
    c = a;         // Copy assignment

    Buffer d = std::move(a); // Move constructor
    Buffer e(1);
    e = std::move(c);        // Move assignment

    b.print("b");
    d.print("d");
    e.print("e");

    return 0; // Observe destructor order and resources
}

