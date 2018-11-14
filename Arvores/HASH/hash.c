#include "hash.h"

No* criarNo(int valor){ //Cria o No para inserir na na Hash
    No* no = (No*) malloc(sizeof(No));
    no->proximo = NULL;
    no->chave = valor;

    return no;
}

Vetor* criarVetor(){ //Cria o vetor
    Vetor* vetor = (Vetor*) malloc(sizeof(Vetor));
    vetor->inicio = NULL;

    return vetor;
}

Hash* criarHash(int tamanho){  //Cria a Hash
    Hash* hash = (Hash*) malloc(sizeof(Hash));
    hash->tamanho = tamanho;

    for (int i = 0; i < tamanhoMax; i++){
        Vetor* vetorDoIndice = criarVetor();
        hash->vetor[i] = vetorDoIndice;
    }

    return hash;
}

void mudarTamanhoHash(Hash* h, int valor){ //Muda o tamanho da Hash
    h->tamanho = valor;
}

int posicaoNaHash(Hash* h, No* x){ //Informa a posicao a ser inserida na Hash
    return x->chave % (h->tamanho);
}

No* busca(No* x){ //Reotorna um no
    No* y;
    while (x->proximo != NULL) {
        y = x->proximo;
    }

    return y;
}

void inserirNoVetor(Vetor* v, No* x){ //Insere um no no vetor
    if(v->inicio == NULL){
        v->inicio = x;
        x->proximo = NULL;
    } else {
        x->proximo = v->inicio;
        v->inicio = x;
    }
}

void inserirNaHash(Hash* h, int valor){ //Insere um no na Hash
    No* no = criarNo(valor);
    inserirNoVetor(h->vetor[posicaoNaHash(h, no)], no);
}

void imprimirHash(Hash* h){ //Imprime a Hash no terminal
     int a = 0;

     while (a < h->tamanho) {
        if(h->vetor[a]->inicio == NULL){
            printf("%d: \n", a);
        } else {
            No* noAux;
            printf("%d: ", a);
            for (noAux = h->vetor[a]->inicio; noAux != NULL; noAux = noAux->proximo) {
                printf("%d ", noAux->chave);
            }
            printf("\n");
        }
        a++;
    }
}

void receberArquivo(char vetor[], Hash* h){ //Leitura da entrada da Hash
    int numero;
    FILE* arquivo = fopen(vetor, "r");

	if(arquivo != NULL){
		while(fscanf(arquivo, "%d", &numero) != EOF){//Fim Do Arquivo = End Of File
			No* No = criarNo(numero);
			inserirNaHash(h, No->chave);
		}
	}

	fclose(arquivo);
}

void escreverArquivo(FILE* arquivo, Hash* h){ //Escrita da saida da Hash
    int a = 0;

    while (a < h->tamanho) {
       if(h->vetor[a]->inicio == NULL){
           fprintf(arquivo, "%d: \n", a);
       } else {
           No* noAux;
           fprintf(arquivo, "%d: ", a);
           for (noAux = h->vetor[a]->inicio; noAux != NULL; noAux = noAux->proximo) {
               fprintf(arquivo, "%d ", noAux->chave);
           }
           fprintf(arquivo, "\n");
       }
       a++;
   }
}
