#include <iostream>
#include <vector>
using namespace std;

// Base Matrix class
class Matrix {
protected:
    int rows, cols;
    vector<vector<int>> data;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<int>(c, 0)) {}

    // Compile-time polymorphism: overloaded setValue functions
    void setValue(int r, int c, int value) {
        if (r < rows && c < cols)
            data[r][c] = value;
    }

    void setValue(double r, double c, double value) {
        // Convert double indices to int
        int row = static_cast<int>(r);
        int col = static_cast<int>(c);
        if (row < rows && col < cols)
            data[row][col] = static_cast<int>(value);
    }

    // Overload + operator for element-wise addition
    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = this->data[i][j] + other.data[i][j];
        return result;
    }

    // Virtual function for run-time polymorphism
    virtual void display() const {
        cout << "Matrix (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }

    virtual ~Matrix() {}
};

// Derived class: SquareMatrix
class SquareMatrix : public Matrix {
public:
    SquareMatrix(int n) : Matrix(n, n) {}

    void display() const override {
        cout << "SquareMatrix (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

// Derived class: IdentityMatrix
class IdentityMatrix : public Matrix {
public:
    IdentityMatrix(int n) : Matrix(n, n) {
        // Fill data with 1s on the diagonal
        for (int i = 0; i < n; i++)
            data[i][i] = 1;
    }

    void display() const override {
        cout << "IdentityMatrix (" << rows << "x" << cols << "):" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};


int main() {
    // Compile-time polymorphism
    SquareMatrix sq(3);
    sq.setValue(0, 0, 5);        // int version
    sq.setValue(1.0, 1.0, 10.5); // double version
    cout << "SquareMatrix after setValue calls:" << endl;
    sq.display();

    IdentityMatrix id(3);
    cout << "\nIdentityMatrix:" << endl;
    id.display();

    // Operator + (compile-time)
    Matrix sum = sq + id; // Matrix + Matrix
    cout << "\nSum of SquareMatrix + IdentityMatrix:" << endl;
    sum.display();

    // Run-time polymorphism
    cout << "\nDemonstrating run-time polymorphism with base pointers:" << endl;
    Matrix* matrices[2];
    matrices[0] = &sq;
    matrices[1] = &id;

    for (Matrix* m : matrices) {
        m->display(); // Correct display() called dynamically
        cout << endl;
    }

    return 0;
}
