#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum tipo {hortifruti=1,bebidas,mercearia,higiene,acougue,laticineos,frios,doces,padaria};

typedef struct {
	char nome[15];
	enum tipo setor;
	int quant;
	float valor;
}ITEM;

void menu();
void insere(int cont, ITEM *item);

int main() {
	int cont,op;

	do{
	printf("Informe a quantidade de produtos a serem cadastrados: ");
	scanf("%d", &cont);
	ITEM *item = (ITEM*) calloc(cont,sizeof(ITEM)); 
	menu();
	printf("Escolha uma opcao dente as acima: ");
	scanf("%d",&op);
	switch(op) {
	case 1:
		insere(cont, item);
		break;
	case 2:
		
		break;
	case 3:
		insere(cont, item);
		break;
	case 4:
		insere(cont, item);
		break;
	case 5:
		insere(cont, item);
		break;
	case 6:
		insere(cont, item);
		break;
	case 7:
		insere(cont, item);
		break;
	case 8:
		insere(cont, item);
		break;
	case 9:
		insere(cont, item);
		break;
	case 10:
		insere(cont, item);
		break;
	}
	}while(op != 10);
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

void insere(int cont, ITEM *item) {
	int set,qt;
	
	for(int i=0; i<cont; i++){
	    printf("Digite o nome do produto: ");
	    scanf("%s", item->nome);
	    printf("1 - Hortifruti\n2 - Bebidas\n3 - Mercearia\n4 - Higiene\n5 - Acougue\n6 - Laticineos\n7 - Frios\n8 - Doces\n9 - Padaria\n\n");
	    printf("O setor do produto dentre as opcoes acima: "); 
	    scanf("%d", &set);
	    item->setor = set;
	    printf("Digite a quantidade do produto: ");
	    scanf("%d", &item->quant);
	    printf("Digite o valor do produto: ");
	    scanf("%f", &item->valor);
	    qt++;
	}
}
