#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "playlist.h"

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
			nodo *node=cria_nodo();
			musica *song=cria_espaco();
			printf("\nDigite a posicao na qual quer inserir: ");
			scanf("%d",&posicao);
			printf("Digite o titulo da musica: ");
			scanf(" %[^\n]s",title);
			printf("Digite o nome do artista: ");
			scanf(" %[^\n]s",artist);
			printf("Digite a letra da musica: ");
			scanf(" %[^\n]s",lyrics);
			printf("Informe um codigo para identificar essa musica: ");
			scanf("%d",&code);
			valida_code(playlist,&code);
			valida_posicao(playlist,node,song,title,artist,lyrics,code,posicao);
			break;
		case 3:
			printf("\nDigite o codigo da musica que quer remover: ");
			scanf("%d",&code);
			nodo *removido = remover_encontra(playlist,code,0,1,1);
			break;
		case 4:
			printf("\nDigite o codigo da musica que quer encontrar: ");
			scanf("%d",&code);
			mostra_musica(remover_encontra(playlist,code,1,1,1),0);
			break;
		case 5:
			mostra_playlist(playlist);
			break;
		case 6:
			printf("\nDigite o codigo da musica que quer tocar: ");
			scanf("%d",&code);
			toca(remover_encontra(playlist,code,1,1,1));
			break;
		case 7:
			ver_tamanho(playlist);
			break;
		case 8:
			libera(playlist);
			printf("\nVoce saiu!");
			break;
		default:
			printf("\nOpcao invalida\n");
		}
	} while(op != 8);
	return 0;
}
