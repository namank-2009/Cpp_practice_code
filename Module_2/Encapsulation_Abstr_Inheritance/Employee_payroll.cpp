#include<iostream>
#include<vector>
using namespace std;

//Abstract Base Class
class Employees{
    private:
        string name;
        int id;
    
        void setName(string name){
            this->name = name;
        }

        void setId(int id){
            if(id>0){
                this->id = id;
            }
            else{
                cout<<"Enter a valid id"<<endl;
            }
        }

    public:
        Employees(const string &name, int id){
            setId(id);
            setName(name);
        }
        string getName() const{
            return name;
        }
        int getId() const{
            return id;
        }
        virtual double calculatePay() const = 0;
        virtual ~Employees()= default;
};


//  Salaried Employee
class SalariedEmployee : public Employees{
    protected:
        double salary;
         void setSalary(double salary){
            if(salary>0){
                this->salary = salary;
            }
            else{
                cout<<"Enter a valid salary"<<endl;
            }
        }
    public:
        SalariedEmployee(string name, int id, double salary) :Employees(name,id){
            setSalary(salary);
        }
       
        double calculatePay() const override{
            cout << "Salaried Employee: " << getName()
             << " | Monthly Salary: " << salary << endl;
             return salary;
        }
};

// Hourly Employee
class HourlyEmployee : public Employees{

    int hourlyRate;
    int hoursWorked;
    void sethourlyRate(int hourRate){
            if(hourRate>0){
                this->hourlyRate = hourRate;
            }
            else{
                cout<<"Enter a valid hourRate"<<endl;
            }
        }

        void sethourlyWorked(int hourWorked){
            if(hourWorked>=0){
                this->hoursWorked = hourWorked;
            }
            else{
                cout<<"Enter a valid hoursWorked"<<endl;
            }
        }
    public:
        HourlyEmployee(string name, int id, int hourRate,int hourWorked) : Employees(name,id){
            sethourlyRate(hourRate);
            sethourlyWorked(hourWorked);
        }
        
    double calculatePay() const override{
        cout << "Hourly Employee: " << getName()
            << " | Pay: " << hourlyRate * hoursWorked << endl;
            return hourlyRate * hoursWorked;
    }
};

//Main
int main(){
    vector<Employees*>payroll;

    payroll.push_back(new SalariedEmployee("Naman",68321,590009.00));
    payroll.push_back(new HourlyEmployee("Kritika", 200000, 500, 12));
    
    for (const Employees* emp : payroll) {
        emp->calculatePay();   // Polymorphism
    }

    for (Employees* emp : payroll)
        delete emp;
}
