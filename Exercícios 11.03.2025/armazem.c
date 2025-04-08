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
Item *realocar(Item *item);
int insere(Item *item, int qt, int cont);
void apresenta(Item *item, int qt);
void apresenta1(Item *item, int qt);
void apresentaT(Item *item, int qt);
float balanco(int i, int qt, Item *item, int qp);
void buscaN(Item *item, int qt);
void buscaS(Item *item, int qt);
void venda(Item *item, int qt);
int carrega(Item *item);
int gera(int qt, Item *item);
int cola(int qt, Item *item);

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
			cont++;
			break;
		case 2:
			qt = insere(item,qt,cont);
			break;
		case 3:
			apresenta1(item,qt);
			break;
		case 4:
			apresentaT(item,qt);
			break;
		case 5:
			balanco(0,qt,item,0);
			break;
		case 6:
			buscaN(item,qt);
			break;
		case 7:
			buscaS(item,qt);
			break;
		case 8:
			venda(item,qt);
			break;
		case 9:
			qt = carrega(item);
			break;
		case 10:
			gera(qt,item);
			return 0;
			break;
		case 11:
		    cola(qt,item);
			break;
		case 12:
		    free(item);
			break;
		default:
			printf("\nOpcao invalida");
		}
	} while(op != 12);
	return 0;
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
	mp+=1;
	Item *itens = (Item*)realloc(item,sizeof(Item) * mp);
	return itens;
}

int insere(Item *item, int qt, int cont) {
	int s;

	if(qt == cont || qt > cont) {
		printf("\nEspaco insuficiente, aloque mais espaco.\n");
		return 1;
	}
	else {
		printf("\nDigite o nome do produto: ");
		scanf(" %[^\n]", item[qt].nome);
		printf("\nO sua quantidade: ");
		scanf("%d", &item[qt].quant);
		printf("\nO seu valor: ");
		scanf("%f", &item[qt].valor);
		printf("\n1-hortifruti; 2-bebidas; 3-mercearia; 4-higiene; 5-acougue; 6-laticineos; 7-frios; 8-doces;9-padaria");
		printf("\nO seu setor, dentre as opcoes acima: ");
		scanf("%d", &s);
		item[qt].setor = s;
		qt++;
		return qt;
	}
}

void apresenta(Item *item, int i) {
	printf("\nProduto: %s", item[i].nome);
	printf("\nQuantidade: %d", item[i].quant);
	printf("\nValor: %.2f", item[i].valor);
	printf("\nSetor: ");
	switch(item[i].setor) {
	case 1:
		printf("hortifruti\n");
		break;
	case 2:
		printf("bebidas\n");
		break;
	case 3:
		printf("mercearia\n");
		break;
	case 4:
		printf("higiene\n");
		break;
	case 5:
		printf("acougue\n");
		break;
	case 6:
		printf("laticineos\n");
		break;
	case 7:
		printf("frios\n");
		break;
	case 8:
		printf("doces\n");
		break;
	case 9:
		printf("padaria\n");
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

float balanco(int i, int qt, Item *item, int qp) {

	if(i<qt) {
		qp+=item[i].quant*item[i].valor;
		i++;
		balanco(i, qt, item, qp);
	}
	else {
		printf("\n%d",qp);
		return qp;
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

void buscaS(Item *item, int qt) {
	int s;

	printf("\n\n1-hortifruti; 2-bebidas; 3-mercearia; 4-higiene; 5-acougue; 6-laticineos; 7-frios; 8-doces; 9-padaria");
	printf("\nO setor do produto, dentre as opcoes acima: ");
	scanf("%d", &s);

	for(int i=0; i<qt; i++) {
		if(item[i].setor == s) {
			apresenta(item,i);
		}
	}
}

void venda(Item *item, int qt) {
	char p[15];
	int qv;

	printf("\nDigite o nome do produto que foi vendido: ");
	scanf(" %[^\n]", p);
	printf("\nA quantidade que foi vendida: ");
	scanf("%d", &qv);

	for(int i=0; i<qt; i++) {
		if(strcmp(p, item[i].nome) == 0) {
			item[i].quant = item[i].quant - qv;
		}
	}
}

int carrega(Item *item) {
	int qt,s;
	FILE *arq = fopen("armazem_aed.txt", "r");
	if(arq == NULL) {
		printf("Erro ao carregar o arquivo");
		return 1;
	}
	else {
		fscanf(arq,"%d\n",&qt);
		for(int i=0; i<qt; i++) {
			fscanf(arq,"%s\n",item[i].nome);
			fscanf(arq,"%d\n",&s);
			item[i].setor = s;
			fscanf(arq,"%d\n",&item[i].quant);
			fscanf(arq,"%f\n",&item[i].valor);
		}
	}
	fclose(arq);
	return qt;
}

int gera(int qt, Item *item) {
	FILE *arq = fopen("armazem_aed.txt", "w");
	if(arq == NULL) {
		printf("Erro ao gerar o arquivo");
		return 1;
	}
	else {
		fprintf(arq,"%d\n",qt);
		for(int i=0; i<qt; i++) {
			fprintf(arq,"%s\n",item[i].nome);
			fprintf(arq,"%d\n",item[i].setor);
			fprintf(arq,"%d\n",item[i].quant);
			fprintf(arq,"%.2f\n",item[i].valor);
		}
	}
	fclose(arq);
}

int cola(int qt, Item *item) {
	FILE *arq = fopen("armazem_aed.txt", "a");
	if(arq == NULL) {
		printf("Erro ao abrir o arquivo");
		return 1;
	}
	else {
		fprintf(arq,"%d\n",qt);
		for(int i=0; i<qt; i++) {
			fprintf(arq,"%s\n",item[i].nome);
			fprintf(arq,"%d\n",item[i].setor);
			fprintf(arq,"%d\n",item[i].quant);
			fprintf(arq,"%.2f\n",item[i].valor);
		}
	}
	fclose(arq);
}
