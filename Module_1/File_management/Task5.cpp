#include <iostream>
#include <cstdio>   // fopen, fclose, fread, fwrite, remove, rename

using namespace std;

struct Employee {
    int empId;
    char name[50];
    float salary;
};

int main() {
    FILE* originalFile = fopen("employee.dat", "rb");
    if (originalFile == NULL) {
        cout << "Error: employee.dat file not found." << endl;
        return 0;
    }

    FILE* tempFile = fopen("temp.dat", "wb");
    if (tempFile == NULL) {
        cout << "Error: Unable to create temporary file." << endl;
        fclose(originalFile);
        return 0;
    }

    Employee emp;
    int deleteId;
    bool found = false;

    cout << "Enter Employee ID to delete: ";
    cin >> deleteId;

    // Read records one by one
    while (fread(&emp, sizeof(Employee), 1, originalFile)) {
        if (emp.empId == deleteId) {
            found = true;    // Skip this record (soft delete)
        } else {
            fwrite(&emp, sizeof(Employee), 1, tempFile);
        }
    }

    fclose(originalFile);
    fclose(tempFile);

    if (found) {
        remove("employee.dat");
        rename("temp.dat", "employee.dat");
        cout << "Employee record deleted successfully." << endl;
    } else {
        remove("temp.dat");
        cout << "Employee record not found." << endl;
    }

    return 0;
}
