CC=gcc
main: main.o arith.o
	$(CC) -o main main.o arith.o
main.o: main.c
	$(CC) -c -o main.o main.c
arith.o: arith.c
	$(CC) -c -o arith.o arith.c
clean:
	rm -rf main.o arith.o main libarith.a
archive: arith.o
	ar crv libarith.a arith.o