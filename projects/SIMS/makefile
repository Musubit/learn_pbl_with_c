objects = main.o  stu_info.o  stu_menu.o stu_file.o

all: $(objects)
	gcc -o sims $(objects)

main.o: src/main.c include/stu_info.h include/stu_file.h
	gcc -c src/main.c -I include

stu_info.o: src/stu_info.c include/stu_info.h
	gcc -c src/stu_info.c -I include

stu_menu.o: src/stu_menu.c include/stu_menu.h include/stu_info.h include/stu_file.h
	gcc -c src/stu_menu.c -I include

stu_file.o: src/stu_file.c include/stu_file.h include/stu_info.h
	gcc -c src/stu_file.c -I include

run: all
	clear && ./sims

build: all
	clear && gcc -o sims $(objects) -I include && ./sims

clean:
	clear && rm -f *.o sims

.PHONY: all clean build run