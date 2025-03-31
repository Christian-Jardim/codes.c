#include <stdio.h>
#include <string.h>

enum tipo {hortifruti=1,bebidas,mercearia,higiene,acougue,laticineos,frios,doces,padaria};

typedef struct {
	char nome[15]
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
	ITEM *item = (ITEM*) calloc(sizeof(ITEM)); 
	printf("Escolha uma opcao: ");
	menu();
	scanf("%d",&op);
	switch(op) {
	case 1:
		insere(cont, item);
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

void insere(int cont, ITEM *item) {
	int set;
	printf("Digite o nome do produto: ");
	scanf("%s", p->nome);
	printf("1 - Hortifruti\n2 - Bebidas\n3 - Mercearia\n4 - Higiene\n5 - Acougue\n6 - Laticineos\n7 - Frios\n8 - Doces\n9 - Padaria")
	printf("O setor do produto dentre as opcoes acima: "); 
	scanf("%d", &set);
	item->setor = set; 
}