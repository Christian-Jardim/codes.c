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
void valida_code(desc * playlist, int *code);
void valida_posicao(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code, int posicao);
void insere(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code);
nodo *remover_encontra(desc *playlist, int code, int sinal1, int sinal2, int sinal3);
void mostra_musica(nodo *aux, int sinal);
void mostra_playlist(desc *p);
void toca(nodo *aux);
void ver_tamanho(desc *playlist);
void libera(desc *playlist);
