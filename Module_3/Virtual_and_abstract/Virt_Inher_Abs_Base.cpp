#include<iostream>
using namespace std;

class Person{
    public:
    string name;
    int id;

    Person(const string& name, int id) : name(name),id(id) {
        cout << "Person Constructor\n";
    }
    virtual void displayInfo() const = 0;

    virtual ~Person(){
        cout << "Person Destructor\n";
    }
};

// Student inherits Person virtually
class Student: virtual public Person{
    public:
    int rollNo;
    Student(const string& name,int id, int rollNo)
        : Person(name,id), rollNo(rollNo) {
        cout << "Student Constructor\n";
    }
};

// Employee inherits Person virtually
class Employee: virtual public Person{
    public:
    double salary;
    Employee(const string& name,int id, double salary)
        : Person(name,id), salary(salary) {
        cout << "Employee Constructor\n";
    }
};


// TeachingAssistant combines both roles
class TeachingAssistant : public Student, public Employee { 
    public:
    TeachingAssistant(const string& name,int id, int rollNo, double salary)
        : Person(name,id),        // virtual base initialized HERE
          Student(name,id,rollNo),
          Employee(name,id,salary) {
        cout << "TeachingAssistant Constructor\n";
    }

    // Implement abstract function
    void displayInfo() const override {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Salary: " << salary << endl;
    }

    ~TeachingAssistant() {
        cout << "TeachingAssistant Destructor\n";
    }
};

int main(){
TeachingAssistant ta("Naman",11, 101, 45000);

    cout << "\n--- Display Info ---\n";
    ta.displayInfo();

    cout << "\n--- Person subobject addresses ---\n";
    Person* viaStudent  = static_cast<Person*>(static_cast<Student*>(&ta));
    Person* viaEmployee = static_cast<Person*>(static_cast<Employee*>(&ta));

    cout << "Via Student:  " << viaStudent << endl;
    cout << "Via Employee: " << viaEmployee << endl;

    if (viaStudent == viaEmployee) {
        cout << "Confirmed: Only ONE Person subobject exists.\n";
    }

    return 0;
}