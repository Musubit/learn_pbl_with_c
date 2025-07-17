#ifndef MENU_H
#define MENU_H

#include "stu_info.h"

typedef enum {
    ADD_STUDENT = 1,
    DELETE_STUDENT,
    UPDATE_STUDENT,
    FIND_STUDENT,
    DISPLAY_ALL_STUDENTS,
    EXIT
} MenuChoice;

void displayMenu();

void handleAddStudent();
void handleDeleteStudent();
void handleUpdateStudent();
void handleFindStudent();
void handleDisplayAllStudents();

#endif // MENU_H