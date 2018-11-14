#ifndef __RN_H__
#define __RN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    struct No* pai;
    struct No* filhoEsq;
    struct No* filhoDir;
    int chave;
    int cor;//se o no for vermelho recebe 1 se o no for preto recebe 0
}No;

typedef struct Arvore{
    No* raiz;
}Arvore;

No* criarNo(int valor);

Arvore* criarArvore();

No* buscarTio(No* x);

int buscarMaior (int x, int y);

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

#endif // __RN_C__
