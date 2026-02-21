#include<iostream>
#include <stdexcept>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

class MedicalMemoryTracker {
    public:
    static int totalMemAllocated;
    static int totalMemDeallocated;
    
    static void recordAllocation(const char* medicalResource, int size){
        totalMemAllocated+=size;
        cout << "[ALLOCATED] " << medicalResource<< " | Size: " << size << " bytes\n";
    }

    static void recordDeallocation(const char* medicalResource, int size){
        totalMemDeallocated += size;
        cout << "[DEALLOCATED] " << medicalResource<< " | Size: " << size << " bytes\n";
    }

    static void reportLeaks(){
        cout << "\n--------MEMORY REPORT --------\n";
        cout << "Total Allocated:   " << totalMemAllocated << " bytes\n";
        cout << "Total Deallocated: " << totalMemDeallocated << " bytes\n";

        if (totalMemAllocated - totalMemDeallocated == 0)
            cout << "No memory leak detected.\n";
        else
            cout << "MEMORY LEAK DETECTED: "
                 << (totalMemAllocated - totalMemDeallocated)
                 << " bytes not freed!\n";

        cout << "-----------------------------\n";
    }

    static void reset(){
        totalMemAllocated = 0;
        totalMemDeallocated = 0;
    }
};

int MedicalMemoryTracker::totalMemAllocated = 0;
int MedicalMemoryTracker::totalMemDeallocated = 0;

class MedicalDeviceException : public runtime_error{
    string message;
    public:
    MedicalDeviceException(const string& msg):runtime_error(msg){}
};

class PatientDataException  : public runtime_error{
    string message;
    public:
    PatientDataException(const string& msg): runtime_error(msg){}
};

class PatientVitalMonitor {
    private:
        int* heartRateData;
        float* bloodPressureData;
        bool deviceConnected;
        char patientId[50];
    public:
        void connectToMedicalDevice(){
            if (rand() % 2 == 0) {
            throw MedicalDeviceException(
                "E101: Medical device connection failed!");
        }
        deviceConnected = true;
             
        }
        void calibrateSensors(){
            if (rand() % 2 == 0) {
                throw MedicalDeviceException(
                "E102: Sensor calibration failed!");
            }
        }
        void validatePatientData(){
            if (rand() % 2 == 0) {
                throw PatientDataException(
                "E303: Corrupted vital signs detected!");
            }
        }
        void analyzeCriticalTrend(){
            if (rand() % 2 == 0) {
                throw PatientDataException(
                "E404: Critical trend analysis failed!");
            }
        }

    PatientVitalMonitor(const char* id):heartRateData(nullptr),bloodPressureData(nullptr),deviceConnected(false){
        strcpy(patientId, id);

        heartRateData = new int[36000];
        MedicalMemoryTracker::recordAllocation("Heart Rate Buffer", 36000 * sizeof(int));

        bloodPressureData = new float[18000];
        MedicalMemoryTracker::recordAllocation("Blood Pressure Buffer", 18000 * sizeof(float));

        connectToMedicalDevice();   // Might throw
        calibrateSensors();         // Might throw

        cout << "Monitor setup successful for Patient: " << patientId << endl;
    }
    ~PatientVitalMonitor() {
        cout << "Shutting down monitor for Patient: "
             << patientId << endl;

        if (heartRateData) {
            delete[] heartRateData;
            MedicalMemoryTracker::recordDeallocation(
                "Heart Rate Buffer", 36000 * sizeof(int));
        }

        if (bloodPressureData) {
            delete[] bloodPressureData;
            MedicalMemoryTracker::recordDeallocation(
                "Blood Pressure Buffer", 18000 * sizeof(float));
        }
    }

    void monitorPatientVitals(int durationMinutes) {

        if (durationMinutes <= 0) {
            throw invalid_argument(
                "E001: Monitoring duration must be positive!");
        }

        float* ecgAnalysisBuffer = new float[5000];
        MedicalMemoryTracker::recordAllocation(
            "ECG Analysis Buffer", 5000 * sizeof(float));

        validatePatientData();   // Might throw → leak ecg buffer

        int* criticalTrendBuffer = new int[1000];
        MedicalMemoryTracker::recordAllocation(
            "Critical Trend Buffer", 1000 * sizeof(int));

        analyzeCriticalTrend();  // Might throw → multiple leaks

        cout << "Monitoring in progress...\n";

        delete[] ecgAnalysisBuffer;
        MedicalMemoryTracker::recordDeallocation(
            "ECG Analysis Buffer", 5000 * sizeof(float));

        delete[] criticalTrendBuffer;
        MedicalMemoryTracker::recordDeallocation(
            "Critical Trend Buffer", 1000 * sizeof(int));
    }
};

int main() {

    cout << "Medical Patient Monitor System\n";

    srand(static_cast<unsigned>(time(nullptr)));

    int attempts;
    cout << "Enter number of monitoring attempts (5-10): ";
    cin >> attempts;

    MedicalMemoryTracker::reset();

    PatientVitalMonitor* emergencyMonitor = nullptr;
    bool setupSuccessful = false;

    while (attempts--) {

        try {
            emergencyMonitor =
                new PatientVitalMonitor("EMERGENCY-001");

            setupSuccessful = true;
            cout << "Device setup successful!\n";
        }
        catch (const MedicalDeviceException& e) {
            cout << "Device Setup Failed: "
                 << e.what() << endl;
        }

        if (setupSuccessful && emergencyMonitor) {

            try {
                emergencyMonitor->monitorPatientVitals(10);
            }
            catch (const PatientDataException& e) {
                cout << "Patient Data Error: "
                     << e.what() << endl;
            }

            delete emergencyMonitor;
            emergencyMonitor = nullptr;
            setupSuccessful = false;
        }
    }

    MedicalMemoryTracker::reportLeaks();

    return 0;
}