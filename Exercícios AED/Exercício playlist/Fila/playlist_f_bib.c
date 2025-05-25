#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "playlist_f.h"

void menu() {
	printf("\n\n1 - Criar uma playlist");
	printf("\n2 - Esvaziar a playlist");
	printf("\n3 - Verificar se a playlist esta vazia");
	printf("\n4 - Verificar o tamanho da playlist");
	printf("\n5 - Inserir uma musica");
	printf("\n6 - Remover uma musica");
	printf("\n7 - Encontrar uma musica");
	printf("\n8 - Tocar uma musica");
	printf("\n9 - Mostrar toda a playlist");
	printf("\n10 - Sair");
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

void empty(fila *playlist) {
	if(playlist == NULL) {
		printf("\nCrie uma playlist primeiro!");
	} else {
		if(check_empty(playlist)) {
			printf("\nA playlist esta vazia!");
		} else {
			printf("\nA playlist nao esta vazia!");
		}
	}
}

bool check_empty(fila *playlist) {
	return playlist->primeiro_nodo == playlist->ultimo_nodo;
}

void tamanho(fila *playlist) {
	if(playlist == NULL) {
		printf("\nCrie uma playlist primeiro!");
	} else {
		printf("\nO tamanho da playlist e: %d",playlist->tamanho);
	}
}

void insere(fila *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code) {
	if(playlist == NULL) {
		printf("\nCrie uma playlist primeiro!");
	} else {
		node->info = song;
		strcpy(song->titulo, title);
		strcpy(song->artista, artist);
		strcpy(song->letra, lyrics);
		song->codigo = code;
		playlist->tamanho++;

		if(playlist->primeiro_nodo == NULL) {
			playlist->primeiro_nodo = node;
		} else {
			if(playlist->ultimo_nodo == NULL) {
				node->prox = NULL;
				playlist->ultimo_nodo = node;
				playlist->primeiro_nodo->prox = node;
			} else {
				playlist->ultimo_nodo->prox = node;
				playlist->ultimo_nodo = node;
			}
		}
	}
}

nodo *encontra(fila *playlist, int code) {
	if(playlist == NULL) {
		printf("\nCrie uma playlist primeiro!");
		return NULL;
	} else {
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
			printf("\nNao ha musica com este codigo na playlist!\n");
			return NULL;
		}
	}
}

nodo *remover(fila *playlist) {
	if(playlist == NULL) {
		printf("\nCrie uma playlist primeiro!");
	} else {
		if (playlist->primeiro_nodo == NULL) {
			printf("\nPlaylis vazia!\n");
			return NULL;
		} else {
			nodo *aux = playlist->primeiro_nodo;
			playlist->primeiro_nodo = aux->prox;
			playlist->tamanho--;
			free(aux);
			printf("\nMusica removida!");
		}
	}
}
void mostra_playlist(fila *p) {
	if(p == NULL) {
		printf("\nCrie uma playlist primeiro!");
	} else {
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
}

void mostra_musica(nodo *aux, int sinal) {
	if(aux == NULL) {
		return;
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
	if(playlist == NULL) {
		printf("\nCrie uma playlist primeiro!");
	} else {
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
		
		printf("\nPlaylist deletada!");
	}
}
