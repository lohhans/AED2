all:floyd

floyd:main.o floyd.o
	gcc floyd.o main.o -o floyd

floyd.o:floyd.c
	gcc -c floyd.c -o floyd.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f floyd*.o
	rm -f main*.o
	rm -f floyd
