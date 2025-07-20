#include "stu_info.h"
#include "stu_menu.h"
#include "stu_file.h"
#include "stu_database.h"

int main() {
    int choice;
    
    // 初始化数据库
    if (initDatabase() != 0) {
        fprintf(stderr, "数据库初始化失败，程序退出。\n");
        return -1;
    }
    
    // 从数据库加载数据
    loadAllStudentsFromDB();

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
            case LOAD_FROM_DB:
                handleLoadFromDB();
                break;
            case SAVE_TO_DB:
                handleSaveToDB();
                break;
            case EXIT:
                freeList();
                closeDatabase();  // 关闭数据库连接
                printf("感谢使用学生信息管理系统！\n");
                exit(0);
            default:
                printf("无效的选择，请重试。\n");
        }
    }
    return 0;
}