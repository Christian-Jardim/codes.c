#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    
	int op;
	char title[256], artist[256], lyrics [256];
	
	do{
		op = menu();
		
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
			
			break;
		case 4:
			
			break;
		case 5:
			
			break;
		case 6:
			
			break;
		case 7:
			
			break;
		case 8:
			libera(playlist);
			printf("\nVoce saiu!");
			break;
		default:
			printf("\nOpcao invalida\n");
		}
	}while(op != 8);

	return 0;
}

int menu(){
	printf("\n1 - Criar uma playlist");
	printf("\n2 - Inserir uma musica");
	printf("\n3 - Remover uma musica");
	printf("\n4 - Encontrar uma musica");
	printf("\n5 - Mostrar toda a playlist");
	printf("\n6 - Tocar uma musica");
	printf("\n7 - Ver o tamanho da playlist");
	printf("\n8 - Sair");
	printf("\nEscolha uma das opcoes acima: ");
	scanf("%d",&op);
	return op;
}
