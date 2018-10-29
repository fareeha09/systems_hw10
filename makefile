all: main.o
	gcc -o main.o

main.o: main.c
	gcc -c main.c

run:
	./a.out

clean:
	rm *.o*
	rm *.txt