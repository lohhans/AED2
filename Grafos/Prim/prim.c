#include "prim.h"

No* alocarAresta(int verticeOrigem, int verticeDestino, int peso){
    Aresta *aresta = (Aresta *)malloc(sizeof(Aresta));
    No *novoNo = (No *)malloc(sizeof(No));
    aresta->verticeOrigem = verticeOrigem;
    aresta->verticeDestino = verticeDestino;
    aresta->peso = peso;
    novoNo->prox = NULL;
    novoNo->aresta = aresta;
    return novoNo;
}

void inicializarVetorArestas(vetorA *vetorA, int valor){
    vetorA->contador2 = valor;
}

void inicializarAresta(vetorA *vetorA, Aresta *aresta){
    vetorA->vetor[vetorA->contador2] = aresta;
    vetorA->contador2++;
}

void inicializarVetorVertices(vetorV *vetor){
    vetor->contador2 = 0;
}

void inicializarVertice(vetorV *vetorV, int numero){
    vetorV->vetor[vetorV->contador2] = numero;
    vetorV->contador2++;
}

void inicializaGrafo(Grafo *grafo, int numeroArestas, int numeroVertices){
    int i;
    grafo->numeroVertices = numeroVertices;
	grafo->numeroArestas = numeroArestas;
	grafo->contador = 0;

    for(i = 0; i <= numeroVertices; i++){
        grafo->vetorArestas[i] = NULL;
	}
}

int adicionarAresta(Grafo *grafo, int verticeOrigem, int verticeDestino, int peso){
    No *no1;
    no1 = alocarAresta(verticeOrigem, verticeDestino, peso);
    No *aux = grafo->vetorArestas[verticeOrigem];
    no1->prox = aux;
    aux = no1;
    grafo->vetorArestas[verticeOrigem] = no1;
    grafo->contador++;
}

int adicionarVertice(vetorV *verticeInicial, vetorV *verticeFinal, int verticeOrigem, int verticeDestino){
    int i, j;
    int origem = 0;
    int destino = 0;

	for(i = 0; i < verticeInicial->contador2; i++){
        if(verticeInicial->vetor[i] == verticeOrigem){
            origem = -1;
        }
    }

	for(i = 0; i < verticeInicial->contador2; i++){
		if(verticeInicial->vetor[i] == verticeDestino){
            destino = -1;
		}
	}

    if(origem == -1 && destino == 0){
        verticeFinal->vetor[verticeFinal->contador2] = verticeDestino;
        verticeFinal->contador2++;
	}

    if (destino == -1 && origem == 0){
        verticeFinal->vetor[verticeFinal->contador2] = verticeOrigem;
        verticeFinal->contador2++;
	}
}

void criarArestas(Grafo *grafo, vetorA *vetorA){
    int i;
	for(i = 0; i <= grafo->numeroVertices; i++){
		No *aux = grafo->vetorArestas[i];
		while(aux != NULL){
			vetorA->vetor[vetorA->contador2] = aux->aresta;
			vetorA->contador2++;
			aux = aux->prox;
		}
	}

    ordenar(vetorA);
}

void criarVertices(Grafo *grafo, vetorV *vetorV){
    int i;
	for(i = 0; i <= grafo->numeroVertices; i++){
		vetorV->vetor[vetorV->contador2] = i;
		vetorV->contador2++;
	}
}

void deletarAresta(vetorA *vetorA, int verticeOrigem, int verticeDestino){
    int i, j;
    for(i = 0; i < vetorA -> contador2; i++){
        if(vetorA -> vetor[i] -> verticeOrigem == verticeOrigem && vetorA -> vetor[i] -> verticeDestino == verticeDestino){
            for(j = i; j < vetorA -> contador2 - 1; j++){
                vetorA -> vetor[j] = vetorA -> vetor[j+1];
            }

            vetorA -> contador2--;
            break;
        }
    }
}

void deletarVertice(vetorV *vetorV, int indice){
    int i, j;
	for(i = 0; i < vetorV->contador2; i++){
        if(vetorV->vetor[i] == indice){
            for(j = i; j < vetorV->contador2 - 1; j++){
                vetorV->vetor[j] = vetorV->vetor[j+1];
            }
            vetorV->contador2--;
            break;
        }
	}
}

