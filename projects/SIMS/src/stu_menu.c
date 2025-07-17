#include "stu_menu.h"
#include "stu_file.h"

void displayMenu() {
    printf("========================================\n");
    printf("       学生信息管理系统\n");
    printf("========================================\n");
    printf("1. 添加学生\n");
    printf("2. 删除学生\n");
    printf("3. 更新学生信息\n");
    printf("4. 查找学生\n");
    printf("5. 显示所有学生\n");
    printf("6. 保存学生信息到文件\n");
    printf("7. 退出系统\n");
    printf("========================================\n");
    printf("请选择操作 (1-6): ");
}

void handleAddStudent() {
    int id, age;
    char name[50];
    float score;

    printf("输入学生ID: ");
    scanf("%d", &id);
    printf("输入学生姓名: ");
    scanf("%s", name);
    printf("输入学生年龄: ");
    scanf("%d", &age);
    printf("输入学生成绩: ");
    scanf("%f", &score);
    addStudent(createStudent(id, name, age, score));
    sysWait();
}

void handleDeleteStudent() {
    int id;
    printf("输入要删除的学生ID: ");
    scanf("%d", &id);
    deleteStudent(id);
    sysWait();
}

void handleUpdateStudent() {
    int id, age;
    char name[50];
    float score;

    
    printf("输入要更新的学生ID: ");
    scanf("%d", &id);
    printf("原学生信息：\n");
    printf("========================================\n");
    printf("ID        姓名       年龄      成绩\n");
    Student* student = findStudent(id);
    if (student != NULL) {
        printf("%-8d %-12s %-8d %-8.2f\n",
               student->id, student->name, student->age, student->score);
    } else {
        printf("未找到该学生。\n");
    }
    printf("========================================\n");
    printf("输入新的姓名: ");
    scanf("%s", name);
    printf("输入新的年龄: ");
    scanf("%d", &age);
    printf("输入新的成绩: ");
    scanf("%f", &score);
    updateStudent(id, name, age, score);
    sysWait();
}

void handleFindStudent() {
    int id;
    printf("输入要查找的学生ID: ");
    scanf("%d", &id);
    Student* student = findStudent(id);
    if (student != NULL) {
        printf("=========================\n");
        printf("学生ID: %d\n", student->id);
        printf("学生姓名: %s\n", student->name);
        printf("学生年龄: %d\n", student->age);
        printf("学生成绩: %.2f\n", student->score);
        printf("=========================\n");
    } else {
        printf("未找到该学生。\n");
    }
    sysWait();
}

void handleDisplayAllStudents() {
    displayAllStudents();
    sysWait();
}

void handleSaveFile() {
    saveStudentsToFile(DEFAULT_FILENAME);
    printf("学生信息已保存到文件 %s\n", DEFAULT_FILENAME);
    sysWait();
}