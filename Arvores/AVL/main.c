#include "avl.h"

int main(int argc, char *argv[]){
	Arvore* t = criarArvore();

	for (int i = 0; i < argc; i++) {
		if(argv[i] != NULL){
			if(strcmp("-h", argv[i]) == 0){
				printf("\n-h			: mostra o help \
				\n-o <arquivo>		: redireciona a saida para o arquivo \
				\n-f <arquivo>		: indica o arquivo que contém os dados a serem adicionados na AVL \
				\n-m			: imprime o menor elemento da AVL \
				\n-M			: imprime o maior elemento da AVL \
				\n-a <elemento>		: imprime o antecessor na AVL do elemento ou caso contrário imprime -1 \
				\n-s <elemento>		: imprime o sucessor na AVL do elemento ou caso contrário imprime -1\n\n");
			} else if(strcmp("-o", argv[i]) == 0){
				if(!argv[i+1]){
					printf("ERRO: Parametros invalidos! \n");
					break;
				} else {
					FILE* arquivo = fopen(argv[i+1], "w");
					escreverArquivo(arquivo, t, t->raiz);
				}
			} else if(strcmp("-f", argv[i]) == 0){
				if(!argv[i+1]){
					printf("ERRO: Parametros invalidos! \n");
					break;
				} else {
					receberArquivo(argv[i+1], t);
					if (argv[i+2] == NULL) {
						printArvore(t, t->raiz);
						printf("\n");
					}
				}
			} else if(strcmp("-m", argv[i]) == 0){
				if(!argv[i+1]){
					No* minimo = buscaMinimo(t->raiz);
					printf("%d\n", minimo->chave);
				} else {
					printf("ERRO: Parametros invalidos! \n");
					break;
				}
			} else if(strcmp("-M", argv[i]) == 0){
				if(!argv[i+1]){
					No* maximo = buscaMaximo(t->raiz);
					printf("%d\n", maximo->chave);
				} else {
					printf("ERRO: Parametros invalidos! \n");
					break;
				}
			} else if(strcmp("-a", argv[i]) == 0){
				if(strcmp("-h", argv[i+1]) == 0 ||strcmp("-o", argv[i+1]) == 0
				|| strcmp("-f", argv[i+1]) == 0 || strcmp("-m", argv[i+1]) == 0
				|| strcmp("-M", argv[i+1]) == 0 || strcmp("-s", argv[i+1]) == 0){
					printf("ERRO: Parametros invalidos! \n");
					break;
				} else {
					No* novoNo = buscaArvore(t->raiz, atoi(argv[i+1]));
					No* noAntecessor = antecessor(novoNo);
					if (noAntecessor == NULL) {
						printf("-1\n");
					} else {
						printf("%d\n", noAntecessor->chave);
					}
				}
			} else if(strcmp("-s", argv[i]) == 0){
				if(strcmp("-h", argv[i+1]) == 0 ||strcmp("-o", argv[i+1]) == 0
				|| strcmp("-f", argv[i+1]) == 0 || strcmp("-m", argv[i+1]) == 0
				|| strcmp("-M", argv[i+1]) == 0 || strcmp("-a", argv[i+1]) == 0){
					printf("ERRO: Parametros invalidos! \n");
					break;
				} else {
					No* novoNo = buscaArvore(t->raiz, atoi(argv[i+1]));
					No* noSucessor = sucessor(novoNo);
					if (noSucessor == NULL) {
						printf("-1\n");
					} else {
						printf("%d\n", noSucessor->chave);
					}
				}
			}
		}
	}

	return 0;
}
