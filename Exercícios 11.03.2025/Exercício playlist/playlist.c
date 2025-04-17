#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playcj.h"

int main() {
    int op;
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
		    insere(playlist,node,song);
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
