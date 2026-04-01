#include<iostream>
#include<set>
#include<vector>
#include<string>

bool scheduleEvent(std::set<int>& scheduledEvents, int startTime){
    auto insertResult = scheduledEvents.insert(startTime);
    if(insertResult.second){
        std::cout<<"Insertion is successful"<<"\n";
    }
    else{
        std::cout<<"Insertion is not successful the startTime already exists in the set"<<"\n";
        return false;
    }
    return true;
}

void displayScheduledEvents(const std::set<int>& events){
    if(events.empty()){
        std::cout<<"No events scheduled!"<<"\n";
    }

    for(auto time:events){
        std::cout << " - " << time << " minutes" << std::endl;
    }
    std::cout << "--------------------------------\n" << std::endl;
}
int main(){
    std::set<int> myCalendar;

    // Scenario 1: Initial Scheduling
    std::cout << "Attempting to schedule initial events:\n";
    scheduleEvent(myCalendar, 900);
    scheduleEvent(myCalendar, 1030);
    scheduleEvent(myCalendar, 1300);
    scheduleEvent(myCalendar, 1400);

    displayScheduledEvents(myCalendar);

    // Scenario 2: Conflict
    std::cout << "\nAttempting conflicting event:\n";
    scheduleEvent(myCalendar, 1030);

    displayScheduledEvents(myCalendar);

    // Scenario 3: New Event
    std::cout << "\nScheduling a new event:\n";
    scheduleEvent(myCalendar, 1200);

    displayScheduledEvents(myCalendar);

    // Scenario 4: Batch Scheduling
    std::cout << "\nBatch scheduling events:\n";
    std::vector<int> newEvents = {800, 1400, 1600, 900, 1800};

    for (int time : newEvents) {
        scheduleEvent(myCalendar, time);
    }

    displayScheduledEvents(myCalendar);

    return 0;
}


/*
#include <iostream>
#include <set>
#include <vector>
#include <string>   // ✅ Added as required

using namespace std;

// ---------------- Schedule Event ----------------
// Schedules an event if the time slot is free.
// Returns true if successful, false if conflict occurs.
bool scheduleEvent(set<int>& scheduledEvents, int startTime) {

    auto result = scheduledEvents.insert(startTime);

    if (result.second) {
        cout << "Event at " << startTime 
             << " minutes scheduled successfully." << endl;
        return true;
    } else {
        cout << "Conflict: Time slot " << startTime 
             << " minutes is already taken." << endl;
        return false;
    }
}

// ---------------- Display Events ----------------
// Displays all scheduled events in sorted order.
void displayScheduledEvents(const set<int>& events) {

    cout << "--------------------------------" << endl;
    cout << "Scheduled Events:" << endl;

    if (events.empty()) {
        cout << "  No events scheduled." << endl;
    } else {
        for (int time : events) {
            cout << "  - " << time << " minutes" << endl;
        }
    }

    cout << "--------------------------------" << endl;
}

// ---------------- Main ----------------
int main() {

    set<int> myCalendar;

    // Scenario 1: Initial Scheduling
    cout << "Attempting to schedule initial events:" << endl;
    scheduleEvent(myCalendar, 900);
    scheduleEvent(myCalendar, 1030);
    scheduleEvent(myCalendar, 1300);
    scheduleEvent(myCalendar, 1400);

    displayScheduledEvents(myCalendar);

    // Scenario 2: Conflict
    cout << "\nAttempting conflicting event:" << endl;
    scheduleEvent(myCalendar, 1030);

    displayScheduledEvents(myCalendar);

    // Scenario 3: New Event
    cout << "\nScheduling a new event:" << endl;
    scheduleEvent(myCalendar, 1200);

    displayScheduledEvents(myCalendar);

    // Scenario 4: Batch Scheduling
    cout << "\nBatch scheduling events:" << endl;

    vector<int> newEvents = {800, 1400, 1600, 900, 1800};

    for (int time : newEvents) {
        scheduleEvent(myCalendar, time);
    }

    displayScheduledEvents(myCalendar);

    return 0;
}*/