#ifndef __HASH_H__
#define __HASH_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanhoMax 500

typedef struct No{
    struct No* proximo;
    int chave;
}No;

typedef struct Vetor{
    struct No* inicio;
}Vetor;

typedef struct Hash{
    struct Vetor* vetor[tamanhoMax];
    int tamanho;
}Hash;

No* criarNo(int valor);

Vetor* criarVetor();

Hash* criarHash(int tamanho);

void mudarTamanhoHash(Hash* h, int valor);

int posicaoNaHash(Hash* h, No* x);

No* busca(No* x);

void inserirNoVetor(Vetor* v, No* x);

void inserirNaHash(Hash* h, int valor);

void imprimirHash(Hash* h);

void receberArquivo(char vetor[], Hash* h);

void escreverArquivo(FILE* arquivo, Hash* h);

#endif // __HASH_C__
