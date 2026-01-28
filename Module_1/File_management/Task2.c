#include<stdio.h>
#include<stdlib.h>

struct Employee{
    int empId;
    char name[50];
    float basicSalary;
};

int main(){
    FILE *fp;
    struct Employee e;

   fp = fopen("employee.dat", "rb");
    if (fp == NULL) {
        printf("Error: employee.dat file not found!\n");
        return;
    }

    while (fread(&e, sizeof(struct Employee), 1, fp)) {

        if (e.basicSalary <= 0)
            continue;

        float DA = e.basicSalary * 0.50;
        float HRA = e.basicSalary * 0.20;
        float netSalary = e.basicSalary + DA + HRA;

        char fileName[30];
        sprintf(fileName, "emp%d_slip.txt", e.empId);

        FILE *check = fopen(fileName, "r");
        if (check != NULL) {
            fclose(check);
            printf("Warning: Slip already exists for Employee ID %d\n", e.empId);
            return 0;
        }

        FILE *slip = fopen(fileName, "w");
        if (slip == NULL) {
            printf("Could not create salary slip for ID %d\n", e.empId);
            continue;
        }

        fprintf(slip, "Salary Slip\n");
        fprintf(slip, "-----------------------------\n");
        fprintf(slip, "Employee ID   : %d\n", e.empId);
        fprintf(slip, "Employee Name : %s\n", e.name);
        fprintf(slip, "Basic Salary  : %.2f\n", e.basicSalary);
        fprintf(slip, "DA (20%%)      : %.2f\n", DA);
        fprintf(slip, "HRA (10%%)     : %.2f\n", HRA);
        fprintf(slip, "Net Salary    : %.2f\n", netSalary);
        fprintf(slip, "-----------------------------\n");

        fclose(slip);

        printf("Salary slip generated: %s\n", fileName);
    }

    fclose(fp);
}