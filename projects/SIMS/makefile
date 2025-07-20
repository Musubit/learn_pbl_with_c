objects = main.o stu_info.o stu_menu.o stu_file.o stu_database.o

# 在 MSYS2 中使用 MinGW64 的 SQLite3
SQLITE_INCLUDE = -I/mingw64/include
SQLITE_LIB = -L/mingw64/lib -lsqlite3

all: $(objects)
	gcc -o sims $(objects) $(SQLITE_LIB)

main.o: src/main.c include/stu_info.h include/stu_file.h include/stu_database.h
	gcc -c src/main.c -I include $(SQLITE_INCLUDE)

stu_info.o: src/stu_info.c include/stu_info.h
	gcc -c src/stu_info.c -I include

stu_menu.o: src/stu_menu.c include/stu_menu.h include/stu_info.h include/stu_file.h include/stu_database.h
	gcc -c src/stu_menu.c -I include $(SQLITE_INCLUDE)

stu_file.o: src/stu_file.c include/stu_file.h include/stu_info.h
	gcc -c src/stu_file.c -I include

stu_database.o: src/stu_database.c include/stu_database.h include/stu_info.h
	gcc -c src/stu_database.c -I include $(SQLITE_INCLUDE)

run: all
	./sims

clean:
	rm -f *.o sims

.PHONY: all clean run