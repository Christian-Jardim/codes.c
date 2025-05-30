#include <stdio.h>
#include <stdlib.h>

typedef struct nodo nodo;
typedef struct desc_avl desc_avl;

struct nodo {
	int chave;
	nodo *pai,
	     *esq,
	     *dir;
};

struct desc_avl {
	nodo *raiz;
	int tamanho;
};

void menu();
desc_avl *cria_arvore();
nodo *cria_nodo(int chave);
void insere(desc_avl *arvore);
int le_chave();
int check_empty(desc_avl *arvore,int code);
void inorder(nodo *node);
void postorder(nodo *node);

int main() {
	int op;

	desc_avl *arvore = NULL;

	while(op != 5) {

		menu();
		printf("\n Escolha uma das opcoes acima: ");
		scanf("%d",&op);

		switch(op) {
		case 1:
			arvore = cria_arvore();
			break;

		case 2:
			insere(arvore);
			break;

		case 3:
			check_empty(arvore,0);
			break;

		case 4:
			check_empty(arvore,1);
			break;

		case 6:
			return 0;
			break;

		default:
			printf("\n Opcao invalida!");
		}
	}

	return 0;
}

void menu() {
	printf("\n\n 1 - CREATE AVL");
	printf("\n 2 - INSERT");
	printf("\n 3 - PRINT INORDER");
	printf("\n 4 - PRINT POSTORDER");
	printf("\n 6 - SING OUT");
}

desc_avl *cria_arvore() {
	desc_avl *nova_arvore = (desc_avl *)malloc(sizeof(desc_avl));
	nova_arvore->raiz = NULL;
	nova_arvore->tamanho = 0;
	return nova_arvore;
}

nodo *cria_nodo(int chave) {
	nodo *novo_nodo = (nodo *)malloc(sizeof(nodo));
	novo_nodo->chave = chave;
	novo_nodo->pai = NULL;
	novo_nodo->esq = NULL;
	novo_nodo->dir = NULL;
	return novo_nodo;
}

void insere(desc_avl *arvore) {
	if(arvore == NULL) {
		printf("\n Crie uma arvore primeiro!");
		return;
	} else {
		nodo *node = cria_nodo(le_chave());
		if(arvore->raiz == NULL) {
			arvore->raiz = node;
		} else {
		    nodo *atual = arvore->raiz;
			while (1) {
				if (node->chave < atual->chave) {
					if (atual->esq == NULL) {
						atual->esq = node;
						break;
					} else {
						atual = atual->esq;
					}
				} else if (node->chave > atual->chave) {
					if (atual->dir == NULL) {
						atual->dir = node;
						break;
					} else {
						atual = atual->dir;
					}
				} else {
					printf("\nChave duplicada!");
					free(node);
					break;
				}
			}
		}
	}
}

int le_chave() {
	int chave;
	printf("\n Digite o valor da chave: ");
	scanf("%d",&chave);
	return chave;
}

int check_empty(desc_avl *arvore,int code) {
	if(arvore == NULL) {
		printf("\n Crie uma arvore primeiro!");
		return 1;
	} else {
		if(arvore->raiz == NULL) {
			printf("\n Arvore vazia!");
		} else {
			if(code == 0) {
				inorder(arvore->raiz);
			}
			else if(code == 1) {
				postorder(arvore->raiz);
			}
		}
	}
}

void inorder(nodo *nodo) {
	if(nodo != NULL) {
		inorder(nodo->esq);
		printf("\n %d",nodo->chave);
		inorder(nodo->dir);
	}
}

void postorder(nodo *nodo) {
	if(nodo != NULL) {
		printf("\n %d",nodo->chave);
		postorder(nodo->esq);
		postorder(nodo->dir);
	}
}
