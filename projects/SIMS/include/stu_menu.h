#ifndef MENU_H
#define MENU_H

#include "stu_info.h"
#include "stu_database.h"

typedef enum {
    ADD_STUDENT = 1,
    DELETE_STUDENT,
    UPDATE_STUDENT,
    FIND_STUDENT,
    DISPLAY_ALL_STUDENTS,
    SAVE_FILE,
    LOAD_FROM_DB,      // 新增
    SAVE_TO_DB,        // 新增
    EXIT
} MenuChoice;

void displayMenu();

void handleAddStudent();
void handleDeleteStudent();
void handleUpdateStudent();
void handleFindStudent();
void handleDisplayAllStudents();
void handleSaveFile();
void handleLoadFromDB();    // 新增
void handleSaveToDB();      // 新增

#endif // MENU_H