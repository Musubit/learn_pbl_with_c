CC = gcc                # 指定C编译器为GCC
CFLAGS = -Iinclude -Wall -g  # 编译选项：
                             # -Iinclude 到include目录查找头文件
                             # -Wall 开启所有常见警告
                             # -g 包含调试信息

SRC = src/main.c src/student.c  # 源文件列表
OBJ = $(SRC:.c=.o)  # 自动生成目标文件列表（.c替换为.o）
TARGET = sims       # 最终生成的可执行文件名

all: $(TARGET)      # 默认目标：生成可执行文件

$(TARGET): $(OBJ)   # 链接规则：将所有.o文件链接成可执行文件
    $(CC) $(OBJ) -o $@  # $@ 代表当前目标（即$(TARGET)）

src/%.o: src/%.c include/student.h  # 编译规则：
                                    # 每个.c文件如何生成对应的.o文件
                                    # 依赖于同名.c文件和公共头文件
    $(CC) $(CFLAGS) -c $< -o $@  # $< 代表第一个依赖文件（.c文件）

clean:              # 清理规则：删除生成的文件
    del /Q src\*.o $(TARGET).exe 2>nul  # Windows系统命令
                                    # 2>nul 用于忽略文件不存在的错误

.PHONY: all clean   # 声明伪目标：即使存在同名文件也会执行命令