all:avl

avl:main.o avl.o
	gcc main.o avl.o -o avl


avl.o:avl.c
	gcc -c avl.c -o avl.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f avl *.o *.
