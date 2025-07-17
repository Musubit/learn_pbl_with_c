#ifndef STU_FILE_H
#define STU_FILE_H

#include "stu_info.h"
extern const char* DEFAULT_FILENAME;

void saveStudentsToFile(const char* filename);
void loadStudentsFromFile(const char* filename);

#endif // STU_FILE_H