all:rn

rn:main.o rn.o
	gcc main.o rn.o -o rn


rn.o:rn.c
	gcc -c rn.c -o rn.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f rn *.o *.
