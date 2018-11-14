#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

No* criarNo(int valor){
    No* no = (No*) malloc(sizeof(No));
    no->pai = NULL;
    no->filhoEsq = NULL;
    no->filhoDir = NULL;
    no->chave = valor;
    return no;
}

Arvore* criarArvore(){
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

void inserir(Arvore* t, No* z){
    No* y = NULL;
    No* x = t->raiz;

    while (x != NULL){
        y=x;

        if(z->chave < x->chave){
            x = x->filhoEsq;
        } else {
            x = x->filhoDir;
         }
    }

    z->pai = y;

    if(y == NULL){
        t->raiz = z;
    } else if(z->chave < y->chave){
        y->filhoEsq = z;
    } else {
        y->filhoDir = z;
    }
}

void percursoOrdemCrescente(No* raiz){
    if(raiz == NULL){
        return;
    }

    percursoOrdemCrescente(raiz->filhoEsq);
    printf("%d\n", raiz->chave);
    percursoOrdemCrescente(raiz->filhoDir);
}

void percursoPreOrdem(No* raiz){
    if(raiz == NULL){
        return;
    }

    printf("%d\n", raiz->chave);
    percursoPreOrdem(raiz->filhoEsq);
    percursoPreOrdem(raiz->filhoDir);
}

void percursoPosOrdem(No* raiz){
    if(raiz == NULL){
        return;
    }

    percursoPosOrdem(raiz->filhoEsq);
    percursoPosOrdem(raiz->filhoDir);
    printf("%d\n", raiz->chave);
}

No* buscaArvore(No* x, int k){
    if(x == NULL || k == x->chave){
        return x;
    }

    if(k < x->chave){
        return buscaArvore(x->filhoEsq, k);
    } else {
        return buscaArvore(x->filhoDir, k);
    }
}

No* buscaMaximo(No* inicio){
    if(inicio == NULL){
        return inicio;
    }

    while(inicio->filhoDir != NULL){
        inicio = inicio->filhoDir;
    }

    return inicio;
}

No* buscaMinimo(No* inicio){
    if(inicio == NULL){
        return inicio;
    }

    while(inicio->filhoEsq != NULL){
        inicio = inicio->filhoEsq;
    }

    return inicio;
}

No* sucessor(No* x){
    if(x == NULL){
        return x;
    }

    if(x->filhoDir != NULL){
        return buscaMinimo(x->filhoDir);
    }

    No* y = x->pai;

    while (y != NULL && x == y->filhoDir) {
        x = y;
        y = y->pai;
    }

    return y;
}

No* antecessor(No* x){
    if(x != NULL){
        if(x->filhoEsq != NULL){
            return buscaMaximo(x->filhoEsq);
        }

        No* y = x->pai;

        while(y != NULL && x == y->filhoEsq){
            x = y;
            y = y->pai;
        }

        return y;
    }
}
