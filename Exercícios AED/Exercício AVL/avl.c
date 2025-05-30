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
nodo *cria_nodo();
void insere(desc_avl *arvore,nodo *sub_arvore);
int check_empty(desc_avl *arvore,int code);
void inorder(nodo *nodo);
void postorder(nodo *nodo);
void insere_esq(nodo *sub_arvore,nodo *nodo);
void insere_dir(nodo *sub_arvore,nodo *nodo);

int main() {
	int op,chave;

	desc_avl *arvore = NULL;
	nodo *sub_arvore = NULL;

	while(op != 5) {

		menu();
		printf("\n Escolha uma das opcoes acima: ");
		scanf("%d",&op);

		switch(op) {
		case 1:
			arvore = cria_arvore();
			break;

		case 2:
			sub_arvore = cria_nodo();
			insere(arvore,sub_arvore);
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

nodo *cria_nodo() {
	nodo *novo_nodo = (nodo *)malloc(sizeof(nodo));
	novo_nodo->pai = NULL;
	novo_nodo->esq = NULL;
	novo_nodo->dir = NULL;
	return novo_nodo;
}

void insere(desc_avl *arvore,nodo *sub_arvore) {
	if(arvore == NULL) {
	    printf("\n Crie uma arvore primeiro!");
		return;
	} else {
        int chave;
        
        printf("\n Digite o valor da chave: ");
        scanf("%d",&chave);
        
		sub_arvore->chave = chave;

		if(arvore->raiz == NULL) {
			arvore->raiz = sub_arvore;
		} else {
			if(chave < arvore->raiz->chave) {
				insere_esq(arvore->raiz,sub_arvore);
			}
			else if(chave > arvore->raiz->chave) {
				insere_dir(arvore->raiz,sub_arvore);
			}
		}
	}
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
		inorder(nodo->esq);
		inorder(nodo->dir);
	}
}

void insere_esq(nodo *sub_arvore,nodo *nodo) {
	if(sub_arvore->esq == NULL) {
		sub_arvore->esq = nodo;
	} else {
		if(nodo->chave < sub_arvore->esq->chave) {
			insere_esq(sub_arvore->esq,nodo);
		}
		else if(nodo->chave > sub_arvore->esq->chave) {
			insere_dir(sub_arvore->dir,nodo);
		}
	}
}

void insere_dir(nodo *sub_arvore,nodo *nodo) {
	if(sub_arvore->dir == NULL) {
		sub_arvore->dir = nodo;
	} else {
		if(sub_arvore->chave > sub_arvore->esq->chave) {
			insere_dir(sub_arvore->dir,nodo);
		}
		else if(sub_arvore->chave < sub_arvore->esq->chave) {
			insere_esq(sub_arvore->esq,nodo);
		}
	}
}
