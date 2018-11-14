#include "heap.h"

Heap* criarHeap(int tamanho){ //Cria o No para inserir na na Heap
    Heap* heap = (Heap*) malloc(sizeof(Heap));
	heap->tamanho = tamanho;
	heap->contador = 0;

    return heap;
}

int saberPai(int posicao){ //Retorna a posicao do pai
    return (posicao/2);
}

int saberFilhoEsq(int posicao){ //Retorna a posicao do filho esquerdo
    return (2*posicao)+1;
}

int saberFilhoDir(int posicao){ //Retorna a posicao do filho direito
    return (2*posicao)+2;
}

void maxHeapify(Heap* h, int pai){ //Ordena o Heap Max
    int fEsq = saberFilhoEsq(pai);
    int fDir = saberFilhoDir(pai);
    int maior = pai;
    int auxiliar;

    if((fEsq <= h->contador-1) && (h->vetor[fEsq] > h->vetor[pai])){
        maior = fEsq;
    }

    if((fDir <= h->contador-1) && (h->vetor[fDir] > h->vetor[maior])){
        maior = fDir;
    }

    if(maior != pai){
        auxiliar = h->vetor[pai];
        h->vetor[pai] = h->vetor[maior];
        h->vetor[maior] = auxiliar;
        maxHeapify(h, maior);
    }
}

void minHeapify(Heap* h, int pai){ //Ordena o Heap Min
        int fEsq = saberFilhoEsq(pai);
        int fDir = saberFilhoDir(pai);
        int menor = pai;
        int auxiliar;

        if((fEsq <= h->contador-1) && (h->vetor[menor] > h->vetor[fEsq])){
            menor = fEsq;
        }

        if((fDir <= h->contador-1) && (h->vetor[menor] > h->vetor[fDir])){
            menor = fDir;
        }

        if(menor != pai){
            auxiliar = h->vetor[pai];
            h->vetor[pai] = h->vetor[menor];
            h->vetor[menor] = auxiliar;
            minHeapify(h, menor);
        }
}

void criarMinHeap(Heap* h){ //Cria o Heap Min
    for(int i = h->contador/2; i >= 0; i--){
        minHeapify(h, i);
    }
}

void criarMaxHeap(Heap* h){ //Cria o Heap Max
    for(int i = h->contador/2 ; i >= 0; i--){
        maxHeapify(h, i);
    }
}

void heapSortMin(Heap* h){ //Ordena o Heap decrescente
    int tamanho = h->contador;
    criarMaxHeap(h);
    int auxiliar;

    for(int i = tamanho; i > 1; i--){
        auxiliar = h->vetor[0];
        h->vetor[0] = h->vetor[i - 1];
        h->vetor[i - 1] = auxiliar;
        (h->contador)--;
        maxHeapify(h, 0);
    }

    h->contador = tamanho;
}

void heapSortMax(Heap* h){ //Ordena o Heap crescente
    int tamanho = h->contador;
    criarMinHeap(h);
    int auxiliar;

    for(int i = tamanho-1; i >= 1; i--){
        auxiliar = h->vetor[0];
        h->vetor[0] = h->vetor[i];
        h->vetor[i] = auxiliar;
        h->contador--;
        criarMinHeap(h);
    }

    h->contador = tamanho;
}

void inserirNaHeap(int dado, Heap* h){  //Insere na Heap
    if(h->contador < h->tamanho){
        h->vetor[h->contador] = dado;
        h->contador++;
    }
}

void imprimirHeap(Heap* h){ //Imprime a Heap no terminal
    for(int i = 0; i < h->contador; i++){
        printf("%d ", h->vetor[i]);
    }
    printf("\n");
}

void receberArquivo(char vetor[], Heap* h){ //Leitura da entrada da Heap
    int numero;
    FILE* arquivo = fopen(vetor, "r");

	if(arquivo != NULL){
		while(fscanf(arquivo, "%d", &numero) != EOF){//Fim Do Arquivo = End Of File
			inserirNaHeap(numero, h);
		}
	}

	fclose(arquivo);
}

void escreverArquivo(FILE* arquivo, Heap* h){ //Escrita da saida da Heap
    for(int i = 0; i < h->contador; i++){
        fprintf(arquivo, "%d ", h->vetor[i]);
    }
    fprintf(arquivo, "\n");
}
