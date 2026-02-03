#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* STRUCT DEFINITION  */

typedef struct {
    char name[50];
    char phone[20];
}Contact ;


/*  FUNCTION DEFINITIONS  */
Contact* addContact(Contact* contacts_array, int* current_size, const Contact* new_contact) {
    /* First contact: use malloc */
    if (contacts_array == NULL) {
        contacts_array = (Contact*)malloc(sizeof(Contact));
        if (contacts_array == NULL) {
            fprintf(stderr, "Error: Initial memory allocation failed.\n");
            return NULL;
        }
    }

    /* Additional contacts: use realloc */
    else {
        Contact* temp = (Contact*)realloc(contacts_array,(*current_size + 1) * sizeof(Contact));

        /* Check realloc result */
        if (temp == NULL) {
            fprintf(stderr, "Error: Memory reallocation failed.\n");
            return contacts_array;  // preserve old data
        }

        contacts_array = temp;
    }

    /* Copy new contact at the end */
    contacts_array[*current_size] = *new_contact;
    (*current_size)++;

    return contacts_array;
}

 //Searches contact by name
 //Returns pointer to Contact if found, else NULL
Contact* findContact(const Contact* contacts_array, int current_size, const char* search_name) {
    if (contacts_array == NULL) {
        return NULL;
    }
    for (int i = 0; i < current_size; i++) {
        if (strcmp(contacts_array[i].name, search_name) == 0) {
            return (Contact*)&contacts_array[i]; // safe cast
        }
    }
    return NULL;
}

// Displays all contacts
void displayAllContacts(const Contact* contacts_array, int current_size) {
    if (contacts_array == NULL || current_size == 0) {
        printf("\nNo contacts available.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < current_size; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name  : %s\n", contacts_array[i].name);
        printf("Phone : %s\n\n", contacts_array[i].phone);
    }
}

// Frees allocated memory and resets values

void cleanupContacts(Contact** contacts_array, int* current_size) {
    if (*contacts_array != NULL) {
        free(*contacts_array);
        *contacts_array = NULL;
    }
    *current_size = 0;
}

/*MAIN FUNCTION */
int main() {
    Contact* contacts = NULL;
    int size = 0;
    int choice;

    do {
        printf("\n===== Contact Management Menu =====\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1: {
                Contact newContact;

                printf("Enter Name: ");
                scanf(" %49[^\n]", newContact.name);

                printf("Enter Phone Number: ");
                scanf(" %19[^\n]", newContact.phone);

                Contact* updated = addContact(contacts, &size, &newContact);
                if (updated != NULL) {
                    contacts = updated;
                    printf("Contact added successfully.\n");
                }
                break;
            }

            case 2:
                displayAllContacts(contacts, size);
                break;

            case 3: {
                char searchName[50];
                printf("Enter name to search: ");
                scanf(" %49[^\n]", searchName);

                Contact* found = findContact(contacts, size, searchName);
                if (found != NULL) {
                    printf("\nContact Found:\n");
                    printf("Name  : %s\n", found->name);
                    printf("Phone : %s\n", found->phone);
                } else {
                    printf("\nContact not found.\n");
                }
                break;
            }

            case 4:
                cleanupContacts(&contacts, &size);
                printf("Exiting program. Memory cleaned up.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