void ordenar(vetorA *vetorA){
    int i, j, minimo;
    Aresta *aux;

    for(i = 0; i < vetorA->contador2 - 1; i++){
        minimo = i;
        for(j = i+1; j < vetorA->contador2; j++){
            if(vetorA -> vetor[j] -> peso < vetorA -> vetor[minimo] -> peso){
                minimo = j;
            }
        }

        if(i != minimo){
            aux = vetorA -> vetor[i];
            vetorA -> vetor[i] = vetorA -> vetor[minimo];
            vetorA -> vetor[minimo] = aux;
        }
    }
}

void ordenarArquivo(vetorA *vetorA){
    int i, j, minimo;
    Aresta *aux;
    for(i = 0; i < vetorA->contador2 - 1; i++){
        minimo = i;
        for(j = i+1; j < vetorA->contador2; j++){
            if(vetorA -> vetor[j] -> verticeOrigem < vetorA -> vetor[minimo] -> verticeOrigem){
                minimo = j;
            }
        }

        if(i != minimo){
            aux = vetorA -> vetor[i];
            vetorA -> vetor[i] = vetorA -> vetor[minimo];
            vetorA -> vetor[minimo] = aux;
        }
    }
}

int calcularPeso(vetorA *vetorA){
    int pesoTotal = 0;
    int i;
    for(i = 0; i < vetorA->contador2; i++ ){
        pesoTotal = pesoTotal + vetorA->vetor[i]->peso;
    }

    return pesoTotal;
}

int verificarPrim(vetorV *vetorV, int verticeOrigem, int verticeDestino){
    int i, j;
    int resultado = 0;
    for(i = 0; i < vetorV->contador2; i++){
        if(vetorV->vetor[i] == verticeOrigem){
            for(j = 0; j < vetorV->contador2; j++){
                if(vetorV->vetor[j] == verticeDestino){
                    resultado = -1;
                }
            }
        }
    }

    return resultado;
}


int verificarPrim2(vetorV *vetorV, int verticeOrigem, int verticeDestino){
    int i, j;
    int flag1 = 0;
    int flag2 = 0;
    int resultado = 0;

    for(i = 0; i < vetorV->contador2; i++){
        if(vetorV->vetor[i] == verticeOrigem){
            flag1 = -1;
        }
    }

    for(i = 0; i < vetorV->contador2; i++){
        if(vetorV->vetor[i] == verticeDestino){
            flag2 = -1;
		}
	}

    if(flag1 == 0 && flag2 == 0){
        resultado = -1;
    }

    return resultado;
}

void prim(Grafo *grafoI, Grafo *grafoF, vetorA *vetorArestaF){
    vetorA vetorA;
    vetorV verticeInicial, verticeFinal;
    inicializarVetorArestas(&vetorA, 0);
    inicializarVetorVertices(&verticeInicial);
    inicializarVetorVertices(&verticeFinal);
    criarArestas(grafoI, &vetorA);
    criarVertices(grafoI, &verticeInicial);
    int j;
    int variavel = 0;

    for(j = 0; j <= vetorA.contador2; j++){
		if(grafoF->contador == 0){
			adicionarAresta(grafoF, vetorA.vetor[0]->verticeOrigem, vetorA.vetor[0]->verticeDestino, vetorA.vetor[0]->peso);
			inicializarAresta(vetorArestaF, vetorA.vetor[0]);
			deletarVertice(&verticeInicial, vetorA.vetor[0]->verticeDestino);
			deletarVertice(&verticeInicial, vetorA.vetor[0]->verticeOrigem);
			inicializarVertice(&verticeFinal, vetorA.vetor[0]->verticeOrigem);
			inicializarVertice(&verticeFinal, vetorA.vetor[0]->verticeDestino);
			deletarAresta(&vetorA, vetorA.vetor[0]->verticeOrigem, vetorA.vetor[0]->verticeDestino);
		} else if(grafoF->contador == grafoI->numeroVertices - 1){
			break;
		} else{
			int i;
			for(i = 0; i < vetorA.contador2; i++){
				int ambosVerticesNoVetor = verificarPrim(&verticeFinal, vetorA.vetor[variavel]->verticeOrigem, vetorA.vetor[variavel]->verticeDestino);
				int ambosVerticesForaVetor = verificarPrim2(&verticeFinal, vetorA.vetor[variavel]->verticeOrigem, vetorA.vetor[variavel]->verticeDestino);
				if(verticeInicial.contador2 == 0){
					break;
				} else{
					if(ambosVerticesForaVetor == -1){
					 	variavel++;
					} else if(ambosVerticesNoVetor == -1){
						deletarAresta(&vetorA, vetorA.vetor[variavel]->verticeOrigem, vetorA.vetor[variavel]->verticeDestino);
						variavel = 0;
					} else{
                        adicionarAresta(grafoF, vetorA.vetor[variavel]->verticeOrigem, vetorA.vetor[variavel]->verticeDestino, vetorA.vetor[variavel]->peso);
                        inicializarAresta(vetorArestaF, vetorA.vetor[variavel]);
                        deletarVertice(&verticeInicial, vetorA.vetor[variavel]->verticeOrigem);
                        deletarVertice(&verticeInicial, vetorA.vetor[variavel]->verticeDestino);
                        adicionarVertice(&verticeFinal, &verticeFinal, vetorA.vetor[variavel]->verticeOrigem, vetorA.vetor[variavel]->verticeDestino);
                        deletarAresta(&vetorA, vetorA.vetor[variavel]->verticeOrigem, vetorA.vetor[variavel]->verticeDestino);
                        variavel = 0;
					}
				}
			}
		}
	}
}

