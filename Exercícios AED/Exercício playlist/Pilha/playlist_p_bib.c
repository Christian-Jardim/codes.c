#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playlist_p.h"

void menu() {
	printf("\n1 - Criar uma playlist");
	printf("\n2 - Inserir uma musica");
	printf("\n3 - Remover uma musica");
	printf("\n4 - Encontrar uma musica");
	printf("\n5 - Mostrar toda a playlist");
	printf("\n6 - Tocar uma musica");
	printf("\n7 - Sair");
}

pilha *cria_pilha(void) {
	pilha *nPilha = (pilha *)malloc(sizeof(pilha));
	nPilha->tamanho = 0;
	nPilha->primeiro_nodo=NULL;
	return nPilha;
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

void insere(pilha *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code) {
	node->prox = playlist->primeiro_nodo;
	playlist->primeiro_nodo = node;
	node->info = song;
	strcpy(song->titulo, title);
	strcpy(song->artista, artist);
	strcpy(song->letra, lyrics);
	song->codigo = code;
	playlist->tamanho++;
}

nodo *encontra(pilha *playlist, int code) {
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

nodo *remover(pilha *playlist) {
	nodo *aux = playlist->primeiro_nodo;
	playlist->primeiro_nodo = aux->prox;
	playlist->tamanho--;
	printf("\nMusica removida: ");
	return aux;
}
void mostra_playlist(pilha *p) {
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

void libera(pilha *playlist) {
	nodo *aux = playlist->primeiro_nodo;
	nodo *anterior;
	while(aux != NULL) {
		anterior = aux;
		aux = aux->prox;
		free(anterior);
	}
	free(aux);
	playlist->primeiro_nodo = NULL;
	playlist->tamanho = 0;
}
