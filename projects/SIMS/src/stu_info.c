#include "stu_info.h"

Student* head = NULL;

Student* createStudent(int id, const char* name, int age, float score) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (newStudent == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    newStudent->id = id;
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[sizeof(newStudent->name) - 1] = '\0';
    newStudent->age = age;
    newStudent->score = score;
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

void deleteStudent(int id) {
    Student* current = head;
    Student* previous = NULL;

    while (current != NULL) {
        if (current->id == id) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next; 
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void updateStudent(int id, const char* name, int age, float score) {
    Student* student = findStudent(id);
    if (student != NULL) {
        strncpy(student->name, name, sizeof(student->name) - 1);
        student->name[sizeof(student->name) - 1] = '\0';
        student->age = age;
        student->score = score;
    }
}

Student* findStudent(int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

void displayAllStudents() {
    if (head == NULL) {
        printf("没有学生信息。\n");
        return;
    }
    
    Student* current = head;
    printf("========================================\n");
    printf("所有学生信息：\n");
    printf("========================================\n");
    printf("%-6s %-12s %-6s %8s\n", "ID", "姓名", "年龄", "成绩");
    printf("----------------------------------------\n");
    
    while (current != NULL) {
        printf("%-6d %-12s %-6d %-8.2f\n",
             current->id, current->name, current->age, current->score);
        current = current->next;
    }
    printf("========================================\n");
}

void freeList() {
    Student* current = head;
    Student* next;
    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}