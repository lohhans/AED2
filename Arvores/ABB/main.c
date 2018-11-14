#include <stdio.h>
#include "abb.h"

void main(){
	Arvore* t = criarArvore();
	No* No1 = criarNo(8);
	No* No2 = criarNo(5);
	No* No3 = criarNo(10);
	No* No4 = criarNo(4);
	No* No5 = criarNo(6);
	No* No6 = criarNo(9);
	No* No7 = criarNo(11);

	inserir(t, No1);
	inserir(t, No2);
	inserir(t, No3);
	inserir(t, No4);
	inserir(t, No5);
	inserir(t, No6);
	inserir(t, No7);

	printf("\nPERCURSO EM ORDEM CRESCENTE: \n");
	percursoOrdemCrescente(t->raiz);

	printf("\nPERCURSO EM PRE ORDEM: \n");
	percursoPreOrdem(t->raiz);

	printf("\nPERCURSO EM POS ORDEM: \n");
	percursoPosOrdem(t->raiz);

	No* a = buscaArvore(t->raiz, 10);
	printf("\nNO ENCONTRADO: %d\n", a->chave);

	No* b = buscaMaximo(t->raiz);
	printf("\nMAXIMO: %d\n", b->chave);

	No* c = buscaMinimo(t->raiz);
	printf("\nMINIMO: %d\n", c->chave);

	No* d = sucessor(t->raiz);
	printf("\nSUCESSOR: %d\n", d->chave);

	No* e = antecessor(t->raiz);
	printf("\nANTECESSOR: %d\n", e->chave);
}
