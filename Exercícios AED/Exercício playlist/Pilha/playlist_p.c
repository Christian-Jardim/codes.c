#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playlist_p.h"

int main() {
	int op,posicao,code;
	char title[256], artist[256], lyrics [256];
	do {
		menu();
		printf("\nEscolha uma das opcoes acima: ");
		scanf("%d", &op);
		switch(op) {
		case 1:
			pilha *playlist=cria_pilha();
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
