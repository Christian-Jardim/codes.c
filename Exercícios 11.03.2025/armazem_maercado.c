#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum tipo {hortifruti=1,bebidas,mercearia,higiene,acougue,laticineos,frios,doces,padaria};

typedef struct {
	char nome[15];
	enum tipo setor;
	int quant;
	float valor;
} Item;

void menu();
Item* realocar(Item *item);
int insere(Item *item, int qt);
void apresenta(Item *item, int qt);
void apresenta1(Item *item, int qt);
void apresentaT(Item *item, int qt);
void buscaN(Item *item, int qt);


int main() {
	int cont,op,qt=0;

	printf("Insira quantos produtos serao cadastrados: ");
	scanf("%d", &cont);
	Item *item = (Item*)malloc(sizeof(Item) * cont);

	do {
		menu();
		printf("\nEscolha uma das opcoes acima: ");
		scanf("%d", &op);
		switch(op) {
		case 1:
			item = realocar(item);
			break;
		case 2:
			qt = insere(item,qt);
			break;
		case 3:
			apresenta1(item,qt);
			break;
		case 4:
			apresentaT(item,qt);
			break;
		case 5:

			break;
		case 6:
			buscaN(item,qt);
			break;
		case 11:
			free(item);
			return 0;
		}
	} while(op != 11);
}

void menu() {
	printf("\n1 - Escolher quantos produtos a mais serao cadastrados");
	printf("\n2 - Inserir um produto");
	printf("\n3 - Apresentar um produto");
	printf("\n4 - Apresentar todos os produtos");
	printf("\n5 - Balanco");
	printf("\n6 - Buscar por nome");
	printf("\n7 - Buscar por setor");
	printf("\n8 - Venda");
	printf("\n9 - Carregar por arquivo");
	printf("\n10 - Gerar arquivo");
	printf("\n11 - Sair");
}

Item *realocar(Item *item) {
	int mp;

	printf("\nInsira quantos elementos a mais serao cadastrados: ");
	scanf("%d", &mp);

	item = (Item*)realloc(item,sizeof(Item*) * mp);

	return item;
}

int insere(Item *item, int qt) {
	int s;

	printf("\nDigite o nome do produto: ");
	scanf(" %[^\n]", item[qt].nome);
	printf("\nO sua quantidade: ");
	scanf("%d", &item[qt].quant);
	printf("\nO seu valor: ");
    scanf("%f", &item[qt].valor);
	printf("\nO seu setor: ");
	scanf("%d", &s);
	item[qt].setor = s;

	qt++;
	return qt;
}

void apresenta(Item *item, int i) {
	printf("\n%s", item[i].nome);
    printf("\n%d", item[i].quant);
    printf("\n%.2f", item[i].valor);
	printf("\n%d", item[i].setor);
	switch(item[i].setor) {
	case 1:
		printf("\nhortifruti");
		break;
	case 2:
		printf("\nbebidas");
		break;
	case 3:
		printf("\nmercearia");
		break;
	case 4:
		printf("\nhigiene");
		break;
	case 5:
		printf("\nacougue");
		break;
	case 6:
		printf("\nlaticineos");
		break;
	case 7:
		printf("\nfrios");
		break;
	case 8:
		printf("\ndoces");
		break;
	case 9:
		printf("\npadaria");
		break;
	}
}

void apresenta1(Item *item, int qt) {
	char p[15];

	printf("\nDigite o nome do produto: ");
	scanf(" %[^\n]", p);

	for(int i=0; i<qt; i++) {
		if(strcmp(p, item[i].nome) == 0) {
			apresenta(item, i);
		}
	}
}

void apresentaT(Item *item, int qt) {

	for(int i=0; i<qt; i++) {
		apresenta(item, i);
	}
}

void buscaN(Item *item, int qt) {
	char p[15];

	printf("\nDigite o nome do produto: ");
	scanf(" %[^\n]", p);

	for(int i=0; i<qt; i++) {
		if(strcmp(p, item[i].nome) == 0) {
			apresenta(item,i);
		}
	}
}
