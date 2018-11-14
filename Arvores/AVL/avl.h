#ifndef __AVL_H__
#define __AVL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    struct No* pai;
    struct No* filhoEsq;
    struct No* filhoDir;
    int chave;
}No;

typedef struct Arvore{
    No* raiz;
}Arvore;

No* criarNo(int valor);

Arvore* criarArvore();

int buscarMaior (int x, int y);

int saberAltura (No* x);

No* noDesbalanceado(No* x);

void balancear (Arvore* t, No* x);

void inserir(Arvore* t, No* z);

void percursoOrdemCrescente(No* raiz);

void percursoPreOrdem(No* raiz);

void percursoPosOrdem(No* raiz);

No* buscaArvore(No* x, int k);

No* buscaMaximo(No* inicio);

No* buscaMinimo(No* inicio);

No* sucessor(No* x);

No* antecessor(No* x);

void rotacaoDireita(Arvore* t, No* p);

void rotacaoEsquerda(Arvore* t, No* p);

void rotacaoDuplaDireita(Arvore* t, No* p);

void rotacaoDuplaEsquerda(Arvore* t, No* p);

No* printArvore(Arvore* t, No* x);

void receberArquivo(char vetor[], Arvore* t);

void escreverArquivo(FILE* arquivo, Arvore* t, No* x);

#endif // __AVL_C__
