#include <stdio.h>
#include <string.h>

/*  Defining the Employee structure (Global Scope) */
struct Employee {
    char name[50];
    int employee_id;
    float salary;
};

/*  Function to print employee details (Pass by Value) */
void printEmployeeDetails(struct Employee emp) {
    printf("Employee Name   : %s\n", emp.name);
    printf("Employee ID     : %d\n", emp.employee_id);
    printf("Employee Salary : %.2f\n", emp.salary);
    printf("-----------------------------\n");
}

int main() {

    /*  Managing a Single Employee */
    struct Employee emp1;

    strcpy(emp1.name, "Naman Gupta");
    emp1.employee_id = 101;
    emp1.salary = 75000.50;

    printf("Single Employee Details:\n");
    printf("-----------------------------\n");
    printEmployeeDetails(emp1);

    /* Managing Multiple Employees using Array */
    struct Employee staff[4];

    /* Initializing employee records */
    strcpy(staff[0].name, "Amit Sharma");
    staff[0].employee_id = 201;
    staff[0].salary = 60000.00;

    strcpy(staff[1].name, "Neha Verma");
    staff[1].employee_id = 202;
    staff[1].salary = 65000.75;

    strcpy(staff[2].name, "Rohit Kumar");
    staff[2].employee_id = 203;
    staff[2].salary = 72000.25;

    strcpy(staff[3].name, "Priya Singh");
    staff[3].employee_id = 204;
    staff[3].salary = 68000.00;

    printf("\nEmployee Records (Array of Structures):\n");
    printf("-----------------------------\n");

    /* Loop through array and print details */
    for (int i = 0; i < 4; i++) {
        printEmployeeDetails(staff[i]);
    }

    return 0;
}
