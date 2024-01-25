#include "SDB.h"
#include <stdio.h>


static student database[MAX_STUDENTS];
static uint8 usedSize = 0;

bool SDB_IsFull() {
    return (usedSize >= MAX_STUDENTS);
}

uint8 SDB_GetUsedSize() {
    return usedSize;
}

bool SDB_AddEntry() {
    if (SDB_IsFull()) {
        printf("Database is full. Cannot add more entries.\n");
        return false;
    }

    printf("Enter student details:\n");
    printf("Student ID: ");
    scanf("%u", &database[usedSize].Student_ID);
    printf("Student year: ");
    scanf("%u", &database[usedSize].Student_year);
    printf("Course 1 ID: ");
    scanf("%u", &database[usedSize].Course1_ID);
    printf("Course 1 grade: ");
    scanf("%u", &database[usedSize].Course1_grade);
    printf("Course 2 ID: ");
    scanf("%u", &database[usedSize].Course2_ID);
    printf("Course 2 grade: ");
    scanf("%u", &database[usedSize].Course2_grade);
    printf("Course 3 ID: ");
    scanf("%u", &database[usedSize].Course3_ID);
    printf("Course 3 grade: ");
    scanf("%u", &database[usedSize].Course3_grade);

    usedSize++;
    return true;
}

void SDB_DeleteEntry(uint32 id) {
    int i;
    for (i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            // Replace the entry to be deleted with the last entry
            database[i] = database[usedSize - 1];
            usedSize--;
            printf("Student with ID %u deleted successfully.\n", id);
            return;
        }
    }
    printf("Student with ID %u not found in the database.\n", id);
}

bool SDB_ReadEntry(uint32 id) {
    int i;
    for (i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            printf("Student ID: %u\n", database[i].Student_ID);
            printf("Student year: %u\n", database[i].Student_year);
            printf("Course 1 ID: %u, Grade: %u\n", database[i].Course1_ID, database[i].Course1_grade);
            printf("Course 2 ID: %u, Grade: %u\n", database[i].Course2_ID, database[i].Course2_grade);
            printf("Course 3 ID: %u, Grade: %u\n", database[i].Course3_ID, database[i].Course3_grade);
            return true;
        }
    }
    printf("Student with ID %u not found in the database.\n", id);
    return false;
}

void SDB_GetList(uint8 *count, uint32 *list) {
    int i;
    *count = usedSize;
    for (i = 0; i < usedSize; i++) {
        list[i] = database[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id) {
    int i;
    for (i = 0; i < usedSize; i++) {
        if (database[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}
