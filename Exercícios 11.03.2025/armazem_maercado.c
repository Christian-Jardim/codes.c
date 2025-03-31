#include <stdio.h>
#include <string.h>

enum tipo {hortifruti,bebidas,mercearia,higiene,acougue,laticineos,frios,doces,padaria};

typedef struct produto{
	char nome[15]
	enum tipo setor;
	int quant;
	float valor;
}ITEM;

int main() {
	int cont,op;
	ITEM item

	do{
	printf("Informe a quantidade de produtos a serem cadastrados: ");
	scanf("%d", &cont);
	printf("Escolha uma opcao: ");
	menu
	scanf("%d",&op);
	switch(op) {
	case 1:
	}
	}while(op != 0)
}