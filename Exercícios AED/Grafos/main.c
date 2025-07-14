#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "grafo.h"

int main() {
    
    setlocale(LC_ALL,"");
	int opcao,chave_busca;
	struct descritor_grafo *grafo = NULL;
	struct descritor_grafo_matriz *grafoMatriz = NULL;
	struct desc_stack *minhaPilha = NULL;
	opcao = -1;
	while(opcao != 0) {
		printf(" Escolha sua opção:\n");
		printf(" 1 - Carrega grafo lista\n 2 - Busca adjacências\n 3 - Imprime grafo lista\n 4 - Pilha de arestas\n 5 - Carrega grafo Matriz\n 6 - Imprime grafo matriz\n 7 - Busca BFS\n 0 - SAIR\n");
		setbuf(stdin,NULL);
		scanf("%d",&opcao);
		switch(opcao) {
		case 1:
			grafo = parser();
			if(grafo!=NULL)
				printf(" Grafo lista inicializado com sucesso\n");
			break;
		case 2:
			printf(" Digite a chave a ser buscada no grafo lista: \n");
			setbuf(stdin,NULL);
			scanf("%d",&chave_busca);
			struct nodo* temp = buscaVertice(grafo,chave_busca);
			if(temp == NULL)
				printf(" Não encontrou o nodo\n");
			else
				printf(" Encontrou o nodo\n");
			break;
		case 3:
			imprimeGrafo(grafo);
			break;
		case 4:
			if(grafo ==NULL) {
				printf("grafo lista inicializado com sucesso\n");
				break;
			}
			minhaPilha = criaDescStack();

			//grafo pronto vai acessar as arestas para criar no da pilha e inserir
			struct aresta *arestaGrafo=NULL;
			//recebe o primeiro da lista de vertices
			struct nodo *auxVertice = grafo->nodos;

			while(auxVertice != NULL) {

				//percorre as adjacencias do auxvertice colocando na pilha
				arestaGrafo = auxVertice->adjacencias;
				while(arestaGrafo != NULL) {
					//crio nC3 pilha para inserir na pilha
					struct nodopilha *noPilha = criaNodoStack(arestaGrafo);
					//insere na pilha
					push(minhaPilha,noPilha);
					arestaGrafo = arestaGrafo->prox;
				}
				auxVertice = auxVertice->prox;
			}

			//mostra pilha completa
			showStack(minhaPilha);

			break;
		case 5:
			grafoMatriz = parserMatriz("grafo.txt");
			if(grafoMatriz !=NULL)
				printf("grafo inicializado com sucesso\n");
			break;
		case 6:
			imprimeGrafoMatriz(grafoMatriz);
			break;
		case 7:
		printf("Chave para começar a busca: ");
		scanf("%d",&chave_busca);
			bfs(grafo, chave_busca);
			break;
		case 0:
			exit(-1);
		}
	}
	return 0;
}
