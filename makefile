all: queue

queue: main.o queue.o
	gcc -pthread -o $@ main.o queue.o

main.o: main.c queue.h
	gcc -pthread -c main.c

queue.o: queue.c queue.h
	gcc -pthread -c queue.c
clean: 
	rm -f queue main.o queue.o
