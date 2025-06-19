#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void menu() {
	printf("\n\n 1 - CREATE AVL");
	printf("\n 2 - INSERT");
	printf("\n 3 - REMOVE");
	printf("\n 4 - PRINT INORDER");
	printf("\n 5 - PRINT PREORDER");
	printf("\n 6 - SIGN OUT");
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
	novo_nodo->altura = 1;
	novo_nodo->pai = NULL;
	novo_nodo->esq = NULL;
	novo_nodo->dir = NULL;
	return novo_nodo;
}

int le_chave() {
	int chave;
	printf("\n Digite o valor da chave: ");
	scanf("%d",&chave);
	return chave;
}

void insere(desc_avl *arvore) {
	if(arvore == NULL) {
		printf("\n Crie uma arvore primeiro!");
		return;
	} else {
		nodo *node = cria_nodo(le_chave());
		arvore->raiz = insere_avl(node, arvore->raiz);
	}
}

nodo* insere_avl(nodo *novo, nodo *raiz) {
	if(raiz == NULL) {
		return novo;
	}

	if(novo->chave < raiz->chave) {
		raiz->esq = insere_avl(novo, raiz->esq);
		raiz->esq->pai = raiz;
	} else if(novo->chave > raiz->chave) {
		raiz->dir = insere_avl(novo, raiz->dir);
		raiz->dir->pai = raiz;
	} else {
		printf("\nChave duplicada! Falha ao inserir!");
		return raiz;
	}

    return rebalancear(raiz);
}

void atualizar_altura(nodo *n) {
    if (n)
        n->altura = 1 + (altura(n->esq) > altura(n->dir) ? altura(n->esq) : altura(n->dir));
}

int altura(nodo *n) {
	if (n != NULL)
		return n->altura;
	else
		return -1;
}

int balanceamento(nodo *n) {
    return altura(n->dir) - altura(n->esq);
}


nodo* rebalancear(nodo *node) {
    atualizar_altura(node);
    int fb = balanceamento(node);

    if (fb < -1) {
        if (balanceamento(node->esq) > 0)
            node->esq = rotacao_esquerda(node->esq);
        return rotacao_direita(node);
    } else if (fb > 1) {
        if (balanceamento(node->dir) < 0)
            node->dir = rotacao_direita(node->dir);
        return rotacao_esquerda(node);
    }

    return node;
}

nodo* rotacao_esquerda(nodo *n) {
    nodo *aux = n->dir;
    n->dir = aux->esq;
    if (aux->esq) aux->esq->pai = n;
    aux->esq = n;

    aux->pai = n->pai;
    n->pai = aux;

    atualizar_altura(n);
    atualizar_altura(aux);

    return aux;
}

nodo* rotacao_direita(nodo *n) {
    nodo *aux = n->esq;
    n->esq = aux->dir;
    if (aux->dir) aux->dir->pai =n;
    aux->dir = n;

    aux->pai = n->pai;
    n->pai = aux;

    atualizar_altura(n);
    atualizar_altura(aux);

    return aux;
}

nodo* remover_avl(nodo* raiz, int chave) {
	if (raiz == NULL) {
		printf("\nChave inexistente!");
		return NULL;
	}

	if (chave < raiz->chave) {
		raiz->esq = remover_avl(raiz->esq, chave);
		if (raiz->esq) raiz->esq->pai = raiz;
	} else if (chave > raiz->chave) {
		raiz->dir = remover_avl(raiz->dir, chave);
		if (raiz->dir) raiz->dir->pai = raiz;
	} else {
		if (raiz->esq == NULL) {
			nodo *temp = raiz->dir;
			if (temp) temp->pai = raiz->pai;
			free(raiz);
			return temp;
		} else if (raiz->dir == NULL) {
			nodo *temp = raiz->esq;
			if (temp) temp->pai = raiz->pai;
			free(raiz);
			return temp;
		}

		nodo *sucessor = raiz->dir;
		while (sucessor->esq != NULL)
			sucessor = sucessor->esq;

		raiz->chave = sucessor->chave;
		raiz->dir = remover_avl(raiz->dir, sucessor->chave);
		if (raiz->dir) raiz->dir->pai = raiz;
	}
    return rebalancear(raiz);
}

int check_empty(desc_avl *arvore, int code) {
	if(arvore == NULL) {
		printf("\n Crie uma arvore primeiro!");
		return 1;
	}
	if(arvore->raiz == NULL) {
		printf("\n Arvore vazia!");
		return 1;
	}

	if(code == 0)
		inorder(arvore->raiz);
	else if(code == 1)
		preorder(arvore->raiz);
	else if(code == 2) {
		int chave;
		printf("\nDigite o valor da chave que deseja remover: ");
		scanf("%d",&chave);
		arvore->raiz = remover_avl(arvore->raiz, chave);
	}
	return 0;
}

void inorder(nodo *nodo) {
	if(nodo != NULL) {
		inorder(nodo->esq);
		printf("\n %d",nodo->chave);
		inorder(nodo->dir);
	}
}

void preorder(nodo *nodo) {
	if(nodo != NULL) {
	    printf("\n %d", nodo->chave);
		preorder(nodo->esq);
		preorder(nodo->dir);
	}
}
