#include "floyd.h"

int main(int argv, char *argc[]){
	Grafo* origem = inicializarGrafo(1, 1);
    Grafo* destino = inicializarGrafo(1, 1);
    int boolDestino = 0, verticeI = 0, verticeF = 0, salvar = 0;
    char arquivoSaida[100];

    for(int i = 1; i < argv; i++){
        if(strcmp(argc[i], "-h") == 0){
			printf("-h			: mostra o help \
			\n-o <arquivo>		: redireciona a saida para o arquivo \
			\n-f <arquivo>		: indica o ‘‘arquivo’’ que contém o grafo de entrada \
			\n-i			: vértice inicial (obrigatório) \
			\n-l			: vértice final (opcional) \n\n");
        }

        if(strcmp(argc[i], "-f") == 0){
			receberArquivo(argc[i+1], origem);
        }

		if(strcmp(argc[i], "-i") == 0){
            floydWarshall(origem, destino);
            verticeI = atoi(argc[i+1]);
        }

		if(strcmp(argc[i], "-o") == 0){
            strcpy(arquivoSaida, argc[i+1]);
        	salvar = 1;
        }

		if(strcmp(argc[i], "-l") == 0){
            boolDestino = 1;
            verticeF = atoi(argc[i+1]);
        }
    }

    if (boolDestino == 1){
        imprimirDestino(destino, verticeI, verticeF);
    } else {
        imprimirGrafo(destino, verticeI);
	}

    if(salvar == 1){
        FILE* arquivo = fopen(arquivoSaida, "w");

        if (arquivo == NULL){
            printf("ERRO - Arquivo de saida invalido\n");
        } else{
            escreverArquivo(arquivo, destino, verticeI);
        }

        fclose(arquivo);
    }

    return 0;
}
