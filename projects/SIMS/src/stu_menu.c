#include "stu_menu.h"

void displayMenu() {
    printf("========================================\n");
    printf("       学生信息管理系统\n");
    printf("========================================\n");
    printf("1. 添加学生\n");
    printf("2. 删除学生\n");
    printf("3. 更新学生信息\n");
    printf("4. 查找学生\n");
    printf("5. 显示所有学生\n");
    printf("6. 退出系统\n");
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
}

void handleDeleteStudent() {
    int id;
    printf("输入要删除的学生ID: ");
    scanf("%d", &id);
    deleteStudent(id);
}

void handleUpdateStudent() {
    int id, age;
    char name[50];
    float score;

    printf("输入要更新的学生ID: ");
    scanf("%d", &id);
    printf("输入新的姓名: ");
    scanf("%s", name);
    printf("输入新的年龄: ");
    scanf("%d", &age);
    printf("输入新的成绩: ");
    scanf("%f", &score);
    updateStudent(id, name, age, score);
}

void handleFindStudent() {
    int id;
    printf("输入要查找的学生ID: ");
    scanf("%d", &id);
    Student* student = findStudent(id);
    if (student != NULL) {
        printf("找到学生 - ID: %d, 姓名: %s, 年龄: %d, 成绩: %.2f\n",
               student->id, student->name, student->age, student->score);
    } else {
        printf("未找到该学生。\n");
    }
}

void handleDisplayAllStudents() {
    displayAllStudents();
}
