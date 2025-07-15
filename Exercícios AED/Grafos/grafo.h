struct descritor_grafo {
	int max_vertices;
	int max_arestas;
	struct nodo *nodos;
};

struct nodo {
	int chave;
	struct nodo *prox;
	//struct nodo *adjacencias;
	struct aresta *adjacencias;
};

struct aresta {
	int partida;
	int chegada;
	int peso;
	struct aresta *prox;
};

struct descritor_grafo* parser();
struct descritor_grafo * inicializaGrafo(int tamanho);
struct nodo* criaVertice(int chave);
void insereVertice(struct descritor_grafo *grafo, int chave);
struct descritor_grafo * insereAresta(struct descritor_grafo *grafo, int chaveSaida, int chaveChegada, int peso);
struct nodo* buscaVertice(struct descritor_grafo *grafo, int chaveBusca);
struct nodo* buscaAdjacencia(struct descritor_grafo *grafo, int partida, int chegada);
int tamanhoVertices(struct descritor_grafo *grafo);
int tamanhoAdjacencias(struct descritor_grafo *grafo);
int listaAjacencias(struct nodo *vertice);
void imprimeGrafo(struct descritor_grafo *grafo);

//--------------- REPRESENTAÇÃO COM MATRIZ DE ADJACÊNCIA ---------------------

struct descritor_grafo_matriz {
	int max_vertices;
	int max_arestas;
	int **grafoMatriz;
};

struct descritor_grafo_matriz* parserMatriz(char *nomeArquivo);
struct descritor_grafo_matriz * inicializaGrafoMatriz(int tamanho);
struct descritor_grafo_matriz * insereArestaMatriz(struct descritor_grafo_matriz *grafo, int chaveSaida, int chaveChegada, int peso);
void imprimeGrafoMatriz(struct descritor_grafo_matriz *grafoMatriz);

// ----------------- STACK E QUEUE ------------

struct nodo_busca {
	struct aresta *aresta_busca;
	struct nodo_busca *prox;
};

//--------------- STACK ---------------------

struct desc_stack {
	struct nodo_busca *top;
	int tamanho;
};

struct desc_stack *criaDescStack(void);
struct nodo_busca* criaNodoStack(struct aresta *arestaPilha);
void push(struct desc_stack *stack,struct nodo_busca *novoElemento);
struct nodo_busca* pop(struct desc_stack *stack);
int empty_stack(struct desc_stack *stack);
int length_stack(struct desc_stack *stack);
void makeNull_stack(struct desc_stack *stack);
struct nodo_busca* top(struct desc_stack *stack);
void showStack(struct desc_stack *stack);

//--------------- QUEUE ---------------------

struct desc_queue {
	struct nodo_busca *head;
	struct nodo_busca *tail;
	int tamanho;
};

struct desc_queue *criaDescQueue(void);
struct nodo_busca* criaNodoQueue(struct aresta *arestaQueue) ;
void enqueue(struct desc_queue *queue, struct nodo_busca *novoElemento);
struct nodo_busca* dequeue(struct desc_queue *queue);
int empty_queue(struct desc_queue *queue);
int length_queue(struct desc_queue *queue);
void makeNull_queue(struct desc_queue *queue);
struct nodo_busca* head(struct desc_queue *queue);
void showQueue(struct desc_queue *queue);

//------------------- BFS ---------------------

void busca_largura(struct descritor_grafo *grafo, int chave_origem);
