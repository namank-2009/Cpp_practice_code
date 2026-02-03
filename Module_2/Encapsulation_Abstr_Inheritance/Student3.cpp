#include <iostream>
#include "Student3.h"

using namespace std;

/*
  Constructor initializes the object to a SAFE default state.
*/
Student::Student() {
    name = "Unknown";
    rollNo = 0;
    marks = 0;
}

/*
  Setter for name.
  No validation needed here.
*/
void Student::setName(const string& n) {
    name = n;
}

/*
  Setter for roll number.
*/
void Student::setRollNo(int r) {
    rollNo = r;
}

/*
  Setter for marks with RANGE CHECKING.

  - Accepts only values between 0 and 100.
  - Rejects invalid values to maintain a valid object state.
*/
void Student::setMarks(int m) {
    if (m >= 0 && m <= 100) {
        marks = m;
    } else {
        cout << "Error: Marks must be between 0 and 100." << endl;
    }
}

/*
  Getter functions provide SAFE read-only access
  to private data members.
*/
string Student::getName() const {
    return name;
}

int Student::getRollNo() const {
    return rollNo;
}

int Student::getMarks() const {
    return marks;
}
