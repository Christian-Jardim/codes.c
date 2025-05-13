#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playlist_de.h"

void menu() {
	printf("\n1 - Criar uma playlist");
	printf("\n2 - Inserir uma musica");
	printf("\n3 - Remover uma musica");
	printf("\n4 - Encontrar uma musica");
	printf("\n5 - Mostrar toda a playlist");
	printf("\n6 - Tocar uma musica");
	printf("\n7 - Ver o tamanho da playlist");
	printf("\n8 - Sair");
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
	nNodo->ant=NULL;
	nNodo->info=NULL;
	return nNodo;
}

musica *cria_espaco(void) {
	musica *nMusica = (musica*)malloc(sizeof(musica));
	return nMusica;
}

void valida_code(desc *playlist, int *code) {
	int c;
	if(remover_encontra(playlist,*code,1,0,0) != NULL) {
		printf("Ja existe uma musica com este codigo, digite outro: ");
		scanf("%d",&c);
		*code = c;
	}
}

void valida_posicao(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code, int posicao) {
	if(playlist->primeiro_nodo == NULL || posicao == 0) {
		node->prox = playlist->primeiro_nodo;
		node->ant = NULL;
		playlist->primeiro_nodo = node;
		insere(playlist,node,song,title,artist,lyrics,code);
	} else {
		nodo *aux=playlist->primeiro_nodo;
		int indice=0;
		if(playlist->tamanho <= posicao) {
			while(aux->prox != NULL) {
				aux=aux->prox;
			}
			node->prox = aux->prox;
			node->ant = aux;
			aux->prox = node;
			insere(playlist,node,song,title,artist,lyrics,code);
		} else {
			while(aux != NULL) {
				if(indice == posicao) {
					node->prox = aux;
					node->ant = aux->ant;
					aux->ant->prox = node;
					aux->ant = node;
					insere(playlist,node,song,title,artist,lyrics,code);
					break;
				}
				aux = aux->prox;
				indice++;
			}
		}
	}
}

void insere(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code) {
	node->info = song;
	strcpy(song->titulo, title);
	strcpy(song->artista, artist);
	strcpy(song->letra, lyrics);
	song->codigo = code;
	playlist->tamanho++;
}
nodo *remover_encontra(desc *playlist, int code, int sinal1, int sinal2, int sinal3) {
	if (playlist->primeiro_nodo == NULL) {
		if (sinal3 == 0) {
			return NULL;
		} else {
			printf("\nPlaylist vazia!\n");
			return NULL;
		}
	} else {
		nodo *aux = playlist->primeiro_nodo;
		if (aux->info->codigo == code) {
			if (sinal1 == 0) {
				playlist->primeiro_nodo = aux->prox;
				if (aux->prox != NULL) {
					aux->prox->ant = NULL;
				}
				playlist->tamanho--;
				return aux;
			} else {
				return aux;
			}
		} else {
			while (aux != NULL) {
				if (aux->info->codigo == code) {
					if (sinal1 == 0) {
						aux->ant->prox = aux->prox;
						if (aux->prox != NULL) {
							aux->prox->ant = aux->ant;
						}
						playlist->tamanho--;
						return aux;
					} else {
						return aux;
					}
				}
				aux = aux->prox;
			}
			if (sinal2 != 0) {
				printf("\nNao ha musica com esse codigo na playlist!\n");
			}
			return NULL;
		}
	}
}

void mostra_playlist(desc *p) {
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
	}
	else {
		printf("\nTitulo da musica: %s",aux->info->titulo);
		printf("\nNome do artista: %s",aux->info->artista);
		printf("\nLetra da musica: %s\n",aux->info->letra);
		if(sinal != 1) {
			printf("\nCodigo da musica: %d",aux->info->codigo);
			printf("\nQuantidade de reproducoes: %d\n",aux->info->execucoes);
		}
	}
}

void toca(nodo *aux) {
	if(aux == NULL) {
		return;
	} else {
		mostra_musica(aux,1);
		aux->info->execucoes++;
	}
}

void ver_tamanho(desc *playlist) {
	printf("\nA playlist possui %d musica(s)!\n",playlist->tamanho);
}

void libera(desc *playlist) {
	nodo *aux = playlist->primeiro_nodo;
	nodo *anterior;
	while(aux->prox != NULL) {
		aux = aux->prox;
		free(aux->ant);
	}
	free(aux);
	playlist->primeiro_nodo = NULL;
	playlist->tamanho = 0;
}