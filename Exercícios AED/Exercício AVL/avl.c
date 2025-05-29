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
void print(desc_avl *arvore);
void inorder(nodo *nodo);
void insere_esq(nodo *sub_arvore,nodo *nodo,int chave);
void insere_dir(nodo *sub_arvore,nodo *nodo,int chave);

int main() {
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

			insere(arvore,sub_arvore,chave);
			break;
		case 3:
			print(arvore);
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
	printf("\n\n1 - CREATE AVL");
	printf("\n2 - INSERT");
	printf("\n3 - PRINT INORDER");
	//printf("\n4 - Imprimir com POSTORDER");
	printf("\n6 - SAIR");
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
	} else {
		if(chave < arvore->raiz->chave) {
			insere_esq(arvore->raiz,sub_arvore,chave);
		}
		else if(chave > arvore->raiz->chave) {
			insere_dir(arvore->raiz,sub_arvore,chave);
		}
	}
}

void print(desc_avl *arvore) {
	if(arvore == NULL) {
		printf("Crie uma arvaore primeiro!\n");
	} else {
		if(arvore->raiz == NULL) {
			printf("Arvore vazia!\n");
		} else {
			inorder(arvore->raiz);
		}
	}
}

void inorder(nodo *nodo) {
	if(nodo != NULL) {
		inorder(nodo->esq);
		printf("\n%d",nodo->chave);
		inorder(nodo->dir);
	}
}

void insere_esq(nodo *sub_arvore,nodo *nodo,int chave) {
	if(sub_arvore->esq == NULL) {
		sub_arvore->esq = nodo;
	} else {
		if(chave < sub_arvore->esq->chave) {
			insere_esq(sub_arvore->esq,nodo,chave);
		}
		else if(chave > sub_arvore->esq->chave) {
			insere_dir(sub_arvore->dir,nodo,chave);
		}
	}
}

void insere_dir(nodo *sub_arvore,nodo *nodo,int chave) {
	if(sub_arvore->dir == NULL) {
		sub_arvore->dir = nodo;
	} else {
		if(chave > sub_arvore->esq->chave) {
			insere_dir(sub_arvore->dir,nodo,chave);
		}
		else if(chave < sub_arvore->esq->chave) {
			insere_esq(sub_arvore->esq,nodo,chave);
		}
	}
}
