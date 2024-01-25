#include <stdio.h>
#include "SDB.h"

void SDB_action(uint8 choice);

void SDB_APP() {
    uint8 choice;

    do {
        printf("\nOptions:\n");
        printf("1. To add entry, enter 1\n");
        printf("2. To get used size in database, enter 2\n");
        printf("3. To read student data, enter 3\n");
        printf("4. To get the list of all student IDs, enter 4\n");
        printf("5. To check if ID exists, enter 5\n");
        printf("6. To delete student data, enter 6\n");
        printf("7. To check if database is full, enter 7\n");
        printf("8. To exit, enter 0\n");
        printf("Enter choice: ");
        scanf("%hhu", &choice);

        SDB_action(choice);
    } while (choice != 0);
}

void SDB_action(uint8 choice) {
    switch (choice) {
        case 1:
            if (SDB_AddEntry())
                printf("Entry added successfully.\n");
            else
                printf("Failed to add entry.\n");
            break;
        case 2:
            printf("Used size in database: %u\n", SDB_GetUsedSize());
            break;
        case 3: {
            uint32 id;
            printf("Enter student ID to read data: ");
            scanf("%u", &id);
            if (SDB_ReadEntry(id))
                printf("Data read successfully.\n");
            break;
        }
        case 4: {
            uint8 count;
            uint32 list[MAX_STUDENTS];
            SDB_GetList(&count, list);
            printf("List of all student IDs:\n");
            for (int i = 0; i < count; i++) {
                printf("%u ", list[i]);
            }
            printf("\n");
            break;
        }
        case 5: {
            uint32 id;
            printf("Enter student ID to check existence: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id))
                printf("Student with ID %u exists in the database.\n", id);
            else
                printf("Student with ID %u does not exist in the database.\n", id);
            break;
        }
        case 6: {
            uint32 id;
            printf("Enter student ID to delete: ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break;
        }
        case 7:
            if (SDB_IsFull())
                printf("Database is full.\n");
            else
                printf("Database is not full.\n");
            break;
        case 8:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
    }
}
