#include "stu_file.h"

const char* DEFAULT_FILENAME = "data/stu_info.dat";

void saveStudentsToFile(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", filename);
        return;
    }

    Student* current = head;
    while (current != NULL) {
        fwrite(current, sizeof(Student), 1, file);
        current = current->next;
    }

    fclose(file);
}

void loadStudentsFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "无法打开文件 %s\n", filename);
        return;
    }

    Student* student = (Student*)malloc(sizeof(Student));
    while (fread(student, sizeof(Student), 1, file) == 1) {
        addStudent(student);
        student = (Student*)malloc(sizeof(Student));
    }
    free(student);
    fclose(file);
}