typedef struct musica musica;
typedef struct nodo nodo;
typedef struct pilha pilha;

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

struct pilha {
	nodo *primeiro_nodo;
	int tamanho;
};

void menu();
pilha *cria_pilha();
nodo *cria_nodo();
musica *cria_espaco();
void insere(pilha *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code);
nodo *remover(pilha *playlist);
nodo *encontra(pilha *playlist, int code);
void mostra_musica(nodo *aux, int sinal);
void mostra_playlist(pilha *p);
void libera(pilha *playlist);
