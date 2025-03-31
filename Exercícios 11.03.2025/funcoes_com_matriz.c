#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum tipo {hortifruti=1,bebidas,mercearia,higiene,acougue,laticineos,frios,doces,padaria};

typedef struct {
	char nome[15];
	enum tipo setor;
	int quant;
	float valor;
} ITEM;

void menu();
int insere(int cont, ITEM *item);
void apresenta(char prod, ITEM *item);
void apresentaT(ITEM *item, int qt);

void buscaN(char bnome[15], ITEM *item, int qt);
void buscaS(int snome, ITEM *item, int qt);
int venda(char v[15], ITEM *item, int qt);

int main() {
	int cont,op,qt,snome;
	char bnome[15];

	do {
		printf("Informe a quantidade de produtos a serem cadastrados: ");
		scanf("%d", &cont);
		ITEM *item = (ITEM *) calloc(cont, sizeof(ITEM));
		menu();
		printf("Escolha uma opcao dentre as acima: ");
		scanf("%d",&op);
		switch(op) {
		case 1:
			qt = insere(cont, item);
			break;
		case 2:
			
			break;
		case 3:
			apresentaT(item, qt);
			break;
		case 4:

			break;
		case 5:
			printf("Informe o produto que deseja buscar: ");
			scanf(" %[^\n]", bnome);
			buscaN(bnome, item, qt);
			break;
		case 6:
			printf("1 - Hortifruti\n2 - Bebidas\n3 - Mercearia\n4 - Higiene\n5 - Acougue\n6 - Laticineos\n7 - Frios\n8 - Doces\n9 - Padaria\n\n");
			printf("Infoeme o setor do produto dentre as opcoes acima: ");
			scanf("%d", &snome);
			buscaS(snome, item, qt);
			break;
		case 7:
			printf("Informe o produto que foi vendido: ");
			scanf(" %[^\n]", v);
			qt = venda(v, item, qt);
			break;
		case 8:

			break;
		case 9:

			break;
		case 10:
			free(item);
			return 0;
		}
	} while(op != 10);
}

void menu() {
	printf("\n1 - Inserir produtos\n");
	printf("2 - Apresentar um produto\n");
	printf("3 - Apresentar todos os produtos");
	printf("4 - Balanco\n");
	printf("5 - Busca por nome\n");
	printf("6 - Busca por setor\n");
	printf("7 - Venda\n");
	printf("8 - Carregar arquivo\n");
	printf("9 - Gerar arquivo\n");
	printf("10 - Sair\n\n");
}

int insere(int cont, ITEM *item) {
	int set,qt;

	for(int i=0; i<cont; i++) {
		printf("\nDigite o nome do produto: ");
		scanf(" %[^\n]", item[i].nome);
		printf("1 - Hortifruti\n2 - Bebidas\n3 - Mercearia\n4 - Higiene\n5 - Acougue\n6 - Laticineos\n7 - Frios\n8 - Doces\n9 - Padaria\n\n");
		printf("O setor do produto dentre as opcoes acima: ");
		scanf("%d", &set);
		item[i].setor = set;
		printf("Digite a quantidade do produto: ");
		scanf("%d", &item[i].quant);
		printf("Digite o valor do produto: ");
		scanf("%f", &item[i].valor);
		qt++;
		return qt;
	}
}

void apresentaT(ITEM *item, int qt) {
	for(int i=0; i<qt; i++) {
			printf("%s\n", item[i].nome);
			printf("%d\n", item[i].setor);
			printf("%d\n", item[i].quant);
			printf("%2.f\n", item[i].valor);
	}
}

}

void buscaN(char bnome[15], ITEM *item, int qt) {
	for(int i=0; i<qt; i++) {
		if(strcmp(bnome, item[i].nome) == 0) {
			printf("%s\n", item[i].nome);
			printf("%d\n", item[i].setor);
			printf("%d\n", item[i].quant);
			printf("%2.f\n", item[i].valor);
		}
	}
}

void buscaS(int snome, ITEM *item, int qt) {
	for(int i=0; i<qt; i++) {
		if(snome == item[i].setor) {
			printf("%s\n", item[i].nome);
			printf("%d\n", item[i].setor);
			printf("%d\n", item[i].quant);
			printf("%2.f\n", item[i].valor);
		}
	}
}

int venda(char v[15], ITEM *item, int qt) {
	for(int i=0; i<qt; i++) {
		if(strcmp(v, item[i].nome) == 0) {
			qt--;
		}
	}
	return qt;
}
