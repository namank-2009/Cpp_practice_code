#include<iostream>
using namespace std;

// Student class 
class Student{
    private:
    string name;
    int marks;

    public:
    //Parameterized constructor
    Student(string n, int m){
        name = n;
        marks = m;
    }

    // Friend class stated
    friend class Result;
};

// Friend class
class Result{
    public:
    void display(const Student& s){
        cout<<"Name: "<<s.name<<" Marks: "<<s.marks<<endl;
        if(s.marks>=40){
            cout<<s.name<<" is passed!"<<endl;
        }
        else{
            cout<<s.name<<" is failed!"<<endl;
        }
    }
};

int main(){
    Student s("Alice",72);
    Result r;
    // Calling the display function in result class which is 
    // accessing the private members of student class
    r.display(s);
}