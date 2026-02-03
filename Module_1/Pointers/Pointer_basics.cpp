#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dynamically allocate memory for an integer
    int *pThemeColorCode = (int *)malloc(sizeof(int));

    // Check if memory allocation was successful
    if (pThemeColorCode == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize with default value
    *pThemeColorCode = 0;

    // Prompt user for input
    printf("Enter your preferred theme color code: ");
    scanf("%d", pThemeColorCode);

    
    // Print final theme color code
    printf("The final theme color code is: %d\n", *pThemeColorCode);

    // Deallocate memory
    free(pThemeColorCode);

    // Prevent dangling pointer
    pThemeColorCode = NULL;

    return 0;
}