void imprimirArestas(vetorA *vetorA){
    for(int i = 0; i < vetorA->contador2-1; i++){
        for(int k = i+1; k < vetorA->contador2; k++){
            if (vetorA->vetor[i]->verticeOrigem == vetorA->vetor[k]->verticeOrigem){
                if ((vetorA->vetor[k]->verticeDestino < vetorA->vetor[i]->verticeDestino)){
                    Aresta* aux = vetorA->vetor[i];
                    vetorA->vetor[i] = vetorA->vetor[k];
                    vetorA->vetor[k] = aux;
                }
            } else if (vetorA->vetor[i]->verticeOrigem > vetorA->vetor[k]->verticeOrigem) {
                Aresta* aux = vetorA->vetor[i];
                vetorA->vetor[i] = vetorA->vetor[k];
                vetorA->vetor[k] = aux;
            }
        }
    }

    for(int j = 0; j < vetorA->contador2; j++ ){
        printf("(%d,%d) ", vetorA->vetor[j]->verticeOrigem, vetorA->vetor[j]->verticeDestino);
    }
    printf("\n");
}

void receberArquivo(char arquivo[], Grafo* grafo){
	FILE* abrirArquivo = fopen(arquivo, "r");

    if(abrirArquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(0);
    } else {
        int vertices, arestas;
        fscanf(abrirArquivo, "%d %d\n", &vertices, &arestas);
        inicializaGrafo(grafo, vertices, arestas);

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
        	adicionarAresta(grafo, vetor2[0], vetor2[1], peso);
        	for(i = 0; i < arestas; i++){
        		int origem, destino;
        		fscanf(abrirArquivo, "%d %d %d\n",&origem, &destino, &peso);
        		adicionarAresta(grafo, origem, destino, peso);
        	}
        } else {
        	adicionarAresta(grafo, vetor2[0], vetor2[1], 1);
        	for(i = 0; i < arestas; i++){
        		int origem, destino;
        		fscanf(abrirArquivo, "%d %d\n",&origem, &destino);
        		adicionarAresta(grafo, origem, destino, 1);
        	}
        }
    }

    fclose(abrirArquivo);
}

void escreverArquivo(FILE* arquivo, vetorA *vetorA){
    for(int i = 0; i < vetorA->contador2-1; i++){
        for(int k = i+1; k < vetorA->contador2; k++){
            if (vetorA->vetor[i]->verticeOrigem == vetorA->vetor[k]->verticeOrigem){
                if ((vetorA->vetor[k]->verticeDestino < vetorA->vetor[i]->verticeDestino)){
                    Aresta* aux = vetorA->vetor[i];
                    vetorA->vetor[i] = vetorA->vetor[k];
                    vetorA->vetor[k] = aux;
                }
            } else if (vetorA->vetor[i]->verticeOrigem > vetorA->vetor[k]->verticeOrigem) {
                Aresta* aux = vetorA->vetor[i];
                vetorA->vetor[i] = vetorA->vetor[k];
                vetorA->vetor[k] = aux;
            }
        }
    }

    for(int j = 0; j < vetorA->contador2; j++ ){
        fprintf(arquivo, "(%d,%d) ", vetorA->vetor[j]->verticeOrigem, vetorA->vetor[j]->verticeDestino);
    }
    fprintf(arquivo, "\n");
}
