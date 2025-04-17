typedef struct musica musica;
typedef struct nodo nodo;
typedef struct desc desc;

struct musica {
	char titulo[256];
	char artista[256];
	char letra[256];
	int codigo;
	int execucoes;
};

struct nodo {
	nodo *prox;
	musica *info;
};

struct desc {
	nodo *primeiro_nodo;
	int tamanho;
};

void menu();
desc *cria_desc();
nodo *cria_nodo();
musica *cria_espaco();
void insere(desc *p, nodo *n, musica *s);
void mostra_playlist(desc *p);
