#include <stdio.h>
#include <string.h>

int main() {
    /* Student 1 Variables */
    char name1[30];
    int age1;
    float gpa1;

    /* Student 2 Variables */
    char name2[30];
    int age2;
    float gpa2;

    /* Student 3 Variables */
    char name3[30];
    int age3;
    float gpa3;

    /* Input Student Details */
    printf("Enter details for Student 1\n");
    printf("Name: ");
    fgets(name1, sizeof(name1), stdin);
    name1[strcspn(name1, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &age1);
    printf("GPA: ");
    scanf("%f", &gpa1);
    getchar();  

    printf("\nEnter details for Student 2\n");
    printf("Name: ");
    fgets(name2, sizeof(name2), stdin);
    name2[strcspn(name2, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &age2);
    printf("GPA: ");
    scanf("%f", &gpa2);
    getchar();

    printf("\nEnter details for Student 3\n");
    printf("Name: ");
    fgets(name3, sizeof(name3), stdin);
    name3[strcspn(name3, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &age3);
    printf("GPA: ");
    scanf("%f", &gpa3);

    /* Display Table */
    printf("\n|---------------|-----|-------|\n");
    printf("|%15s|%5s|%7s|\n", "Name", "Age", "GPA");
    printf("|---------------|-----|-------|\n");

    printf("|%15s|%5d|%7.2f|\n", name1, age1, gpa1);
    printf("|%15s|%5d|%7.2f|\n", name2, age2, gpa2);
    printf("|%15s|%5d|%7.2f|\n", name3, age3, gpa3);

    printf("|---------------|-----|-------|\n");

    return 0;
}
