#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;
typedef struct desc_avl desc_avl;

struct nodo {
	int chave;
	nodo *pai;
	nodo *esq;
	nodo *dir;
};

struct desc_avl {
	nodo *raiz;
	int tamanho;
};

void menu();
desc_avl *cria_arvore();
nodo *cria_nodo();
void insere(desc_avl *arvore,nodo *sub_arvore,int chave);


int main()
{
	int op, chave;

	desc_avl *arvore = NULL;
	nodo *sub_arvore = NULL;

	while(op != 5) {
	    
	    menu();
	    printf("\nEscolha uma das opcoes acima: ");
	    scanf("%d",&op);
	    
		switch(op) {
		case 1:
            arvore = cria_arvore();
			break;
		
		case 2:
			sub_arvore = cria_nodo();
			
			printf("Digite o valor da chave: ");
			scanf("%d",&chave);
			
			insere(sub_arvore,chave);
			break;
			
		case 6:
			return 0;
			break;
			
		default:
			printf("\nOpcao invalida!");
		}
	}

	return 0;
}

void menu() {
	printf("\n1 - Criar uma arvore");
	printf("\n2 - Inserir uma chave");
	printf("\n3 - Imprimir com INORDER");
    printf("\n4 - Imprimir com POSTORDER");
	printf("\n6 - Sair");
}

desc_avl *cria_arvore() {
    desc_avl *nova_arvore = (desc_avl *)malloc(sizeof(desc_avl));
    nova_arvore->raiz = NULL;
    nova_arvore->tamanho = 0;
    return nova_arvore;
}

nodo *cria_nodo() {
    nodo *novo_nodo = (nodo *)malloc(sizeof(nodo));
    novo_nodo->pai = NULL;
    novo_nodo->esq = NULL;
    novo_nodo->dir = NULL;
    return novo_nodo;
}

void insere(desc_avl *arvore,nodo *sub_arvore,int chave) {
    sub_arvore->chave = chave;
    
    if(arvore->raiz == NULL) {
        arvore->raiz = sub_arvore;
    }
}
