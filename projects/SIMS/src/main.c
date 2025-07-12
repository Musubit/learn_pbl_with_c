#include "student.h"
#include "menu.h"

int main() {
    int choice;
    int id, age;
    char name[50];
    float score;

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
            case EXIT:
                freeList();
                exit(0);
            default:
                printf("无效的选择，请重试。\n");
        }
    }
    return 0;
}