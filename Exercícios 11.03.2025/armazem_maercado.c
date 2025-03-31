#include <stdio.h>
#include <string.h>

enum tipo {hortifruti,bebidas,mercearia,higiene,acougue,laticineos,frios,doces,padaria};

typedef struct {
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
	
	}while(op != 0)
}