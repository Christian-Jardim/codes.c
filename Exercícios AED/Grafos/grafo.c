#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafo.h"

struct descritor_grafo* parser() {
	char arquivo[20];
	int total;

	printf("\n Nome do arquivo: ");
	scanf("%s", arquivo);
	FILE *file = fopen(arquivo,"r");
	if(file == NULL) {
		printf("\n Erro ao carregar o arquivo");
		return NULL;
	}
	fscanf(file,"%d",&total);
	printf(" =======================================================\n");
	printf(" ================ LEITURA GRAFO ========================\n");

	printf(" Total de nodos %d\n",total);
	struct descritor_grafo *grafo = NULL;
	grafo = inicializaGrafo(total);
	char linha[500];
	char caractere;
	int n;
	n=0;
	while((caractere =fgetc(file)) != EOF ) { //le o arquivo atC) o final caractere por caractere
		if(caractere != '\n') {
			linha[n]=caractere;
			n++;
		}
		else {
			linha[n]='\0';
			if(n > 0 ) //frase valida
			{
				printf(" Linha C): %s\n", linha);
				int partida = atoi(strtok(linha," "));
				printf("\n Partida strtok = %d\n",partida);
				int chegada = atoi(strtok(NULL," "));
				printf("\n Chegada strtok = %d\n",chegada);

				int peso = atoi(strtok(NULL," "));
				printf("\n Peso strtok = %d\n",peso);

				grafo = insereAresta(grafo,partida,chegada,peso);
			}
			n=0; //zera a frase para pegar proximas informaC'C5es
			linha[n]='\0';
		}
	}
	fclose(file);
	printf(" =====================================================\n");
	return grafo;
}

struct descritor_grafo * inicializaGrafo(int tamanho) {
	struct descritor_grafo * novografo = (struct descritor_grafo*) malloc(sizeof(struct descritor_grafo));
	novografo->max_vertices = tamanho;
	novografo->max_arestas = 0;
	novografo->nodos = NULL;
	int i;
	//cria a lista encadeada de nodos
	for(i=0; i<tamanho; i++) {
		struct nodo *novoNodo = criaVertice(i+1);
		if(novografo->nodos == NULL) {
			novografo->nodos = novoNodo;
		}
		else {
			struct nodo *temp = novografo->nodos;
			while(temp->prox!=NULL) {
				temp = temp->prox;
			}
			temp->prox = novoNodo;
		}
	}
	return novografo;
}

struct nodo * criaVertice(int chave) {
	struct nodo *novoVertice  = (struct nodo *) malloc(sizeof(struct nodo));
	novoVertice->chave 	= chave;
	novoVertice->prox 	= NULL;
	novoVertice->adjacencias=NULL;
	return novoVertice;
}

struct descritor_grafo * insereAresta(struct descritor_grafo *grafo, int chaveSaida, int chaveChegada, int peso) {
	struct nodo* nodoSaida = buscaVertice(grafo,chaveSaida);
	if(nodoSaida ==NULL) {
		printf(" Nodo buscado não existe\n");
		return grafo;
	}
	struct aresta* arestaNova = (struct aresta *) malloc(sizeof(struct aresta));
	arestaNova->peso = peso;
	arestaNova->partida = chaveSaida;
	arestaNova->chegada = chaveChegada;


	if(nodoSaida->adjacencias == NULL)
		nodoSaida->adjacencias=arestaNova;
	else {
		struct aresta *tempAdj = nodoSaida->adjacencias;
		while(tempAdj->prox != NULL) {
			tempAdj = tempAdj->prox;
		}
		tempAdj->prox = arestaNova;
	}
	return grafo;
}

struct nodo * buscaVertice(struct descritor_grafo *grafo, int chaveBusca) {
	struct nodo* temporaria = grafo->nodos;
	while(temporaria !=NULL) {
		if(temporaria->chave == chaveBusca)
			return temporaria;
		temporaria = temporaria->prox;
	}
	return NULL;
}

void imprimeGrafo(struct descritor_grafo *grafo) {
	struct nodo *nodoGrafo = grafo->nodos;
	printf("\n ========= GRAFO LISTA =============\n");
	while(nodoGrafo != NULL) {
		printf(" Nodo %d -",nodoGrafo->chave);
		struct aresta *adjacenciaNodo = nodoGrafo->adjacencias;
		while(adjacenciaNodo != NULL) {
			printf("[ ->%d (peso %d)] ",adjacenciaNodo->chegada, adjacenciaNodo->peso);
			adjacenciaNodo = adjacenciaNodo->prox;
		}
		printf("\n");
		nodoGrafo = nodoGrafo->prox;
	}
	printf("\n =====================\n");
}

//-----------------------------GRAFO COM MATRIZ ----------------------

struct descritor_grafo_matriz* parserMatriz(char *nomeArquivo) {
	FILE *file = fopen(nomeArquivo,"r");
	int total;
	fscanf(file,"%d",&total);
	printf("total de nodos %d\n",total);
	struct descritor_grafo_matriz *grafo = NULL;
	grafo = inicializaGrafoMatriz(total);
	char linha[500];
	char caractere;
	int n;
	n=0;
	while((caractere =fgetc(file)) != EOF ) { //le o arquivo atC) o final caractere por caractere
		if(caractere != '\n') {
			linha[n]=caractere;
			n++;
		}
		else {
			linha[n]='\0';
			if(n > 0 ) //frase valida
			{
				printf("linha eh: %s\n", linha);
				int partida = atoi(strtok(linha," "));
				printf("\n partida strtok= %d\n",partida);
				int chegada = atoi(strtok(NULL," "));
				printf("\n chegada strtok= %d\n",chegada);

				int peso = atoi(strtok(NULL," "));
				printf("\n peso strtok= %d\n",peso);

				grafo = insereArestaMatriz(grafo,partida,chegada,peso);
			}
			n=0; //zera a frase para pegar proximas informaC'C5es
			linha[n]='\0';
		}
	}
	fclose(file);
	return grafo;
}

