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

void insere(desc *descritor, nodo *nodo, musica *musica){
    nodo->prox=descritor->primeiro_nodo;
    nodo->info=musica;
    descritor->primeiro_nodo=nodo;
    descritor->tamanho++;
    
    printf("Digite o titulo da musica: ");
    scanf(" %[^\n]",nodo->info->titulo);
    setbuf(stdin,NULL);
    printf("Digite o nome do artista: ");
    scanf(" %[^\n]",nodo->info->artista);
    setbuf(stdin,NULL);
    printf("Digite a letra da musica: ");
    scanf(" %[^\n]",nodo->info->letra);
    setbuf(stdin,NULL);
    printf("Informe um codigo para identificar essa musica: ");
    scanf("%d",&nodo->info->codigo);
}

void mostra_playlist(desc *p) {
    nodo *aux=p->primeiro_nodo;
    do {
       printf("\nTitulo da musica: %s",aux->info->titulo);
       printf("\nNome do artista: %s",aux->info->artista);
       printf("\nLetra da musica: %s",aux->info->letra);
       printf("\nCodigo da musica: %d",aux->info->codigo);
       printf("\nQuantidade de reproducoes: %d",aux->info->execucoes);
    } while(aux->prox!=NULL);
}
