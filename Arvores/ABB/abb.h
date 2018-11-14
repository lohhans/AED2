#ifndef __ABB_H__
#define __ABB_H__

#include <stdio.h>
#include <stdlib.h>

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

void inserir(Arvore* t, No* z);

void percursoOrdemCrescente(No* x);

void percursoPreOrdem(No* x);

void percursoPosOrdem(No* x);

No* buscaArvore(No* x, int k);

No* buscaMaximo(No* inicio);

No* buscaMinimo(No* inicio);

No* sucessor(No* x);

No* antecessor(No* x);

#endif // __ABB_C__
