#include "dijkstra.h"
#include "heap.c"

Grafo* inicializarGrafo(int ponderado, int digrafo){
  	Grafo* grafo = (Grafo*) malloc(sizeof(Grafo)); //Alocando memoria para o grafo
  	Aresta* arestas = (Aresta*) malloc(sizeof(Aresta)); //Alocando memoria para as arestas

	grafo->arestas = arestas; //Atribuindo arestas ao grafo

	for(int i = 0; i < maximoVertice; i++){ //Inicializando grafo com 0
    	for(int j = 0; j < maximoVertice; j++){
      		grafo->v[i][j] = 0;
    	}
  	}

	grafo->ponderado = ponderado; //Definindo se o grafo é ponderado
	grafo->digrafo = digrafo; //Definindo se o grafo é digrafo

	return grafo;
}

Aresta* inserirAresta(Aresta* aresta, int verticeOrigem, int verticeDestino, int peso){
	Aresta* novaAresta = (Aresta*)malloc(sizeof(Aresta)); //Alocando memoria para as arestas
	novaAresta->verticeOrigem = verticeOrigem; //Definindo o vertice de origem da aresta
	novaAresta->verticeDestino = verticeDestino; //Definindo o vertice de destino da aresta
	novaAresta->peso = peso; //Definindo o peso da aresta

	if(aresta == NULL){ //Alocando aresta
        novaAresta->prox = NULL;
        return novaAresta;
	}

	novaAresta->prox = aresta; //Alocando aresta
	return novaAresta;
}

void inserirGrafo(Grafo* grafo, int verticeOrigem, int verticeDestino, int peso){ //Inserção no Grafo de acordo se é ponderado e digrafo
    grafo->arestas = inserirAresta(grafo->arestas, verticeOrigem, verticeDestino, peso);

    if(grafo->ponderado == 1 && grafo->digrafo == 1){
        grafo->v[verticeOrigem][verticeDestino] = peso;
    } else if(grafo->ponderado == 1 && grafo->digrafo == 0){
        grafo->v[verticeOrigem][verticeDestino] = peso;
        grafo->v[verticeDestino][verticeOrigem] = peso;
    } else if(grafo->ponderado == 0 && grafo->digrafo == 1){
        grafo->v[verticeOrigem][verticeDestino] = 1;
    } else if(grafo->ponderado == 0 && grafo->digrafo == 0){
        grafo->v[verticeOrigem][verticeDestino] = 1;
        grafo->v[verticeDestino][verticeOrigem] = 1;
    }
}

void ordenacao(Aresta* aresta){
	int troca = 0, a, b, c;

	while(troca == 0){
		troca = 1;
		for(Aresta* aux = aresta; aux->prox!=NULL; aux = aux->prox){
			if(aux->peso > aux->prox->peso){
				c = aux->peso;
				aux->peso = aux->prox->peso;
				aux->prox->peso = c;

				a = aux->verticeOrigem;
                aux->verticeOrigem = aux->prox->verticeOrigem;
                aux->prox->verticeOrigem = a;

				b = aux->verticeDestino;
                aux->verticeDestino = aux->prox->verticeDestino;
                aux->prox->verticeDestino = b;
                troca = 0;
			}
		}
	}
}

void dijkstra(Grafo* grafo, Grafo* grafo2, int v0){
    Aresta* aux;
	ArestaAux* m[maximoVertice];
	ArestaAux* min;
	Heap* p = (Heap*)malloc(sizeof(Heap));
	int escolha;

    ordenacao(grafo->arestas);

	for(int i = 0; i < maximoVertice; i++){
        m[i] = (ArestaAux*)malloc(sizeof(m));
        m[i]->vertice = i;
        m[i]->custoTotal = 99999;
        m[i]->prev = -1;

        if(i == v0){
            m[i]->custoTotal = 0;
        }

        inserirHeap(p, m[i]);
    }

	criaHeap(p);

	while(heapVazia(p) != 1){
        min = extrairMin(p);

		for(aux = grafo->arestas->prox; aux != NULL; aux = aux->prox){
            if(aux->verticeOrigem == min->vertice || aux->verticeDestino == min->vertice){
                if(aux->verticeOrigem == min->vertice){
                    escolha = aux->verticeDestino;
                } else if(aux->verticeDestino == min->vertice){
                    escolha = aux->verticeOrigem;
                } if(m[escolha]->custoTotal > min->custoTotal + aux->peso){
                    m[escolha]->custoTotal = min->custoTotal + aux->peso;
                    m[escolha]->prev = min->vertice;
                    criaHeap(p);
                }
            }
        }

		if(min->prev != -1){
            inserirGrafo(grafo2, v0, min->vertice, min->custoTotal);
        }
    }
}

