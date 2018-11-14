all:hash

hash:main.o hash.o
	gcc main.o hash.o -o hash

hash.o:hash.c
	gcc -c hash.c -o hash.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f hash *.o *.
