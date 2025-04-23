#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playcj.h"

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
			insere(playlist,title,artist,lyrics,&code,&posicao);
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
