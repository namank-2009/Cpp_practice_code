#include <iostream>
#include <vector>
#include <initializer_list>

class Matrix {
    std::vector<std::vector<int>> data;
public:
    // Taking the initializer list and inserting the elements to data vector
    Matrix(std::initializer_list<std::initializer_list<int>> list) {
        for (const auto& row : list) {
            data.emplace_back(row);
        }
    }

    // Function to first print and then double the element of the matrix
    void printAndDouble() {
        std::cout << "Matrix elements:" << std::endl;
        for (auto& row : data) {
            for (auto& col : row) {
                std::cout << col << " ";
                col *= 2; // Modify in-place
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // Function to print the value of matrix
    void print() const {
        std::cout << "Matrix elements:" << std::endl;
        for (const auto& row : data) {
            for (const auto& col : row) {
                std::cout << col << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Passing the value to constructor
    Matrix mat{
        {1, 2},
        {3, 4}
    };

    // Calling the print and double function
    mat.printAndDouble();
    
    std::cout << "After doubling:" << std::endl;
    mat.print();

    return 0;
}
