#include <stdio.h>
#include <stdlib.h>

// Function to dynamically copy a string safely
char* StringCopy(const char *source) {
    if (source == NULL) {
        return NULL; // Handle null input gracefully
    }

    // Calculate length of source string
    int length = 0;
    const char *temp = source;
    while (*temp != '\0') {
        length++;
        temp++;
    }

    // Allocate memory for destination string (length + 1 for '\0')
    char *dest = (char*)malloc((length + 1) * sizeof(char));
    if (dest == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL; // Allocation failed, return NULL
    }

    // Copy characters from source to destination
    for (int i = 0; i < length; i++) {
        dest[i] = source[i];
    }

    // Add null terminator
    dest[length] = '\0';

    return dest; // Return pointer to newly allocated string
}

int main() {
    // Test strings of various lengths
    const char *str1 = "Hello, World!";
    const char *str2 = "Dynamic string copy in C.";
    const char *str3 = ""; // Empty string

    // Copy strings dynamically
    char *copy1 = StringCopy(str1);
    char *copy2 = StringCopy(str2);
    char *copy3 = StringCopy(str3);

    // Check if allocation succeeded before printing
    if (copy1) {
        printf("Original: %s\nCopied  : %s\n\n", str1, copy1);
        free(copy1); // Free memory after use
    }

    if (copy2) {
        printf("Original: %s\nCopied  : %s\n\n", str2, copy2);
        free(copy2); // Free memory
    }

    if (copy3) {
        printf("Original: %s\nCopied  : %s\n\n", str3, copy3);
        free(copy3); // Free memory
    }

    return 0;
}
