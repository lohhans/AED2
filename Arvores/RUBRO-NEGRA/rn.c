#include "rn.h"

No* criarNo(int valor){ //Cria o No para inserir na Arvore
    No* no = (No*) malloc(sizeof(No));
    no->pai = NULL;
    no->filhoEsq = NULL;
    no->filhoDir = NULL;
    no->chave = valor;
    no->cor = 1; //vermelho
    return no;
}

Arvore* criarArvore(){ //Cria a Arvore
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

No* buscarTio(No* x){ //Retorna o tio de um no
    No* tio = NULL;

    if(x->pai != NULL){
        No* avo = x->pai->pai;

        if(avo != NULL && avo->filhoEsq != x->pai){
            tio = avo->filhoEsq;
        } else if (avo != NULL && avo->filhoDir != x->pai){
            tio = avo->filhoDir;
        }
    }

    return tio;
}

int buscarMaior (int x, int y){ //Busca o valor maior
	if(x > y){
		return x;
	} else {
		return y;
	}
}

void balancear (Arvore* t, No* x){  //Metodo para balancear a Arvore
    if(x->pai == NULL){
        x->cor = 0; //preto
        t->raiz = x;
    } else if(x->pai->cor == 1){
        No* tio = buscarTio(x);

        if(tio != NULL && tio->cor == 1){ //caso 1: o tio de x é vermelho
            x->pai->cor = 0; //preto
            tio->cor = 0; //preto
            x->pai->pai->cor = 1; //vermelho
            balancear(t, x->pai->pai);
        } else if(x == x->pai->filhoEsq){ //caso 2: o tio de x é preto e x é filho a esquerda

            if(x->pai == x->pai->pai->filhoEsq){ //caso 2.1: o pai de x é filho a esquerda
                x->pai->cor = 0;
                x->pai->pai->cor = 1;
                rotacaoDireita(t, x->pai->pai);
            } else if(x->pai == x->pai->pai->filhoDir){ //caso 3.1: o pai de x é filho a direita
                x->cor = 0; //preto
				x->pai->pai->cor = 1; //vermelho
				rotacaoDuplaEsquerda(t, x->pai->pai);
            }
        } else if (x == x->pai->filhoDir) { //caso 2.2: o tio de x é preto e x é filho a direita

            if (x->pai == x->pai->pai->filhoDir){ //caso 3.1: o pai de x é filho a direita
                    x->pai->cor = 0;
                    x->pai->pai->cor = 1;
                    rotacaoEsquerda(t, x->pai->pai);
            } else if (x->pai == x->pai->pai->filhoEsq){ //caso 3.2: o pai de x é filho a esquerda
				x->cor = 0;
				x->pai->pai->cor = 1;
				rotacaoDuplaDireita(t, x->pai->pai);
			}
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

    balancear(t, z);
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

No* buscaArvore(No* x, int k){  //Retorna um no
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
    if(x->cor == 0){
        printf("N");
    } else {
        printf("R");
    }
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
    if(x->cor == 0){
        fprintf(arquivo, "N");
    } else {
        fprintf(arquivo, "R");
    }
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
