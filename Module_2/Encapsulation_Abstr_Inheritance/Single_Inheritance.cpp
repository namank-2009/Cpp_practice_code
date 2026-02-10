#include<iostream>
using namespace std;

// Person class that is common to tell the name and age of the person
class Person{
    private:
    string name;
    int age;

    public:
    Person(){
        name = "Unknown";
        age = 0;
    }

    void SetPerson(string name, int age){
        this->name = name;
        this->age = age;
    }

    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

// Student class inherits person class and tell about roll no and grade of student
class Student: public Person{
    int rollNo;
    char grade;

    public:
    void SetStudent(string n, int a, int roll, char grade){
        SetPerson(n,a);
        this->rollNo = roll;
        this->grade = grade;
    }
    void displayStudent(){
        display();
        cout<<"Roll No : "<<rollNo<<endl;
        cout<<"Grade: "<<grade<<endl;
    }
};

// Teacher class tells about teachers name, age, subject,salary 
class Teacher: public Person{
    string subject;
    double salary;

    public:
    void SetTeacher(string n, int a,string subject, double salary){
        SetPerson(n,a);
        this->subject = subject;
        this->salary = salary;
    }
    void displayTeacher(){
        display();
        cout<<"Subject  : "<<subject<<endl;
        cout<<"Salary: "<<salary<<endl;
    }

};

int main(){
    Student s;
    Teacher t;
    s.SetStudent("Naman", 20, 2237411,'A');
    // Display student information
    s.displayStudent();
    
    t.SetTeacher("Kritika",21,"Physical",50000);
    // Displays teachers information
    t.displayTeacher();
}