void receberArquivo(char arquivo[], Grafo* grafo){
	FILE* abrirArquivo = fopen(arquivo, "r");

    if(abrirArquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(0);
    } else {
        int vertices, arestas;
        fscanf(abrirArquivo, "%d %d\n", &vertices, &arestas);

        char** vetor = (char**) malloc(sizeof(char) * 2);
        int* vetor2 = (int*) malloc(sizeof(int*) * 2);

        int i;

        for(i = 0; i < 2; i++){
            vetor[i] = (char*) malloc(sizeof(char));
        }

        fscanf(abrirArquivo, "%d", &vetor2[0]);
        vetor[0][0] = fgetc(abrirArquivo);
        fscanf(abrirArquivo, " %d", &vetor2[1]);
        vetor[1][0] = fgetc(abrirArquivo);

        if(strcmp(vetor[1], " ") ==0){
        	int peso;
        	fscanf(abrirArquivo, " %d\n", &peso);
        	inserirGrafo(grafo, vetor2[0], vetor2[1], peso);
        	for(i = 0; i < arestas; i++){
        		int origem, destino;
        		fscanf(abrirArquivo, "%d %d %d\n",&origem, &destino, &peso);
        		inserirGrafo(grafo, origem, destino, peso);
        	}
        } else {
        	inserirGrafo(grafo, vetor2[0], vetor2[1], 1);
        	for(i = 0; i < arestas; i++){
        		int origem, destino;
        		fscanf(abrirArquivo, "%d %d\n",&origem, &destino);
        		inserirGrafo(grafo, origem, destino, 1);
        	}
        }
    }

    fclose(abrirArquivo);
}

void escreverArquivo(FILE* arquivo, Grafo* grafo, int v0){
    fprintf(arquivo, "%d:%d ", v0, 0);

    for(int i = 0; i < maximoVertice; i++){
        for(int j = 0; j < maximoVertice; j++){
            if(grafo->v[i][j] != 0 && grafo->ponderado== 1){
                fprintf(arquivo, "%d:%d ",j, grafo->v[i][j]);
            } else if(grafo->v[i][j] != 0 && grafo->ponderado== 1){
                fprintf(arquivo, "%d:%d ",j,grafo->v[i][j]);
            }
        }
    }

	fprintf(arquivo, "\n");
}

void imprimirGrafo(Grafo *grafo, int v0){
    printf("%d:%d ", v0, 0);

    for(int i = 0; i < maximoVertice; i++){
        for(int j = 0; j < maximoVertice; j++){
            if(grafo->v[i][j] != 0 && grafo->ponderado == 0){
                printf("%d:%d ",j, grafo->v[i][j]);
            } else if(grafo->v[i][j] != 0 && grafo->ponderado == 1){
                printf("%d:%d ",j,grafo->v[i][j]);
            }
        }
    }

	printf("\n");
}

void imprimirDestino(Grafo *grafo, int inicial, int final){
    if(grafo->v[inicial][final] != 0 && grafo->ponderado == 0){
        printf("%d", grafo->v[inicial][final]);
    } else if(grafo->v[inicial][final] != 0 && grafo->ponderado == 1){
        printf("%d", grafo->v[inicial][final]);
    }

    printf("\n");
}
