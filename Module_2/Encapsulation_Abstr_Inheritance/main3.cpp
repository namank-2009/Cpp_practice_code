#include <iostream>
#include "Student3.h"


using namespace std;

int main() {
    Student s;

    // Setting values using public setters
    s.setName("Naman");
    s.setRollNo(101);
    s.setMarks(85);

    // Displaying values using getters
    cout << "Name: " << s.getName() << endl;
    cout << "Roll No: " << s.getRollNo() << endl;
    cout << "Marks: " << s.getMarks() << endl;

    cout << endl;

    // Attempting to set INVALID marks
    s.setMarks(-10);   // rejected
    s.setMarks(120);   // rejected

    cout << "Marks after invalid input attempts: "
         << s.getMarks() << endl;

    /*
      The following lines would cause COMPILATION ERRORS
      because data members are private.
      This proves ENCAPSULATION.

      s.marks = 50;
      s.name = "Test";
      s.rollNo = 1;
    */

    return 0;
}
