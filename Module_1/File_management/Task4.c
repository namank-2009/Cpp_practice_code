#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    FILE *fp;
    struct Student s;
    int searchRoll;
    float newMarks;
    int found = 0;

    fp = fopen("students.dat", "r+b");
    if (fp == NULL) {
        printf("Error: Unable to open file or file does not exist.\n");
        return 1;
    }

    printf("Enter roll number to update marks: ");
    scanf("%d", &searchRoll);

    if (searchRoll <= 0) {
        printf("Invalid roll number.\n");
        fclose(fp);
        return 1;
    }

    /* Search for the student record */
    while (fread(&s, sizeof(struct Student), 1, fp)) {
        if (s.rollNo == searchRoll) {
            found = 1;

            printf("Student Found!\n");
            printf("Name: %s\n", s.name);
            printf("Current Marks: %.2f\n", s.marks);

            printf("Enter new marks (0 - 100): ");
            scanf("%f", &newMarks);

            if (newMarks < 0 || newMarks > 100) {
                printf("Invalid marks entered.\n");
                fclose(fp);
                return 1;
            }

            s.marks = newMarks;

            /* Move file pointer back to start of this record */
            fseek(fp, -sizeof(struct Student), SEEK_CUR);

            fwrite(&s, sizeof(struct Student), 1, fp);

            printf("Marks updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", searchRoll);
    }

    fclose(fp);
    return 0;
}
