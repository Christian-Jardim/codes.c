#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct musica musica;
typedef struct nodo nodo;
typedef struct desc desc;

struct musica {
	char titulo[256];
	char artista[256];
	char letra[256];
	int codigo;
	int execucoes;
};

struct nodo {
	nodo *prox;
	musica *info;
};

struct desc {
	nodo *primeiro_nodo;
	int tamanho;
};

void menu();
desc *cria_desc();
nodo *cria_nodo();
musica *cria_espaco();
void valida_posicao(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int *code, int *posicao);
void mostra_playlist(desc *p);
void insere(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int *code, int *posicao);
void mostra_playlist(desc *p);  

int main() {
	int op,posicao,code;
	char title[256], artist[256], lyrics [256];
	do {
		menu();
		printf("\nEscolha uma das opcoes acima: ");
		scanf("%d", &op);
		switch(op) {
		case 1:
			desc *playlist=cria_desc();
			break;
		case 2:
			nodo *node=cria_nodo(); 
			musica *song=cria_espaco(); 

			printf("Digite a posicao na qual quer inserir: ");
			scanf("%d",&posicao);
			printf("Digite o titulo da musica: ");
			scanf(" %[^\n]",title);
			setbuf(stdin,NULL);
			printf("Digite o nome do artista: ");
			scanf(" %[^\n]",artist);
			setbuf(stdin,NULL);
			printf("Digite a letra da musica: ");
			scanf(" %[^\n]",lyrics);
			setbuf(stdin,NULL);
			printf("Informe um codigo para identificar essa musica: ");
			scanf("%d",&code);
		valida_posicao(playlist,node,song,title,artist,lyrics,&code,&posicao);
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			mostra_playlist(playlist);
			break;
		case 6:
			printf("\nVoce saiu!");
			break;;
		default:
			printf("\nOpcao invalida");
		}
	} while(op != 6);
	return 0;
}

void menu() {
	printf("\n1 - Criar uma playlist");
	printf("\n2 - Inserir uma musica");
	printf("\n3 - Remover uma musica");
	printf("\n4 - Encontrar uma musica");
	printf("\n5 - Mostrar toda a playlist");
	printf("\n6 - Sair");
}

desc *cria_desc(void) {
	desc *nDesc = (desc *)malloc(sizeof(desc));
	nDesc->tamanho = 0;
	nDesc->primeiro_nodo=NULL;
	return nDesc;
}

nodo *cria_nodo(void) {
	nodo *nNodo=(nodo *)malloc(sizeof(nodo));
	nNodo->prox=NULL;
	nNodo->info=NULL;
	return nNodo;
}

musica *cria_espaco(void) {
	musica *nMusica = (musica*)malloc(sizeof(musica));
	return nMusica;
}

void valida_posicao(desc *playlist, char *title, char *artist, char *lyrics, int *code, int *posicao) {
	
	if(playlist->primeiro_nodo == NULL || posicao == 0) {
		node->prox=playlist->primeiro_nodo;
		node->info=song;
		playlist->primeiro_nodo=node;
		playlist->tamanho++;
	}
	else{
		nodo *aux=playlist->primeiro_nodo;
		int indice=0;
		if(playlist->tamanho < *posicao) {
			while(aux->prox != NULL) {
				aux=aux->prox;
			}
			aux->prox = node;
			node->info = song;
			strcpy(song->titulo, title);
			strcpy(song->artista, artist);
			strcpy(song->letra, lyrics);
			song->codigo = *code;
		}
	}
}

void insere(nodo *node, musica *song, char *title, char *artist, char *lyrics, int *code, int *posicao) {

}

void mostra_playlist(desc *p) {
	nodo *aux=p->primeiro_nodo;
	while(aux != NULL) {
		printf("\nTitulo da musica: %s",aux->info->titulo);
		printf("\nNome do artista: %s",aux->info->artista);
		printf("\nLetra da musica: %s",aux->info->letra);
		printf("\nCodigo da musica: %d",aux->info->codigo);
		printf("\nQuantidade de reproducoes: %d",aux->info->execucoes);
		aux=aux->prox;
	}
}
