#include "stu_database.h"

const char* DATABASE_PATH = "data/students.db";
static sqlite3* db = NULL;

int initDatabase() {
    int rc = sqlite3_open(DATABASE_PATH, &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    // 创建学生表
    const char* createTableSQL = 
        "CREATE TABLE IF NOT EXISTS students ("
        "id INTEGER PRIMARY KEY,"
        "name TEXT NOT NULL,"
        "age INTEGER NOT NULL,"
        "score REAL NOT NULL"
        ");";

    rc = sqlite3_exec(db, createTableSQL, 0, 0, 0);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "创建表失败: %s\n", sqlite3_errmsg(db));
        return -1;
    }

    printf("数据库初始化成功。\n");
    return 0;
}

int saveStudentToDB(Student* student) {
    if (db == NULL) {
        fprintf(stderr, "数据库未初始化。\n");
        return -1;
    }

    const char* sql = "INSERT OR REPLACE INTO students (id, name, age, score) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printSQLError(rc, "准备插入语句");
        return -1;
    }

    // 绑定参数
    sqlite3_bind_int(stmt, 1, student->id);
    sqlite3_bind_text(stmt, 2, student->name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, student->age);
    sqlite3_bind_double(stmt, 4, student->score);

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc != SQLITE_DONE) {
        printSQLError(rc, "插入学生数据");
        return -1;
    }

    return 0;
}

int deleteStudentFromDB(int id) {
    if (db == NULL) {
        fprintf(stderr, "数据库未初始化。\n");
        return -1;
    }

    const char* sql = "DELETE FROM students WHERE id = ?;";
    sqlite3_stmt* stmt;
    
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printSQLError(rc, "准备删除语句");
        return -1;
    }

    sqlite3_bind_int(stmt, 1, id);
    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc != SQLITE_DONE) {
        printSQLError(rc, "删除学生数据");
        return -1;
    }

    return sqlite3_changes(db) > 0 ? 0 : -1;
}

int updateStudentInDB(int id, const char* name, int age, float score) {
    if (db == NULL) {
        fprintf(stderr, "数据库未初始化。\n");
        return -1;
    }

    const char* sql = "UPDATE students SET name = ?, age = ?, score = ? WHERE id = ?;";
    sqlite3_stmt* stmt;
    
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printSQLError(rc, "准备更新语句");
        return -1;
    }

    sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, age);
    sqlite3_bind_double(stmt, 3, score);
    sqlite3_bind_int(stmt, 4, id);

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc != SQLITE_DONE) {
        printSQLError(rc, "更新学生数据");
        return -1;
    }

    return sqlite3_changes(db) > 0 ? 0 : -1;
}

Student* findStudentInDB(int id) {
    if (db == NULL) {
        fprintf(stderr, "数据库未初始化。\n");
        return NULL;
    }

    const char* sql = "SELECT id, name, age, score FROM students WHERE id = ?;";
    sqlite3_stmt* stmt;
    
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printSQLError(rc, "准备查询语句");
        return NULL;
    }

    sqlite3_bind_int(stmt, 1, id);
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) {
        Student* student = (Student*)malloc(sizeof(Student));
        if (student == NULL) {
            fprintf(stderr, "内存分配失败。\n");
            sqlite3_finalize(stmt);
            return NULL;
        }

        student->id = sqlite3_column_int(stmt, 0);
        strncpy(student->name, (const char*)sqlite3_column_text(stmt, 1), 
                sizeof(student->name) - 1);
        student->name[sizeof(student->name) - 1] = '\0';
        student->age = sqlite3_column_int(stmt, 2);
        student->score = sqlite3_column_double(stmt, 3);
        student->next = NULL;

        sqlite3_finalize(stmt);
        return student;
    }

    sqlite3_finalize(stmt);
    return NULL;
}

int loadAllStudentsFromDB() {
    if (db == NULL) {
        fprintf(stderr, "数据库未初始化。\n");
        return -1;
    }

    // 清空当前链表
    freeList();

    const char* sql = "SELECT id, name, age, score FROM students ORDER BY id;";
    sqlite3_stmt* stmt;
    
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        printSQLError(rc, "准备查询所有学生");
        return -1;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*)sqlite3_column_text(stmt, 1);
        int age = sqlite3_column_int(stmt, 2);
        float score = sqlite3_column_double(stmt, 3);

        Student* student = createStudent(id, name, age, score);
        if (student != NULL) {
            addStudent(student);
        }
    }

    sqlite3_finalize(stmt);
    return 0;
}

void closeDatabase() {
    if (db != NULL) {
        sqlite3_close(db);
        db = NULL;
        printf("数据库连接已关闭。\n");
    }
}

void printSQLError(int rc, const char* operation) {
    fprintf(stderr, "%s失败: %s (错误代码: %d)\n", 
            operation, sqlite3_errmsg(db), rc);
}