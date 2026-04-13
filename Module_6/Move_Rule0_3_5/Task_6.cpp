#include <iostream>
#include <cstring>

class ResourceHolder {
    int* data;
    size_t size;
public:
    ResourceHolder(size_t sz) : size(sz) {
        data = new int[size];
        for (size_t i = 0; i < size; ++i) data[i] = i * 11;
        std::cout << "Constructor: allocated at " << static_cast<void*>(data) << "\n";
    }
    // Copy constructor (deep copy)
    ResourceHolder(const ResourceHolder& other) : size(other.size) {
        data = new int[size];
        std::memcpy(data, other.data, size * sizeof(int));
        std::cout << "Copy constructor: copied to " << static_cast<void*>(data) << "\n";
    }
    // Copy assignment operator (deep copy with self-assignment check)
    ResourceHolder& operator=(const ResourceHolder& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::memcpy(data, other.data, size * sizeof(int));
            std::cout << "Copy assign: copied to " << static_cast<void*>(data) << "\n";
        }
        return *this;
    }
    // Destructor (cleanup)
    ~ResourceHolder() {
        std::cout << "Destructor: freeing " << static_cast<void*>(data) << std::endl;
        delete[] data;
    }
    
    void print(const char* label) const {
        std::cout << label << " data at " << static_cast<const void*>(data) << ": [ ";
        for (size_t i = 0; i < size; ++i) std::cout << data[i] << " ";
        std::cout << "]" << std::endl;
    }
};

int main() {
    ResourceHolder a(5);
    a.print("a: ");

    ResourceHolder b = a; // Copy constructor
    b.print("b: ");

    ResourceHolder c(3);
    c.print("c: ");
    c = a;                // Copy assignment
    c.print("c (after = a): ");
    a.print("a after assignment: ");

    return 0;
}
