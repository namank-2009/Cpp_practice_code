#include<iostream>
using namespace std;

class Student{
    public:
    int rollNo;
    string name;
    char grade;

    Student(){
        rollNo = 0;
        name = "Unknown";
        grade = 'A';
        cout<<"Deafult Constructor is called"<<endl;
    }

    Student(int r, string n, char g)
    : rollNo(r),name(n),grade(g){
         cout<<"Parameterized Constructor is called"<<endl;
    }

    void print(){
        cout<<"Name is"<<name<<endl;
        cout<<"Roll no is "<<rollNo<<endl;
        cout<<"Grade is "<<grade<<endl;
    }
};

int main(){
    //Default constructor will be called 
    Student s;
    s.print();

    //Parameterized constructor will be called
    Student s2(101,"Naman",'A');
    s2.print();
}