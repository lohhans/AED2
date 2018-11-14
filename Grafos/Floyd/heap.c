#include "heap.h"

int pai(int i){
	return ((i+1)/2)-1;
}

int dir(int i){
	return (2*(i+1));
}

int esq(int i){
	return (2*(i+1))-1;
}

void criaHeap(Heap* h){
	for(int i = (HEAP/2); i>=0;i--){
		heapify(h,i);
	}
}

void inserirHeap(Heap* h, ArestaAux* no){
	h->vetor[h->tamanho] = no;
	h->tamanho = h->tamanho + 1;
}

void trocar(Heap* h, int a, int b){
	ArestaAux* aux;
	aux = h->vetor[a];
	h->vetor[a] = h->vetor[b];
	h->vetor[b] = aux;
}

void heapify(Heap* h, int i){
	int l, r, minimo;
	l = esq(i);
	r = dir(i);
	if(l< h->tamanho && h->vetor[l]->custoTotal < h->vetor[i]->custoTotal){
		minimo = l;
			}

	else{
		minimo= i;
	}

	if(r< h->tamanho && h->vetor[r]->custoTotal <h->vetor[minimo]->custoTotal){
		minimo = r;
	}

	if(minimo != i){
		trocar(h, i, minimo);
		heapify(h, minimo);
	}
}

ArestaAux* heapMin(Heap* h){
	return h->vetor[0];
}

ArestaAux* extrairMin(Heap* h){
	ArestaAux* minimo;
	minimo = h->vetor[0];
	h->tamanho = h->tamanho-1;
	h->vetor[0] = h->vetor[h->tamanho];
	heapify(h, 0);
	return minimo;

}
void heapIncreaseKey(Heap* h, int i, int k){
	h->vetor[i]->custoTotal = k;

	while(i>0 && h->vetor[pai(i)]->custoTotal > h->vetor[i]->custoTotal){
		trocar(h, i, pai(i));
		i = pai(i);
	}
}

int heapVazia(Heap* heap){
	if(heap->tamanho == 0){
		return 1;
	}

	return 0;
}
