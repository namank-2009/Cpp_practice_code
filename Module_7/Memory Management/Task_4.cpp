#include<iostream>
#include<string>
#include<memory>
using namespace std;

class LogMessage{
    string message_content;
    public:
    LogMessage(const string& message){
        message_content = message;
        std::cout << "LogMessage '" << message_content << "' created. Address: " << this << std::endl;
    }

    ~LogMessage(){
        std::cout << "LogMessage '" << message_content << "' destroyed. Address: " << this << std::endl;
    }

    void printContent(){
        cout<<message_content<<endl;
    }
    
};

void handleLegacyLog(LogMessage* rawMessage){
        if(rawMessage == nullptr){
            std::cout << "Legacy system received a nullptr log.\n";
            return; 
        }
        cout<<"Legacy system is now handling log: [Content of message]";
        rawMessage->printContent();
        delete rawMessage;

        cout<<"The legacy system has finished processing and deleting the message";
}

class SensorReport {

private:
    int rawSensorValue;
    string sensorIdentifier;

public:

    SensorReport(int value, string id)
        : rawSensorValue(value), sensorIdentifier(id)
    {
        cout << "SensorReport CREATED for sensor: "
             << sensorIdentifier << endl;
    }

    ~SensorReport(){
        cout << "SensorReport DESTROYED for sensor: "
             << sensorIdentifier << endl;
    }

    void displayDetails(){
        cout << "Sensor ID: " << sensorIdentifier
             << " | Value: " << rawSensorValue << endl;
    }
};

int main(){
    cout << "Creating unique_ptr managed LogMessage\n";

    // unique_ptr managing resource
    unique_ptr<LogMessage> myLog =
        make_unique<LogMessage>("System Startup Event");

    cout << "unique_ptr created and managing log.\n";

    myLog->printContent();

    // release ownership
    LogMessage* handedOverLog = myLog.release();

    cout << "\nOwnership released from unique_ptr\n";

    // pass to legacy system
    handleLegacyLog(handedOverLog);

    // check unique_ptr state
    if (!myLog)
        cout << "myLog unique_ptr is now empty (nullptr) after release().\n";
    else
        cout << "Error: myLog unique_ptr is NOT empty!\n";

    int rawSensorValue = 87;
    string sensorIdentifier = "TempSensor_A1";

    // unique_ptr managing SensorReport
    unique_ptr<SensorReport> criticalReportPtr =
        make_unique<SensorReport>(rawSensorValue, sensorIdentifier);

    cout << "\nProcessing critical sensor report:\n";

    // Access object using ->
    criticalReportPtr->displayDetails();
    
    cout << "\nProgram finished.\n";

    return 0;
}