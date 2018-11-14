all:dijkstra

dijkstra:main.o dijkstra.o
	gcc dijkstra.o main.o -o dijkstra

dijkstra.o:dijkstra.c
	gcc -c dijkstra.c -o dijkstra.o

main.o:main.c
	gcc -c main.c -o main.o

clean:
	rm -f dijkstra*.o
	rm -f main*.o
	rm -f dijkstra
