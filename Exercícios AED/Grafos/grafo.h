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

//--------------- REPRESENTAÇÃO COM MATRIZ DE ADJACÊNCIA ---------------------

struct descritor_grafo_matriz {
	int max_vertices;
	int max_arestas;
	int **grafoMatriz;
};

struct descritor_grafo_matriz* parserMatriz(char *nomeArquivo);
struct descritor_grafo_matriz * inicializaGrafoMatriz(int tamanho);
struct descritor_grafo_matriz * insereArestaMatriz(struct descritor_grafo_matriz *grafo, int chaveSaida, int chaveChegada, int peso);
void imprimeGrafoMatriz(struct descritor_grafo_matriz *grafoMatriz);

//--------------- STACK ---------------------

struct nodopilha {
	struct aresta *arestaPilha;
	struct nodopilha *prox;
};

struct desc_stack {
	struct nodopilha *top;
	int tamanho;
};

struct desc_stack *criaDescStack(void);
struct nodopilha* criaNodoStack(struct aresta *arestaPilha);
void push(struct desc_stack *stack,struct nodopilha*novoElemento);
struct nodopilha* pop(struct desc_stack *stack);
int empty(struct desc_stack *stack);
int length(struct desc_stack *stack);
void makeNull(struct desc_stack *stack);
struct nodopilha* top(struct desc_stack *stack);
void showStack(struct desc_stack *stack);

//--------------- QUEUE ---------------------

struct fila {
    int chave;
    struct fila *prox;
};

void enqueue(struct fila **inicio, struct fila **fim, int chave);
int dequeue(struct fila **inicio, struct fila **fim);


//--------------- BFS ---------------------

void bfs(struct descritor_grafo *grafo, int inicio_chave);
