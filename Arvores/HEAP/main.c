#include "heap.h"

int main(int argc, char *argv[]){
	Heap* h = criarHeap(99999999);

	for (int i = 0; i < argc; i++) {
		if(argv[i] != NULL){
			if(strcmp("-h", argv[i]) == 0){
				printf("\n-h			: mostra o help \
				\n-o <arquivo>		: redireciona a saida para o arquivo \
				\n-f <arquivo>		: indica o arquivo que contém os dados a serem adicionados na Heap \
				\n-m			: indica que a estrutura será uma heap mínima \n\n");
			}else if(strcmp("-o", argv[i]) == 0){
				if(!argv[i+1]){
					printf("ERRO: Parametros invalidos! \n");
					break;
				} else {
					if (strcmp("-m", argv[1]) == 0) {
						receberArquivo(argv[3], h);
						heapSortMin(h);
						FILE* arquivo = fopen(argv[5], "w");
						escreverArquivo(arquivo, h);
						return 0;
					} else{
						FILE* arquivo = fopen(argv[i+1], "w");
						escreverArquivo(arquivo, h);
					}
				}
			} else if(strcmp("-f", argv[i]) == 0){
				if(!argv[i+1]){
					printf("ERRO: Parametros invalidos! \n");
					break;
				} else {
					receberArquivo(argv[i+1], h);
					heapSortMax(h);
					if (argv[i+2] == NULL) {
						imprimirHeap(h);
					}
				}
			} else if(strcmp("-m", argv[i]) == 0){
				if(strcmp("-f", argv[i+1] ) == 0){
					if(!argv[i+2]){
						printf("ERRO: Parametros invalidos! \n");
						break;
					} else {
						receberArquivo(argv[i+2], h);
						heapSortMin(h);
						if (argv[i+3] == NULL) {
							imprimirHeap(h);
							break;
						}
					}

				} else{
					printf("ERRO: Parametros invalidos! \n");
					break;
				}
			}
		}
	}



    return 0;
}
