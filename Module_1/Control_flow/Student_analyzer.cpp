#include <stdio.h>

/* Global variable to demonstrate global scope & lifetime */
static int totalStudentsProcessed = 0;

int main() {
    char choice;

    do {
        int studentID;
        int numAssignments;
        int validCount = 0;
        int totalGrades = 0;

        /* Student ID validation using while loop */
        while (1) {
            printf("Enter Student ID (e.g., 101-999): ");
            scanf("%d", &studentID);

            if (studentID >= 101 && studentID <= 999) {
                break;
            } else {
                printf("Invalid Student ID. Must be between 101 and 999. Please re-enter.\n");
            }
        }

        /* Number of assignments */
        printf("How many assignments does Student %d have? ", studentID);
        scanf("%d", &numAssignments);

        /* Assignment grade input using for loop */
        for (int i = 1; i <= numAssignments; i++) {
            int grade;
            printf("Enter grade for Assignment #%d (0-100): ", i);
            scanf("%d", &grade);

            /* Grade validation using continue */
            if (grade < 0 || grade > 100) {
                printf("Invalid grade. Must be between 0 and 100. Skipping this assignment.\n");
                continue;
            }

            totalGrades += grade;
            validCount++;
        }

        /* Output and performance feedback */
        if (validCount == 0) {
            printf("No valid grades entered for Student %d.\n", studentID);
        } else {
            float average = (float) totalGrades / validCount;
            printf("Student %d - Average Grade: %.2f%%\n", studentID, average);

            if (average >= 90) {
                printf("Excellent!\n");
            } else if (average >= 70) {
                printf("Good job!\n");
            } else if (average >= 50) {
                printf("Needs improvement.\n");
            } else {
                printf("At risk.\n");
            }
        }
        totalStudentsProcessed++;
        /* Main loop continuation */
        printf("Process another student? (Y/N): ");
        scanf(" %c", &choice);

        if (choice == 'N' || choice == 'n') {
            break;   // exit do-while loop
        }

    } while (1);

    printf("Total students processed: %d\n", totalStudentsProcessed);
    printf("Exiting Grade Analyzer. Goodbye!\n");

    return 0;
}