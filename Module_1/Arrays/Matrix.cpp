#include <iostream>
#include <vector>
using namespace std;

// Input matrix
void inputMatrix(vector<vector<int>> &mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
}

// Display matrix
void displayMatrix(const vector<vector<int>> &mat) {
    for (const auto &row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Addition
vector<vector<int>> addMatrices(const vector<vector<int>> &A,
                                const vector<vector<int>> &B,
                                int rows, int cols) {
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
    return result;
}

// Subtraction
vector<vector<int>> subtractMatrices(const vector<vector<int>> &A,
                                     const vector<vector<int>> &B,
                                     int rows, int cols) {
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] - B[i][j];
    return result;
}

// Multiplication
vector<vector<int>> multiplyMatrices(const vector<vector<int>> &A,
                                     const vector<vector<int>> &B,
                                     int r1, int c1, int c2) {
    vector<vector<int>> result(r1, vector<int>(c2, 0));
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

// Transpose
vector<vector<int>> transposeMatrix(const vector<vector<int>> &A,
                                    int rows, int cols) {
    vector<vector<int>> result(cols, vector<int>(rows));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = A[i][j];
    return result;
}

int main() {
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of Matrix B: ";
    cin >> r2 >> c2;

    // Validate dimensions
    if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0) {
        cout << "Error: Matrix dimensions must be greater than zero.\n";
        return 0;
    }

    vector<vector<int>> A(r1, vector<int>(c1));
    vector<vector<int>> B(r2, vector<int>(c2));

    cout << "Enter elements of Matrix A:\n";
    inputMatrix(A, r1, c1);

    cout << "Enter elements of Matrix B:\n";
    inputMatrix(B, r2, c2);

    cout << "\nChoose Operation:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Transpose of Matrix A\n";
    cout << "Enter choice: ";

    int choice;
    cin >> choice;

    vector<vector<int>> result;

    switch (choice) {
        case 1:
            if (r1 != r2 || c1 != c2) {
                cout << "Error: Matrices must have same dimensions for addition.\n";
                return 0;
            }
            result = addMatrices(A, B, r1, c1);
            cout << "\nResult of Addition:\n";
            displayMatrix(result);
            break;

        case 2:
            if (r1 != r2 || c1 != c2) {
                cout << "Error: Matrices must have same dimensions for subtraction.\n";
                return 0;
            }
            result = subtractMatrices(A, B, r1, c1);
            cout << "\nResult of Subtraction:\n";
            displayMatrix(result);
            break;

        case 3:
            if (c1 != r2) {
                cout << "Error: Columns of Matrix A must equal rows of Matrix B.\n";
                return 0;
            }
            result = multiplyMatrices(A, B, r1, c1, c2);
            cout << "\nResult of Multiplication:\n";
            displayMatrix(result);
            break;

        case 4:
            result = transposeMatrix(A, r1, c1);
            cout << "\nTranspose of Matrix A:\n";
            displayMatrix(result);
            break;

        default:
            cout << "Invalid operation selected.\n";
    }

    return 0;
}
