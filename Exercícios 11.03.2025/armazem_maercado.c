#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum tipo {hortifruti=1,bebidas,mercearia,higiene,acougue,laticineos,frios,doces,padaria};

typedef struct {
	char nome[15];
	enum tipo setor;
	int quant;
	float valor;
}Item;

void menu();
Item* realocar(Item *item);
int insere(Item *item, int qt);


int main() {
    int cont,op,qt=0;
    
    printf("Insira quantos produtos serao cadastrados: ");
    scanf("%d", &cont);
    Item *item = (Item*)malloc(sizeof(Item) * cont);
    
    do{
        menu();
        printf("\nEscolha uma das opcoes acima: ");
        scanf("%d", &op);
        switch(op) {
            case 1:
                item = realocar(item);
                break;
            case 2:
                qt = insere(item,qt);
        }
    } while(op != 11);
    printf("%s",item[qt- 1].nome);
}

void menu() {
    printf("\n1 - Escolher quantos produtos a mais serao cadastrados");
    printf("\n2 - Inserir um produto");
    printf("\n3 - Escolher quantos elementos serao cadastrados");
    printf("\n3 - Escolher quantos elementos serao cadastrados");
    printf("\n4 - Escolher quantos elementos serao cadastrados");
    printf("\n5 - Escolher quantos elementos serao cadastrados");
    printf("\n6 - Escolher quantos elementos serao cadastrados");
    printf("\n7 - Escolher quantos elementos serao cadastrados");
    printf("\n8 - Escolher quantos elementos serao cadastrados");
    printf("\n9 - Escolher quantos elementos serao cadastrados");
    printf("\n10 - Escolher quantos elementos serao cadastrados");
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
    
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", item[qt].nome);
    
    qt++;
    return qt;
}
