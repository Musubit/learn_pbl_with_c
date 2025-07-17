#include "stu_info.h"
#include "stu_menu.h"
#include "stu_file.h"

int main() {
    int choice;
    int id, age;
    char name[50];
    float score;
    loadStudentsFromFile(DEFAULT_FILENAME);

    while(1) {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case ADD_STUDENT:
                handleAddStudent();
                break;
            case DELETE_STUDENT:
                handleDeleteStudent();
                break;
            case UPDATE_STUDENT:
                handleUpdateStudent();
                break;
            case FIND_STUDENT:
                handleFindStudent();
                break;
            case DISPLAY_ALL_STUDENTS:
                handleDisplayAllStudents();
                break;
            case SAVE_FILE:
                handleSaveFile();
                break;
            case EXIT:
                freeList();
                printf("感谢使用学生信息管理系统！\n");
                exit(0);
            default:
                printf("无效的选择，请重试。\n");
        }
    }
    return 0;
}