#include<iostream>
using namespace std;

int main(){
    // Defining the values to the Variables for an IOT based Sensor Monitoring System
    const int sensorID = 102; // sensorID is made constant because it is fixed and cannot be changed during program excution
    char sensorType = 'A';
    float temperature = 70.2;  // The temperature can vary from 60 degree to 90 degree
    double humidity= 62.232; // Humidity level increase as more machines are used
    bool systemActive = true;  // system is in active state if we are using it else inactive
    short shortValue = 25;
    long longValue = 100000L;
    long long bigValue = 1234567890123LL;
    unsigned int packetCount = 500;
    unsigned char statusCode = 'E';

    //Printing all the Variable values
    cout<<"Sensor Type : "<<sensorType<<endl;
    cout<<"Sensor ID : "<<sensorID<<endl;
    cout<<"Temperature Reading : "<<temperature <<" degree C"<<endl;
    cout<<"Humidity level : "<<humidity<<endl;
    cout<<"System Active : "<<systemActive<<endl;
    cout<<"Short Value : "<<shortValue<<endl;
    cout<<"Long Value : "<<longValue<<endl;
    cout<<"Big Value : "<<bigValue<<endl;
    cout<<"Unsigned Int (Packets) : "<<packetCount<<endl;
    cout<<"Unsigned char (Status) : "<<statusCode<<endl;

    return 0;
}