#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdlib.h>
#include <stdio.h>

#include "floyd.h"

#define HEAP 99999

typedef struct Heap{
	int tamanho;
	ArestaAux* vetor[HEAP];
}Heap;

int pai(int i); //ok

int dir(int i); //ok

int esq(int i); //ok

void criaHeap(Heap* h); //ok

void inserirHeap(Heap* h, ArestaAux* no); //ok

void trocar(Heap* h, int a, int b); //ok

void heapify(Heap* h, int i); //ok

ArestaAux* heapMin(Heap* h); //ok

ArestaAux* extrairMin(Heap* h); //ok

void heapIncreaseKey(Heap* h, int i, int chave); //ok

int heapVazia(Heap* heap); //ok

#endif //__HEAP_H__
