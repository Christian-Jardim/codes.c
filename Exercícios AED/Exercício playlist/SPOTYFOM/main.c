#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct musica musica;
typedef struct nodo nodo;
typedef struct desc desc;

struct musica {
	char titulo[256];
	char artista[256];
	char letra[256];
	int codigo;
	int execucoes;
};

struct nodo {
	nodo *prox;
	musica *info;
	nodo *ant;
};

struct desc {
	nodo *primeiro_nodo;
	int tamanho;
};

int menu1();
int menu2();
desc *carrega();
desc *cria_desc();
nodo *cria_nodo();
musica *cria_campo();


int main() {

	int op;
	char title[256], artist[256], lyrics [256];

	do {
		op = menu1();
		switch(op) {
		case 1:
			do {
				op = menu2();
				switch(op) {
				case 1:
					desc *acervo=carrega();
					break;
				case 0:
					printf("\n Voce saiu!");
					break;
				default:
					printf("\n Opcao invalida\n");
				}
			} while(op != 0);;
			break;
		case 0:
			printf("\n Voce saiu!");
			break;
		default:
			printf("\n Opcao invalida\n");
		}
	} while(op != 0);

	return 0;
}

int menu1() {
	int op;
	printf("\n 1 - Carregar arquivo de musicas");
	printf("\n 0 - Sair");
	printf("\n Escolha uma das opcoes acima: ");
	scanf("%d",&op);
	return op;
}

int menu2() {
	int op;
	printf("\n 1 - BUSCA");
	printf("\n 2 - PLAYLIST");
	printf("\n 3 - EXECUCAO");
	printf("\n 4 - IMPRESSAO");
	printf("\n 5 - RELATORIO");
	printf("\n 0 - SAIR");
	printf("\n Escolha uma das opcoes acima: ");
	scanf("%d",&op);
	return op;
}

desc *carrega(){
    int qt;
	char arquivo[20];
	printf("\n Nome do arquivo: ");
	scanf("%s", arquivo);
	
	FILE *arq = fopen(arquivo, "r");
	if(arq == NULL) {
		printf("\n Erro ao carregar o arquivo");
	}else{
		fscanf(arq,"%d\n",&qt);
		for(int i=0; i<qt; i++) {
			fscanf(arq,"%[^\n]s\n",item[i].nome);
			fscanf(arq,"%d\n",&s);
			item[i].setor = s;
			fscanf(arq,"%d\n",&item[i].quant);
			fscanf(arq,"%f\n",&item[i].valor);
		}
		printf("\n Arquivo carregado: %s\n",arquivo);
	}
	fclose(arq);
}


desc *cria_desc() {
	desc *nDesc = (desc *)malloc(sizeof(desc));
	nDesc->tamanho = 0;
	nDesc->primeiro_nodo=NULL;
	return nDesc;
}

nodo *cria_nodo() {
	nodo *nNodo=(nodo *)malloc(sizeof(nodo));
	nNodo->prox=NULL;
	nNodo->ant=NULL;
	nNodo->info=NULL;
	return nNodo;
}

musica *cria_campo() {
	musica *nMusica = (musica*)malloc(sizeof(musica));
	return nMusica;
}
