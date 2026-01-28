#include <stdio.h>
#include <stdlib.h>

// Structure to store employee information
struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    struct Employee *empPtr = NULL;

    /* Dynamically allocate memory for one Employee */
    empPtr = (struct Employee *)malloc(sizeof(struct Employee));

    /* Check if memory allocation was successful */
    if (empPtr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        return 1;
    }

    /* Take initial employee details from user */
    printf("Enter Employee ID: ");
    scanf("%d", &empPtr->id);

    printf("Enter Employee Name: ");
    scanf(" %49[^\n]", empPtr->name);   // safe input for name

    printf("Enter Employee Salary: ");
    scanf("%f", &empPtr->salary);

    /*  Print initial employee details */
    printf("\n--- Initial Employee Details ---\n");
    printf("ID     : %d\n", empPtr->id);
    printf("Name   : %s\n", empPtr->name);
    printf("Salary : %.2f\n", empPtr->salary);

    /* Update salary using pointer */
    float newSalary;
    printf("\nEnter New Salary: ");
    scanf("%f", &newSalary);

    empPtr->salary = newSalary;   // updating via pointer

    /* Print updated employee details */
    printf("\n--- Updated Employee Details ---\n");
    printf("ID     : %d\n", empPtr->id);
    printf("Name   : %s\n", empPtr->name);
    printf("Salary : %.2f\n", empPtr->salary);

    /* Free allocated memory */
    free(empPtr);
    empPtr = NULL;   // prevent dangling pointer

    return 0;
}
