#include<iostream>
using namespace std;

class Person{
    string name;
    int age;

    public:
    Person() : name(""), age(0) {}   // Default constructor (important for input)
    Person(string n, int a) : name(n), age(a) {}

    friend istream& operator>>(std::istream& is, Person& p){
        cout<<"Enter name: "<<endl;
        getline(is>>ws,p.name);

        cout<<"Enter the age: "<<endl;
        is>>p.age;

        return is;
    }

    friend ostream& operator<<(std::ostream& os, const Person& p){
        os<<"\nName: "<<p.name
            <<"\n Age "<<p.age<<endl;
            return os;
    }
};

int main(){
    Person p1, p2;

    // 🔹 Chained input
    cin >> p1 >> p2;

    // 🔹 Chained output
    cout << "\n---- Person Details ----\n";
    cout << p1 << p2;
    
}