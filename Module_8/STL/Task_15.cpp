#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// =========================================
// PATIENT STRUCT
// =========================================
struct Patient {
    string name;
    int severity;      // 1 = most critical, 5 = least
    int arrivalTime;   // smaller = earlier

    Patient(string n, int s, int t) {
        name = n;
        severity = s;
        arrivalTime = t;
    }
};

// =========================================
// CUSTOM COMPARATOR
// =========================================
struct ComparePatients {

    // Returns true if p1 has LOWER priority than p2
    bool operator()(const Patient& p1, const Patient& p2) const {

        // PRIMARY RULE: Lower severity value = higher priority
        if (p1.severity > p2.severity) {
            return true;   // p1 lower priority
        }
        if (p1.severity < p2.severity) {
            return false;  // p1 higher priority
        }

        // TIE BREAKER: Earlier arrival = higher priority
        if (p1.arrivalTime > p2.arrivalTime) {
            return true;   // p1 lower priority
        }
        if (p1.arrivalTime < p2.arrivalTime) {
            return false;  // p1 higher priority
        }

        // Equal priority
        return false;
    }
};

// =========================================
// MAIN FUNCTION
// =========================================
int main() {

    // Priority Queue with custom comparator
    priority_queue<Patient, vector<Patient>, ComparePatients> erQueue;

    // =========================================
    // ADDING PATIENTS
    // =========================================
    erQueue.push(Patient("Alice", 3, 10));   // S3 A10
    erQueue.push(Patient("Bob", 1, 5));      // S1 A5
    erQueue.push(Patient("Charlie", 3, 8));  // S3 A8
    erQueue.push(Patient("David", 2, 12));   // S2 A12
    erQueue.push(Patient("Eve", 1, 7));      // S1 A7
    erQueue.push(Patient("Frank", 5, 2));    // S5 A2

    cout << "===== Emergency Room Triage =====\n\n";

    // =========================================
    // PROCESSING PATIENTS
    // =========================================
    while (!erQueue.empty()) {

        Patient current = erQueue.top();

        cout << "Processing Patient: "
             << current.name
             << " | Severity: " << current.severity
             << " | Arrival: " << current.arrivalTime
             << endl;

        erQueue.pop();
    }

    return 0;
}