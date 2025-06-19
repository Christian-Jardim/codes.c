typedef struct nodo nodo;
typedef struct desc_avl desc_avl;

struct nodo {
	int chave,
	    altura;
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
int le_chave();

void insere(desc_avl *arvore);
nodo* insere_avl(nodo *novo, nodo *raiz);
nodo* remover_avl(nodo* raiz, int chave);

int altura(nodo *node);
void atualizar_altura(nodo *n);
int balanceamento(nodo *n);
nodo* rebalancear(nodo *node);
nodo* rotacao_esquerda(nodo *n);
nodo* rotacao_direita(nodo *n);

int check_empty(desc_avl *arvore,int code);
void inorder(nodo *node);
void preorder(nodo *node);
