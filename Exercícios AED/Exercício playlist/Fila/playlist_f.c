#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "playlist_f.h"

int main() {
	int op,posicao,code;
	char title[256], artist[256], lyrics [256];
	do {
		menu();
		printf("\nEscolha uma das opcoes acima: ");
		scanf("%d", &op);
		switch(op) {
		case 1:
			fila *playlist = cria_fila();
			break;
		case 2:
			libera(playlist);
			printf("\nPlaylist esvaziada!");
			break;
		case 3:
			empty(playlist);
			break;
		case 4:
			printf("\nO tamanho da playlist e: %d",tamanho(playlist));
			break;
		case 5:
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
		case 6:
			remover(playlist);
			break;
		case 7:
			printf("\nDigite o codigo da musica que quer encontrar: ");
			scanf("%d",&code);

			mostra_musica(encontra(playlist,code),0);
			break;
		case 8:
			printf("\nDigite o codigo da musica que quer tocar: ");
			scanf("%d",&code);

			mostra_musica(encontra(playlist,code),1);
			break;
		case 9:
			mostra_playlist(playlist);
			break;
		case 10:
			libera(playlist);

			printf("\nVoce saiu!");
			break;
		default:
			printf("\nOpcao invalida\n");
		}
	} while(op != 10);
	return 0;
}