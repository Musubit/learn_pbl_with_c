#ifndef STU_DATABASE_H
#define STU_DATABASE_H

#include "stu_info.h"
#include <sqlite3.h>

// 数据库文件路径
extern const char* DATABASE_PATH;

// 数据库操作函数
int initDatabase();
int saveStudentToDB(Student* student);
int deleteStudentFromDB(int id);
int updateStudentInDB(int id, const char* name, int age, float score);
Student* findStudentInDB(int id);
int loadAllStudentsFromDB();
void closeDatabase();

// 辅助函数
int executeSQL(const char* sql);
void printSQLError(int rc, const char* operation);

#endif // STU_DATABASE_H