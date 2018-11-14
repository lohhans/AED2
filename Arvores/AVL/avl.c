#include "avl.h"

No* criarNo(int valor){ //Cria o No para inserir na Arvore
    No* no = (No*) malloc(sizeof(No));
    no->pai = NULL;
    no->filhoEsq = NULL;
    no->filhoDir = NULL;
    no->chave = valor;
    return no;
}

Arvore* criarArvore(){ //Cria a Arvore
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

int buscarMaior (int x, int y){ //Busca o valor maior
	if(x > y){
		return x;
	} else {
		return y;
	}
}

int saberAltura (No* x){ //Informa a altura da Arvore
	if (x == NULL){
		return -1;
	} else {
		return buscarMaior(saberAltura(x->filhoEsq), saberAltura(x->filhoDir)) + 1;
	}
}

No* noDesbalanceado(No* x){ //Retorna o no no desbalanceado
	while (x != NULL){
		if(abs (saberAltura(x->filhoEsq) - saberAltura(x->filhoDir)) > 1){
			return x;
		} else {
			x = x->pai;
		}
	}
	return NULL;
}

void balancear (Arvore* t, No* x){  //Metodo para balancear a Arvore
	if(saberAltura(x->filhoEsq) > saberAltura(x->filhoDir)){
		if(saberAltura(x->filhoEsq->filhoEsq) > saberAltura(x->filhoEsq->filhoDir)){
			rotacaoDireita(t, x);
		} else if(saberAltura(x->filhoEsq->filhoDir) > saberAltura(x->filhoEsq->filhoEsq)){
			rotacaoDuplaDireita(t, x);
		}
	}  else if(saberAltura(x->filhoDir) > saberAltura(x->filhoEsq)){
		if(saberAltura(x->filhoDir->filhoDir) > saberAltura(x->filhoDir->filhoEsq)){
			rotacaoEsquerda(t, x);
		} else if(saberAltura(x->filhoDir->filhoEsq) > saberAltura(x->filhoDir->filhoDir)){
			rotacaoDuplaEsquerda(t, x);
		}
	}
}

void inserir(Arvore* t, No* z){ //Metodo para inserir na Arvore
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

    No* a = noDesbalanceado(z);

    if(a != NULL){
        balancear(t, a);
    }
}

void percursoOrdemCrescente(No* raiz){ //Percurso em ordem crescente
    if(raiz == NULL){
        return;
    }

    percursoOrdemCrescente(raiz->filhoEsq);
    printf("%d\n", raiz->chave);
    percursoOrdemCrescente(raiz->filhoDir);
}

void percursoPreOrdem(No* raiz){ //Percurso pre ordem
    if(raiz == NULL){
        return;
    }

    printf("%d\n", raiz->chave);
    percursoPreOrdem(raiz->filhoEsq);
    percursoPreOrdem(raiz->filhoDir);
}

void percursoPosOrdem(No* raiz){ //Percurso pos ordem
    if(raiz == NULL){
        return;
    }

    percursoPosOrdem(raiz->filhoEsq);
    percursoPosOrdem(raiz->filhoDir);
    printf("%d\n", raiz->chave);
}

No* buscaArvore(No* x, int k){ //Retorna um no
    if(x == NULL || k == x->chave){
        return x;
    }

    if(k < x->chave){
        return buscaArvore(x->filhoEsq, k);
    } else {
        return buscaArvore(x->filhoDir, k);
    }
}

No* buscaMaximo(No* inicio){ //Retorna o maior no da arvore
    if(inicio == NULL){
        return inicio;
    }

    while(inicio->filhoDir != NULL){
        inicio = inicio->filhoDir;
    }

    return inicio;
}

No* buscaMinimo(No* inicio){ //Retorna o menor no da arvore
    if(inicio == NULL){
        return inicio;
    }

    while(inicio->filhoEsq != NULL){
        inicio = inicio->filhoEsq;
    }

    return inicio;
}

No* sucessor(No* x){ //Retorna o sucessor de um no da arvore
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

No* antecessor(No* x){ //Retorna o antecessor de um no da arvore
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

void rotacaoDireita(Arvore* t, No* p){ //rotacao simples direita
    if(p == NULL){
        return;
    }

    No* u; //criacao no
    No* t2; //criacao no
    No* paiDeTodos; //criacao no

    if(p->filhoEsq != NULL){ //atribuicao do valor do no
        u = p->filhoEsq;
    } else {
        u = NULL;
    }

    if(u->filhoDir != NULL){ //atribuicao do valor do no
        t2 = u->filhoDir;
        t2->pai = p;
    } else {
        t2 = NULL;
    }

    if(p->pai != NULL){ //atribuicao do valor do no
        u->pai = p->pai;
    } else {
        u->pai = NULL;
        t->raiz = u; //atribuicao da raiz para o valor do no
    }

    if(t2 != NULL){ //rotacao
        p->filhoEsq = t2;
    } else {
        p->filhoEsq = NULL;
    }

    u->filhoDir = p; //rotacao

    p->pai = u; //rotacao

    paiDeTodos = u->pai; //indexacao da raiz

    if(paiDeTodos != NULL){ //indexacao da raiz
        if(p->chave < paiDeTodos->chave){
            paiDeTodos->filhoEsq = u;
        } else {
            paiDeTodos->filhoDir = u;
        }
    }
}

void rotacaoEsquerda(Arvore* t, No* p){ //rotacao simples esquerda
    if(p == NULL){
        return;
    }

    No* z; //criacao no
    No* t2; //criacao no
    No* paiDeTodos; //criacao no

    if(p->filhoDir != NULL){ //atribuicao do valor do no
        z = p->filhoDir;
    } else {
        z = NULL;
    }

    if(z->filhoEsq != NULL){ //atribuicao do valor do no
        t2 = z->filhoEsq;
        t2->pai = p;
    } else {
        t2 = NULL;
    }

    if(p->pai != NULL){ //atribuicao do valor do no
        z->pai = p->pai;
    } else {
        z->pai = NULL;
        t->raiz = z; //atribuicao da raiz para o valor do no
    }

    if(t2 != NULL){ //rotacao
        p->filhoDir = t2;
    } else {
        p->filhoDir = NULL;
    }

    z->filhoEsq = p; //rotacao

    p->pai = z; //rotacao

    paiDeTodos = z->pai; //indexacao da raiz

    if(paiDeTodos != NULL){ //indexacao da raiz
        if(p->chave < paiDeTodos->chave){
            paiDeTodos->filhoEsq = z;
        } else {
            paiDeTodos->filhoDir = z;
        }
    }
}

void rotacaoDuplaDireita(Arvore* t, No* p){ //rotacao simples esquerda
    rotacaoEsquerda(t, p->filhoEsq);
    rotacaoDireita(t, p);
}

void rotacaoDuplaEsquerda(Arvore* t, No* p){ //rotacao simples esquerda
    rotacaoDireita(t, p->filhoDir);
    rotacaoEsquerda(t, p);
}

No* printArvore(Arvore* t, No* x){ //Imprime arvore no terminal
    printf("(");
    printf("%d", x->chave);
    if(x->filhoEsq != NULL){
        printArvore(t, x->filhoEsq);
    } else{
        printf("(X)");
    }

	if(x->filhoDir != NULL){
        printArvore(t, x->filhoDir);
    } else{
        printf("(X)");
    }
    printf(")");
}

void receberArquivo(char vetor[], Arvore* t){ //Leitura da entrada da Arvore
    int numero;
    FILE* arquivo = fopen(vetor, "r");

	if(arquivo != NULL){
		while(fscanf(arquivo, "%d", &numero) != EOF){//Fim Do Arquivo = End Of File
			No* No = criarNo(numero);
			inserir(t, No);
		}
	}

	fclose(arquivo);
}

void escreverArquivo(FILE* arquivo, Arvore* t, No* x){ //Escrita da saida da Arvore
    fprintf(arquivo, "(");
    fprintf(arquivo, "%d", x->chave);
    if(x->filhoEsq != NULL){
        escreverArquivo(arquivo, t, x->filhoEsq);
    } else{
        fprintf(arquivo, "(X)");
    }

    if(x->filhoDir != NULL){
        escreverArquivo(arquivo, t, x->filhoDir);
    } else{
        fprintf(arquivo, "(X)");
    }
    fprintf(arquivo, ")");
}
