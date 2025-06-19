#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main() {
	int op;

	desc_avl *arvore = NULL;

	do {
		menu();
		printf("\n Escolha uma das opcoes acima: ");
		scanf("%d",&op);

		switch(op) {
		case 1:
			arvore = cria_arvore();
			break;

		case 2:
			insere(arvore);
			break;

		case 3:
			check_empty(arvore,2);
			break;

		case 4:
			check_empty(arvore,0);
			break;

		case 5:
			check_empty(arvore,1);
			break;

		case 6:
			printf("\nVoce saiu!");
			return 0;
			break;

		default:
			printf("\n Opcao invalida!");
		}
	} while(op != 6);

	return 0;
}
