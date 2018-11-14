all:avl.bin

arvore.bin:main.o abb.o
	gcc main.o abb.o -o arvore.bin


ArvoreBin.o:abb.c
	gcc -c abb.c -o abb.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f *.bin *.o *.*~ *~
