typedef struct lista Lista;
typedef struct fila Fila;
typedef struct pilha Pilha;
typedef struct musica Musica;
typedef struct nodo Nodo;

struct musica {
	char titulo[256];
	char artista[256];
	char letra[256];
	int codigo;
	int execucoes;
};

struct nodo {
	Nodo *prox;
	Musica *info;
	Nodo *ant;
};

struct lista {
	Nodo *inicio;
	int tamanho;
};

struct fila {
	Nodo *head;
	Nodo *tail;
	int tamanho;
};

struct pilha {
	Nodo *topo;
	int tamanho;
};

// Funcoes dos menus
int menu();
int menu1();
int menu1_1();
int menu1_2();
int menu1_2_2();
int menu1_3();
int menu1_4();
int menu1_5();

// Funcoes para gerar os arquivos
int carrega(Lista **acervo);
int output_acervo(Lista *acervo);
int output_fila(Fila *fila);
int output_pilha(Pilha *pilha);

// Funcoes de alocamento de espaco
Lista *cria_lista();
Fila *cria_fila();
Pilha *cria_pilha();
Nodo *cria_nodo();
Musica *cria_campo();

void insere(Lista *acervo, Nodo *no); // Insere um nodo na lista encadeada
Musica* copia_musica(Nodo *no); // Copia uma musica

// Funcoes da playlist aleatoria (fila)
Fila *playlist_aleatoria(int tamanho, Lista *acervo);
void executa_fila(Lista *acervo, Fila *fila);
void enqueue(Fila *fila, Nodo *item);
void dequeue(Fila *fila);

// Funcoes da playlist pessoal (pilha)
Pilha *playlist_pessoal(Lista *acervo);
void executa_pilha(Lista *acervo, Pilha *pilha);
void push(Pilha *pilha, Nodo *item);
void pop(Pilha *pilha);

// Funcoes de impressao
void mostra_musica(Nodo *aux);
void mostra_acervo(Lista *acervo);

// Funcoes de busca
Nodo *busca_codigo(Lista *acervo, int codigo);
Nodo *busca_titulo(Lista *acervo, const char *titulo);
Nodo *busca_artista(Lista *acervo, const char *artista);

// Funcoes para liberar espaco
void libera_lista(Lista *acervo);
void libera_fila(Fila *fila);
void libera_pilha(Pilha *pilha);
