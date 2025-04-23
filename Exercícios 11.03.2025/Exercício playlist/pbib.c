#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playcj.h"

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

void insere(desc *playlist, char *title, char *artist, char *lyrics, int *code, int *posicao) {
	nodo *node=cria_nodo(); 
	musica *song=cria_espaco();
	
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
			song.titulo = title;
			song.artista = artist;
			song.letra = lyrics;
			song.codigo = *code;
		}
	}
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
