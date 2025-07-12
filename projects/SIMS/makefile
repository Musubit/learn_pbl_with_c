objects = student.o main.o

all: $(objects)
	gcc -o sims $(objects)

main.o: src/main.c include/student.h
	gcc -c src/main.c -I include

student.o: src/student.c include/student.h
	gcc -c src/student.c -I include

run: all
	clear && ./sims

clean:
	clear && rm -f *.o sims

.PHONY: all clean