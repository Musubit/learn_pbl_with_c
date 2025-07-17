#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[100];
    int age;
    float score;
    struct Student* next;
} Student;

extern Student* head;

Student* createStudent(int id, const char* name, int age, float score);
void addStudent(Student* student);
void deleteStudent(int id);
void updateStudent(int id, const char* name, int age, float score);
Student* findStudent(int id);
void displayAllStudents();
void freeList();

void sysWait();

#endif // STUDENT_H