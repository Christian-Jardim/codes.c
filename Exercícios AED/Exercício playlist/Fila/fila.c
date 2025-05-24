#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct musica musica;
typedef struct nodo nodo;
typedef struct fila fila;

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

struct fila {
	nodo *primeiro_nodo;
	nodo *ultimo_nodo;
	int tamanho;
};

void menu();
fila *cria_fila();
nodo *cria_nodo();
musica *cria_espaco();
void insere(fila *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code);
nodo *remover(fila *playlist);
nodo *encontra(fila *playlist, int code);
void mostra_musica(nodo *aux, int sinal);
void mostra_playlist(fila *p);
void libera(fila *playlist);

int main() {
	int op,posicao,code;
	char title[256], artist[256], lyrics [256];
	do {
		menu();
		printf("\nEscolha uma das opcoes acima: ");
		scanf("%d", &op);
		switch(op) {
		case 1:
			fila *playlist=cria_fila();
			break;
		case 2:
			nodo *node=cria_nodo();
			musica *song=cria_espaco();

			printf("\nDigite o titulo da musica: ");
			scanf(" %[^\n]s",title);
			printf("Digite o nome do artista: ");
			scanf(" %[^\n]s",artist);
			printf("Digite a letra da musica: ");
			scanf(" %[^\n]s",lyrics);
			printf("Informe um codigo para identificar essa musica: ");
			scanf("%d",&code);
			insere(playlist,node,song,title,artist,lyrics,code);
			break;
		case 3:
			mostra_musica(remover(playlist),0);
			break;
		case 4:
			printf("\nDigite o codigo da musica que quer encontrar: ");
			scanf("%d",&code);
			mostra_musica(encontra(playlist,code),0);
			break;
		case 5:
			mostra_playlist(playlist);
			break;
		case 6:
			printf("\nDigite o codigo da musica que quer tocar: ");
			scanf("%d",&code);
			mostra_musica(encontra(playlist,code),1);
			break;
		case 7:
			libera(playlist);
			printf("\nVoce saiu!");
			break;
		default:
			printf("\nOpcao invalida\n");
		}
	} while(op != 7);
	return 0;
}

void menu() {
	printf("\n1 - Criar uma playlist");
	printf("\n2 - Inserir uma musica");
	printf("\n3 - Remover uma musica");
	printf("\n4 - Encontrar uma musica");
	printf("\n5 - Mostrar toda a playlist");
	printf("\n6 - Tocar uma musica");
	printf("\n7 - Sair");
}

fila *cria_fila(void) {
	fila *nFila = (fila *)malloc(sizeof(fila));
	nFila->tamanho = 0;
	nFila->primeiro_nodo = NULL;
	nFila->ultimo_nodo = NULL;
	return nFila;
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

void insere(fila *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code) {
	node->prox = playlist->primeiro_nodo;
	playlist->primeiro_nodo = node;
	node->info = song;
	strcpy(song->titulo, title);
	strcpy(song->artista, artist);
	strcpy(song->letra, lyrics);
	song->codigo = code;
	playlist->tamanho++;
}

nodo *encontra(fila *playlist, int code) {
	if (playlist->primeiro_nodo == NULL) {
		printf("\nPlaylis vazia!\n");
		return NULL;
	} else {
		nodo *aux = playlist->primeiro_nodo;
		while (aux != NULL) {
			if (aux->info->codigo == code) {
				return aux;
			}
			aux = aux->prox;
		}
		return NULL;
	}
}

nodo *remover(fila *playlist) {
	nodo *aux = playlist->primeiro_nodo;
	playlist->primeiro_nodo = aux->prox;
	playlist->tamanho--;
	printf("\nMusica removida: ");
	return aux;
}
void mostra_playlist(fila *p) {
	nodo *aux=p->primeiro_nodo;
	if(aux == NULL) {
		printf("\nPlaylist vazia!\n");
	} else {
		while(aux != NULL) {
			mostra_musica(aux,0);
			aux=aux->prox;
		}
	}
}

void mostra_musica(nodo *aux, int sinal) {
	if(aux == NULL) {
		printf("Nao ha musica com este codigo na playlist!\n");
	} else {
		printf("\nTitulo da musica: %s",aux->info->titulo);
		printf("\nNome do artista: %s",aux->info->artista);
		printf("\nLetra da musica: %s\n",aux->info->letra);
		if(sinal == 0) {
			printf("Codigo da musica: %d",aux->info->codigo);
			printf("\nQuantidade de reproducoes: %d\n",aux->info->execucoes);
		}
	}
}

void libera(fila *playlist) {
	nodo *aux = playlist->primeiro_nodo;
	nodo *anterior;
	while(aux != playlist->ultimo_nodo) {
		anterior = aux;
		aux = aux->prox;
		free(anterior);
	}
	free(playlist->ultimo_nodo);
	playlist->primeiro_nodo = NULL;
	playlist->ultimo_nodo = NULL;
	playlist->tamanho = 0;
}
