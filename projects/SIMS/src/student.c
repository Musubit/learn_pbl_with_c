#include "student.h"

Student* head = NULL;

Student* createStudent(int id, const char* name, int age, float score) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    return newStudent;
}

void addStudent(Student* student) {
    if (head == NULL) {
        head = student;
    } else {
        Student* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = student;
    }
    student->next = NULL;
}