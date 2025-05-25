typedef struct musica musica;
typedef struct nodo nodo;
typedef struct fila fila;

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

struct fila {
	nodo *primeiro_nodo;
	nodo *ultimo_nodo;
	int tamanho;
};

void menu();
fila *cria_fila();
nodo *cria_nodo();
musica *cria_espaco();
void empty(fila *playlist);
bool check_empty(fila *playlist);
int tamanho(fila *playlist);
void insere(fila *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code);
nodo *remover(fila *playlist);
nodo *encontra(fila *playlist, int code);
void mostra_musica(nodo *aux, int sinal);
void mostra_playlist(fila *p);
void libera(fila *playlist);