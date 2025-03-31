#include <stdio.h>
#include <string.h>

enum tipo {hortifruti,bebidas,mercearia,higiene,acougue,laticineos,frios,doces,padaria};

typedef struct produto{
	char nome[15]
	enum tipo setor;
	int quant;
	float valor;
}ITEM;

void menu();
void insere();

int main() {
	int cont,op;
	ITEM item;

	do{
	printf("Informe a quantidade de produtos a serem cadastrados: ");
	scanf("%d", &cont);
	printf("Escolha uma opcao: ");
	menu();
	scanf("%d",&op);
	switch(op) {
	case 1:
		insere();
	}
	}while(op != 10)
}

void menu() {
	printf("1 - Inserir produtos");
	printf("2 - Apresentar um produto");
	printf("3 - Apresentar todos os produtos");
	printf("4 - Balanco");
	printf("5 - Busca por nome");
	printf("6 - Busca por setor");
	printf("7 - Venda");
	printf("8 - Carregar arquivo");
	printf("9 - Gerar arquivo");
	printf("10 - Sair");
}

void insere() {

}