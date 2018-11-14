#ifndef __PRIM_H_
#define __PRIM_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Aresta{
	int verticeOrigem;
	int verticeDestino;
  	int peso;
}Aresta;

typedef struct No{
	Aresta* aresta;
	struct No *prox;
}No;

typedef struct Grafo{
	int numeroArestas;
	int numeroVertices;
	int contador;
	No* vetorArestas[MAX];

}Grafo;

typedef struct vetorA{
    int contador2;
    Aresta* vetor[MAX];
}vetorA;

typedef struct vetorV{
    int contador2;
    int vetor[MAX];
}vetorV;

No* alocarAresta(int verticeOrigem, int verticeDestino, int peso); //ok

void inicializarVetorArestas(vetorA *vetorA, int valor); //ok

void inicializarAresta (vetorA *vetorA, Aresta *aresta); //ok

void inicializarVetorVertices(vetorV *vetor); //ok

void inicializarVertice(vetorV *vetorV, int numero); //ok

void inicializaGrafo(Grafo *grafo, int numeroArestas, int numeroVertices); //ok

int adicionarAresta(Grafo *grafo, int verticeOrigem, int verticeDestino, int peso); //ok

int adicionarVertice(vetorV *vetorVerticeI, vetorV *vetorVerticeF, int verticeOrigem, int verticeDestino); //ok

void criarArestas(Grafo *grafo, vetorA *vetorA); //ok

void criarVertices(Grafo *grafo, vetorV *vetorV); //ok

void deletarAresta(vetorA *vetorA, int verticeOrigem, int verticeDestino); //ok

void deletarVertice(vetorV *vetorV, int indice); //ok

void ordenar(vetorA *vetorA); //ok

void ordenarArquivo(vetorA *vetorA); //ok

int calcularPeso(vetorA *vetorA); //ok

int verificarPrim(vetorV *vetorV, int verticeOrigem, int verticeDestino); //ok

int verificarPrim2(vetorV *vetorV, int verticeOrigem, int verticeDestino); //ok

void prim(Grafo *grafoI, Grafo *grafoF, vetorA *vetorArestaF); //ok

void imprimirArestas(vetorA *vetorA); //ok

void receberArquivo(char arquivo[], Grafo* grafo); //ok

void escreverArquivo(FILE* arquivo, vetorA *vetorA); //ok

#endif //__PRIM_H_
