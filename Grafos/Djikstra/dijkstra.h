#ifndef __DJIKSTRA_H__
#define __DJIKSTRA_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maximoVertice 100
#define maximoAresta 100

typedef struct Aresta{
    int peso;
    int verticeOrigem;
    int verticeDestino;
    struct Aresta* prox;
}Aresta;

typedef struct ArestaAux{
    int vertice;
    int custoTotal;
    int prev;
}ArestaAux;

typedef struct Grafo{
    int ponderado;
    int digrafo;
    int v[maximoVertice][maximoVertice];
    struct Aresta* arestas;
}Grafo;

Grafo* inicializarGrafo(int ponderado, int digrafo); //ok

Aresta* inserirAresta(Aresta* aresta, int verticeOrigem, int verticeDestino, int peso); //ok

void inserirGrafo(Grafo* grafo, int verticeOrigem, int verticeDestino, int peso); //ok

void ordenacao(Aresta* aresta); //ok

void dijkstra(Grafo* grafo, Grafo* grafo2, int v0); //ok

void receberArquivo(char arquivo[], Grafo* grafo); //ok

void escreverArquivo(FILE* arquivo, Grafo* grafo, int v0); //ok

void imprimirGrafo(Grafo* grafo, int verticeInicial); //ok

void imprimirDestino(Grafo* grafo, int inicial, int final); //ok

#endif //__DJIKSTRA_H__
