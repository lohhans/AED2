#include "prim.h"

int main(int argv, char *argc[]){
    Grafo grafoI;
    Grafo grafoF;
    vetorA vetorA;
    int i;
    int flag = 0;
    for(i = 1; i < argv; i++){
        if(strcmp(argc[i], "-h") == 0){
            printf("\n  -h             |Mostra menu de ajuda");
            printf("\n  -o arquivo.dat |saida para arquivo  ");
            printf("\n  -f arquivo.dat |Entrada para arquivo");
            printf("\n  -s inteiro     |solução    ");
            printf("\n                      ");
            printf("\n\n");
        }
        if(strcmp(argc[i], "-s")== 0){
            imprimirArestas(&vetorA);
            // imprimirGrafo(&grafoI);
            flag = 0;
        }

        if(strcmp(argc[i], "-o") == 0){
            FILE *arquivo = fopen(argc[i+1], "w");
            if (arquivo == NULL){
                printf("ERRO - Arquivo de saida invalido\n");
            }
            else{
                escreverArquivo(arquivo, &vetorA);
            }
            flag = 1;
        }
        if(strcmp(argc[i], "-f")== 0){
            receberArquivo(argc[i+1], &grafoI);
            inicializaGrafo(&grafoF, grafoI.numeroArestas, grafoI.numeroVertices - 1);
            prim(&grafoI, &grafoF, &vetorA);
            flag = 1;
        }
    }
    if(flag == 1){
    	int peso = 0;
        int j;
        for(j = 0;j < vetorA.contador2; j++ ){
            peso += vetorA.vetor[j]->peso;
        }
        printf("%d\n", peso);
    }
    return 0;
}
