#include<stdio.h>
#include<stdlib.h>


struct Student{
    int rollNo;
    char name[50];
    float marks;
};

void addStudentRecord(){
    FILE *fp;
    struct Student s;

    fp = fopen("students.dat", "ab");
    if(fp == NULL){
       printf("Error: Unable to open file for writing!\n");
       return; 
    }

    printf("\nEnter roll number: ");
    scanf("%d", &s.rollNo);
    if (s.rollNo <= 0) {
        printf("Invalid roll number!\n");
        fclose(fp);
        return;
    }

    printf("Enter Name: ");
    scanf("%[^\n]",s.name);

    printf("Enter marks[0-100]: ");
    scanf("%f",&s.marks);

    if(s.marks<0 || s.marks>100){
        printf("Invalid marks!");
        fclose(fp);
        return;
    }

    fwrite(&s, sizeof(struct Student), 1, fp);
    printf("Student record added successfully!\n");
    fclose(fp);
}


void displayAllRecords() {
    FILE *fp;
    struct Student s;
    int found = 0;

    fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("Error: No records found or file cannot be opened!\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    while (fread(&s, sizeof(struct Student), 1, fp)) {
        printf("Roll No: %d | Name: %s | Marks: %.2f\n",
               s.rollNo, s.name, s.marks);
        found = 1;
    }

    if (!found) {
        printf("File is empty. No records to display.\n");
    }

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudentRecord();
                break;

            case 2:
                displayAllRecords();
                break;

            case 3:
                printf("Exiting program... Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}