struct descritor_grafo_matriz * inicializaGrafoMatriz(int tamanho) {
	struct descritor_grafo_matriz * novografo = (struct descritor_grafo_matriz*) malloc(sizeof(struct descritor_grafo_matriz));
	novografo->max_vertices = tamanho;
	novografo->max_arestas = 0;
	novografo->grafoMatriz = (int **) malloc(sizeof(int *)*(tamanho));
	int i;
	for(i=0; i<tamanho; i++)
		novografo->grafoMatriz[i] = (int*) malloc(sizeof(int)*(tamanho));
	return novografo;
}

struct descritor_grafo_matriz * insereArestaMatriz(struct descritor_grafo_matriz *novografo, int chaveSaida, int chaveChegada, int peso) {
	novografo->grafoMatriz[chaveSaida-1][chaveChegada-1]=peso;
	novografo->max_arestas++;
	return novografo;
}

void imprimeGrafoMatriz(struct descritor_grafo_matriz *grafoMatriz) {
	int i,j;
	printf("\n ========== GRAFO MATRIZ =============\n");
	for(i=0; i<grafoMatriz->max_vertices; i++) {
		for(j=0; j<grafoMatriz->max_vertices; j++) {
			printf("[%d-%d]=%d \t",i+1,j+1,grafoMatriz->grafoMatriz[i][j]);
		}
		printf("\n");
	}
	printf("\n =====================\n");
}

//----------------------------- STACK ----------------------

struct desc_stack *criaDescStack(void) {
	struct desc_stack *stack = (struct desc_stack*)malloc(sizeof(struct desc_stack));
	stack->top = NULL;
	stack->tamanho=0;
	return stack;
}

struct nodo_busca *criaNodoStack(struct aresta *arestaPilha) {
	struct nodo_busca *novo = (struct nodo_busca*)malloc(sizeof(struct nodo_busca));
	novo->aresta_busca = arestaPilha;
	novo->prox = NULL;
	return novo;
}

void push(struct desc_stack *stack, struct nodo_busca *novoElemento) {
	novoElemento->prox = stack->top;
	stack->top = novoElemento;
	stack->tamanho++;
}

struct nodo_busca *pop(struct desc_stack *stack) {
	struct nodo_busca *aux = stack->top;
	stack->top = stack->top->prox;
	stack->tamanho--;
	return aux;
}

int empty_stack(struct desc_stack *stack) {
	if(stack->top == NULL)
		return 1;
	return 0;
}

int length_stack(struct desc_stack *stack) {
	return stack->tamanho;
}

void makeNull_stack(struct desc_stack *stack) {
	while(empty_stack(stack) == 0) {
		free(pop(stack));
	}
}

struct nodo_busca* top(struct desc_stack *stack) {
	return stack->top;
}

void showStack(struct desc_stack *stack) {
	struct nodo_busca* topo = top(stack);
	printf("\n ========= Pilha de Arestas ==========\n");
	while(topo !=NULL) {
		printf("[ %d -> %d ] \n",topo->aresta_busca->partida,topo->aresta_busca->chegada);
		topo = topo->prox;
	}
	printf("\n ==============\n");
}

//----------------------------- QUEUE ----------------------

struct desc_queue *criaDescQueue(void) {
	struct desc_queue *queue = (struct desc_queue*)malloc(sizeof(struct desc_queue));
	queue->head = NULL;
	queue->tail = NULL;
	queue->tamanho=0;
	return queue;
}

struct nodo_busca* criaNodoQueue(struct aresta *arestaQueue) {
	struct nodo_busca *novo = (struct nodo_busca*)malloc(sizeof(struct nodo_busca));
	novo->aresta_busca = arestaQueue;
	novo->prox = NULL;
	return novo;
}

void enqueue(struct desc_queue *queue, struct nodo_busca *novoElemento) {
	queue->tail->prox = novoElemento;
	queue->tail = novoElemento;
	queue->tamanho++;
}

struct nodo_busca* dequeue(struct desc_queue *queue) {
	struct nodo_busca *aux = queue->head;
	queue->head = queue->head->prox;
	queue->tamanho--;
	return aux;
}

int empty_queue(struct desc_queue *queue) {
	if(queue->head == NULL)
		return 1;
	return 0;
}

int length_queue(struct desc_queue *queue) {
	return queue->tamanho;
}

void makeNull_queue(struct desc_queue *queue) {
	while(empty_queue(queue) == 0) {
		free(dequeue(queue));
	}
}

struct nodo_busca* head(struct desc_queue *queue) {
	return queue->head;
}

void showQueue(struct desc_queue *queue) {
	struct nodo_busca* cabeca = head(queue);
	printf("\n ========= Fila de Arestas ==========\n");
	while(cabeca != NULL) {
		printf("[ %d -> %d ] \n",cabeca->aresta_busca->partida,cabeca->aresta_busca->chegada);
		cabeca = cabeca->prox;
	}
	printf("\n ==============\n");
}

//----------------------------- BFS ----------------------

