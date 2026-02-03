#ifndef STUDENT_H
#define STUDENT_H

#include <string>

/*
  Student class declaration (INTERFACE).
  - Only declarations are present here.
  - Data members are PRIVATE to enforce encapsulation.
  - Users of this class can only interact through public functions.
*/
class Student {
private:
    std::string name;  // Student name (hidden from outside)
    int rollNo;        // Roll number (hidden)
    int marks;         // Marks (0–100 only)

public:
    // Constructor
    Student();

    // Setters (with validation where needed)
    void setName(const std::string& n);
    void setRollNo(int r);
    void setMarks(int m);

    // Getters (read-only access)
    std::string getName() const;
    int getRollNo() const;
    int getMarks() const;
};

#endif
