all:prim

prim:main.o prim.o
	gcc prim.o main.o -o prim

prim.o:prim.c
	gcc -c prim.c -o prim.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f prim*.o
	rm -f main*.o
	rm -f prim
