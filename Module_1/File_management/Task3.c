#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void appendAttendance(int empId, char timestamp[]) {
    FILE *fp = fopen("attendance.txt", "a");
    if (fp == NULL) {
        printf("Error: Unable to open attendance file for appending.\n");
        return;
    }

    fprintf(fp, "%d, %s", empId, timestamp);
    fclose(fp);

    printf("Attendance successfully logged.\n");
}

void displayAttendanceLog() {
    FILE *fp = fopen("attendance.txt", "r");
    if (fp == NULL) {
        printf("No attendance records found.\n");
        return;
    }

    char buffer[200];
    int isEmpty = 1;

    printf("\n----- Attendance Log -----\n");
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
        isEmpty = 0;
    }

    if (isEmpty)
        printf("No attendance records found.\n");

    fclose(fp);
}

int main() {
    int empId;
    char timestamp[100];

    printf("Enter Employee ID: ");
    scanf("%d", &empId);

    if (empId <= 0) {
        printf("Invalid Employee ID.\n");
        return 1;
    }

    getchar(); // clear newline buffer

    printf("Enter Timestamp (e.g., 2025-09-20 09:30 AM): ");
    fgets(timestamp, sizeof(timestamp), stdin);

    if (strlen(timestamp) <= 1) {
        printf("Invalid timestamp.\n");
        return 1;
    }

    appendAttendance(empId, timestamp);
    displayAttendanceLog();

    return 0;
}
