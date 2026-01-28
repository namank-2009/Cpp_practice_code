#include<stdio.h>

int main(){
    /* Sensor Configuration Variables*/

    char sensorRegionCode = 'N'; // Defined sensor code from 'N', 'S', 'E', 'W'
    int currentReadingID = 12; // Current Reading Id
    float averageSoilMoisture = 90; // Average soil moisture percentage
    double lightIntensity = 23.123; // Precise light intensity in lumens
    short temperature = 40; // Temperature is in degree Celsius and we use short here for memory efficiency
    long totalReadingFromStart= 6; // total number of readings collected since device start
    unsigned int thresholdForServerData = 4; // threshold for sending data to server
    unsigned char sensorModeFlag = 0x01; // sensor mode flag

    /* Printing the variable for a smart agriculture system*/

    printf("Sensor Region %c\n", sensorRegionCode);
    printf("Current Reading ID %d\n", currentReadingID);
    printf("Average Soil Moisture %.2f \n", averageSoilMoisture );
    printf("Light Intensity %.6f lumens\n", lightIntensity);
    printf("Temperature %d °C\n", temperature);
    printf("Total Readings collected %ld\n", totalReadingFromStart);
    printf("Server Threshold %u readings\n", thresholdForServerData);
    printf("Sensor Mode Flag 0x%02x\n", sensorModeFlag);

    return 0;
}