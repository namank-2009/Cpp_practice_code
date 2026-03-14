#include<iostream>
#include<string>
#include<memory>
using namespace std;

class SensorReport{
    int value;
    string sensorName;
    public:
    SensorReport(int val, const string& name){
        this->value = val;
        this->sensorName = name;
        cout<<"SensorReport for "<<sensorName<<" created"<<endl;
    }

    void displayDetails(){
        cout<<"SensorName: "<<sensorName<<", Value: "<<value<<endl;
    }

    ~SensorReport(){
        cout<<"SensorReport for "<<sensorName<<" destroyed!"<<endl;
    }
};

int main(){
    int rawSensorValue = 75;  
    string sensorIdentifier = "Pressure_A01";
    unique_ptr<SensorReport>criticalReportPtr  = make_unique<SensorReport>(rawSensorValue,sensorIdentifier);

    std::cout << "\nProcessing critical sensor report:" << std::endl; 
    criticalReportPtr->displayDetails();

// Demonstrating unique ownership (will cause compile error if uncommented)
    // unique_ptr<SensorReport> anotherReport = criticalReportPtr;
    cout << "\nProgram finishing..." << endl;

    return 0;
}