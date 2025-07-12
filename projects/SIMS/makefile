objects = main.o  student.o  menu.o

all: $(objects)
	gcc -o sims $(objects)

main.o: src/main.c include/student.h
	gcc -c src/main.c -I include

student.o: src/student.c include/student.h
	gcc -c src/student.c -I include

menu.o: src/menu.c include/menu.h
	gcc -c src/menu.c -I include

run: all
	clear && ./sims

build: all
	clear && gcc -o sims $(objects) -I include && ./sims

clean:
	clear && rm -f *.o sims

.PHONY: all clean build run