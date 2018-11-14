#include "hash.h"

int main(int argc, char *argv[]){
	Hash* h = criarHash(11);

	for (int i = 0; i < argc; i++) {
		if(argv[i] != NULL){
			if(strcmp("-h", argv[i]) == 0){
				printf("\n-h			: mostra o help \
				\n-o <arquivo>		: redireciona a saida para o arquivo \
				\n-f <arquivo>		: indica o arquivo que contém os dados a serem adicionados na Heap \
				\n-m			: o tamanho da hash (default=11) \n\n");
			} else if(strcmp("-o", argv[i]) == 0){
				if(!argv[i+1]){
					printf("ERRO: Parametros invalidos! \n");
					break;
				} else {
					FILE* arquivo = fopen(argv[i+1], "w");
					escreverArquivo(arquivo, h);
				}
			} else if(strcmp("-f", argv[i]) == 0){
				if(!argv[i+1]){
					printf("ERRO: Parametros invalidos! \n");
					break;
				} else {
					receberArquivo(argv[i+1], h);
					if (argv[i+2] == NULL) {
						imprimirHash(h);
					}
				}
			} else if(strcmp("-m", argv[i]) == 0){
				if(!argv[i+1]){
					printf("ERRO: Parametros invalidos! \n");
					break;
				} else {
					mudarTamanhoHash(h, atoi(argv[i+1]));
				}
			}
		}
	}

    return 0;
}
