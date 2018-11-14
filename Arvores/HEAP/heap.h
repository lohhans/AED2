#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanhoMax 500

typedef struct Heap{
    int vetor[tamanhoMax];
    int tamanho;
    int contador;
}Heap;

Heap* criarHeap(int tamanho);

int saberPai(int posicao);

int saberFilhoEsq(int posicao);

int saberFilhoDir(int posicao);

void maxHeapify(Heap* h, int pai);

void minHeapify(Heap* h, int pai);

void criarMinHeap(Heap* h);

void criarMaxHeap(Heap* h);

void heapSortMax(Heap* h);

void heapSortMin(Heap* h);

void inserirNaHeap(int dado, Heap* h);

void imprimirHeap(Heap* h);

void receberArquivo(char vetor[], Heap* h);

void escreverArquivo(FILE* arquivo, Heap* h);

#endif // __HEAP_C__
