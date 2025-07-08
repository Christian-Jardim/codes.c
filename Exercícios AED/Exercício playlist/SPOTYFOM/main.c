#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct musica Musica;
typedef struct nodo Nodo;
typedef struct lista Lista;
typedef struct fila Fila;
typedef struct pilha Pilha;

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

int menu();
int menu1();
int menu1_1();
int menu1_2();
int menu1_2_2();
int menu1_3();
int menu1_4();
int menu1_5();

int carrega(Lista **acervo);
int output_fila(Fila *fila);
int output_pilha(Pilha *pilha);
int output_acervo(Lista *acervo);

Lista *cria_lista();
Fila *cria_fila();
Pilha *cria_pilha();
Nodo *cria_nodo();
Musica *cria_campo();

void insere(Lista *acervo, Nodo *no);
Fila *playlist_aleatoria(int tamanho, Lista *acervo);
Pilha *playlist_pessoal(Lista *acervo);
void executa_fila(Lista *acervo, Fila *fila);
void executa_pilha(Lista *acervo, Pilha *pilha);

void push(Pilha *pilha, Nodo *item);
void pop(Pilha *pilha);

void enqueue(Fila *fila, Nodo *item);
void dequeue(Fila *fila);

Musica* copia_musica(Nodo *no);

void mostra_musica(Nodo *aux);
void mostra_acervo(Lista *acervo);
Nodo *busca_codigo(Lista *acervo, int codigo);
Nodo *busca_titulo(Lista *acervo, const char *titulo);
Nodo *busca_artista(Lista *acervo, const char *artista);

void libera_lista(Lista *acervo);
void libera_fila(Fila *fila);
void libera_pilha(Pilha *pilha);

int main() {
	int op1,op2,op3,codigo;
	char titulo[256],artista[256];

	Lista *acervo=NULL;
	Fila *fila=NULL;
	Pilha *pilha=NULL;

	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");

	do {
		op1 = menu();
		switch(op1) {
		case 1: // Carrega o arquivo escolhido e, se ele for valido, abre o segundo menu de opcoes
			if (carrega(&acervo) == 0) {
				do {
					op2 = menu1();
					switch(op2) {
					case 1: // Abre o menu para a busca
						do {
							op3 = menu1_1();
							switch(op3) {
							case 1: // Busca uma musica pelo codigo e imprime ela
								printf(" \nInforme o cC3digo: ");
								scanf("%d",&codigo);
								mostra_musica(busca_codigo(acervo,codigo));
								break;
							case 2: // Busca uma musica pelo titulo e imprime ela
								printf(" \nInforme o titulo: ");
								scanf(" %[^\n]s",titulo);
								mostra_musica(busca_titulo(acervo,titulo));
								break;
							case 3: // Busca musicas pelo artista e imprime elas
								printf(" \nInforme o artista: ");
								scanf(" %[^\n]s",artista);
								mostra_musica(busca_artista(acervo,artista));
								break;
							case 0: // Volta para o menu anterior
								break;
							}
						} while(op3 != 0);
						break;
					case 2: // Abre o menu para criar playlists
						do {
							op3 = menu1_2();
							switch(op3) {
							case 1: // Cria uma playlist aleatoria
								printf(" \nInforme o tamanho da playlist: ");
								scanf("%d",&codigo);
								fila = playlist_aleatoria(codigo, acervo);
								break;
							case 2: // Cria uma playlist pessoal
								pilha = playlist_pessoal(acervo);
								break;
							case 0: // Volta para o menu anterior
								break;
							}
						} while(op3 != 0);
						break;
					case 3: // Executa a playlist

						do {
							op3 = menu1_3();
							switch(op3) {
							case 1: //
								executa_fila(acervo,fila);
								break;
							case 2: //
								executa_pilha(acervo,pilha);
								break;
							case 0: // Volta para o menu anterior
								break;
							}
						} while(op3 != 0);
						break;
					case 4: // Abre o menu para gerar o arquivo de relatorio
						do {
							op3 = menu1_4();
							switch(op3) {
							case 1: // Gera um arquivo de saida com os dados da playlist em fila
								output_fila(fila);
								break;
							case 2: // Gera um arquivo de saida com os dados da playlist em pilha
								output_pilha(pilha);
								break;
							case 3: // Gera um arquivo de saida com os dados do acervo
								output_acervo(acervo);
								break;
							case 0: // Volta para o menu anterior
								break;
							}
						} while(op3 != 0);
						break;
					case 5: // Abre o menu de impressao
						do {
							op3 = menu1_5();
							switch(op3) {
							case 1: // Procura uma musica no acervo e imprime se encontra-la
								printf(" \nInforme o tC-tulo da mC:sica: ");
								scanf(" %[^\n]s",titulo);
								mostra_musica(busca_titulo(acervo,titulo));
								break;
							case 2: // Imprime todo o acervo
								mostra_acervo(acervo);
								break;
							case 0: // Volta para o menu anterior
								break;
							}
						} while(op3 != 0);
						break;
					case 0: // Volta para o menu anterior
						break;
					}
				} while(op2 != 0);
			}
			break;
		case 0: // Sai do programa e libera os descritores
			if (acervo != NULL)
				libera_lista(acervo);
			if (fila != NULL)
				libera_fila(fila);
			if (pilha != NULL)
				libera_pilha(pilha);
			break;
		}
	} while(op1 != 0);

	return 0;
}

int menu() {
	int op;
	printf("\n\n ########## MENU ##########\n");
	printf("\n 1 - Carregar arquivo de mC:sicas");
	printf("\n 0 - Sair\n");
	printf("\n Escolha uma das opC'C5es acima: ");
	scanf("%d",&op);
	return op;
}

int menu1() {
	int op;
	printf("\n\n ########## 1 | MENU ##########\n");
	printf("\n 1 - BUSCA");
	printf("\n 2 - PLAYLIST");
	printf("\n 3 - EXECUCCO");
	printf("\n 4 - RELATORIO");
	printf("\n 5 - IMPRESSAO");
	printf("\n 0 - Voltar ao menu anterior\n");
	printf("\n Escolha uma das opC'C5es acima: ");
	scanf("%d",&op);
	return op;
}

int menu1_1() {
	int op;
	printf("\n\n ########## 1.1 | MENU ##########\n");
	printf("\n 1 - Buscar por codigo");
	printf("\n 2 - Buscar por titulo");
	printf("\n 3 - Buscar por artista");
	printf("\n 0 - Voltar ao menu anterior\n");
	printf("\n Escolha uma das opC'C5es acima: ");
	scanf("%d",&op);
	return op;
}

int menu1_2() {
	int op;
	printf("\n\n ########## 1.2 | MENU ##########\n");
	printf("\n 1 - Playlist aleatoria");
	printf("\n 2 - Playlist pessoal");
	printf("\n 0 - Voltar ao menu anterior\n");
	printf("\n Escolha uma das opC'C5es acima: ");
	scanf("%d",&op);
	return op;
}

int menu1_2_2() {
	int op;
	printf("\n\n ########## 1.2.2 | MENU ##########\n");
	printf("\n 1 - Escolher uma musica");
	printf("\n 0 - Voltar ao menu anterior\n");
	printf("\n Escolha uma das opC'C5es acima: ");
	scanf("%d",&op);
	return op;
}

int menu1_3() {
	int op;
	printf("\n\n ########## 1.2.2 | MENU ##########\n");
	printf("\n 1 - Executar a playlist aleatoria");
	printf("\n 2 - Executar a playlist pessoal");
	printf("\n 0 - Voltar ao menu anterior\n");
	printf("\n Escolha uma das opC'C5es acima: ");
	scanf("%d",&op);
	return op;
}

int menu1_4() {
	int op;
	printf("\n\n ########## 1.4 | MENU ##########\n");
	printf("\n 1 - Gerar arquivo da playlist aleatoria");
	printf("\n 2 - Gerar arquivo da playlist pessoal");
	printf("\n 3 - Gerar arquivo do acervo");
	printf("\n 0 - Voltar ao menu anterior\n");
	printf("\n Escolha uma das opC'C5es acima: ");
	scanf("%d",&op);
	return op;
}

int menu1_5() {
	int op;
	printf("\n\n ########## 1.5 | MENU ##########\n");
	printf("\n 1 - Buscar por titulo");
	printf("\n 2 - Imprimir todo o acervo");
	printf("\n 0 - Voltar ao menu anterior\n");
	printf("\n Escolha uma das opC'C5es acima: ");
	scanf("%d",&op);
	return op;
}

int carrega(Lista **acervo) {
	int qt;
	char arquivo[20], linha[100];

	printf("\n Nome do arquivo: ");
	scanf("%s", arquivo);

	FILE *arq = fopen(arquivo, "r");
	if (arq == NULL) {
		printf("**** Erro ao carregar o arquivo ****");
		return 1;
	}

	printf("\n\n**** Arquivo carregado com sucesso ****\n");

	*acervo = cria_lista();

	fscanf(arq, "%d\n", &qt);

	for (int i = 0; i < qt; i++) {
		if (fgets(linha, sizeof(linha), arq)) {
			linha[strcspn(linha, "\n")] = 0; // remove \n

			Nodo *no = cria_nodo();
			Musica *musica = cria_campo();
			no->info = musica;

			char *token = strtok(linha, ";");
			if (!token) continue;
			strcpy(musica->artista, token);

			token = strtok(NULL, ";");
			if (!token) continue;
			strcpy(musica->titulo, token);

			token = strtok(NULL, ";");
			if (!token) continue;
			strcpy(musica->letra, token);

			token = strtok(NULL, ";");
			if (!token) continue;
			musica->execucoes = atoi(token);

			token = strtok(NULL, ";");
			if (!token) continue;
			musica->codigo = atoi(token);

			insere(*acervo, no);
		}
	}

	fclose(arq);
	return 0;
}

Lista *cria_lista() {
	Lista *nLista = (Lista *)malloc(sizeof(Lista));
	nLista->tamanho = 0;
	nLista->inicio=NULL;
	return nLista;
}

Nodo *cria_nodo() {
	Nodo *nNodo=(Nodo *)malloc(sizeof(Nodo));
	nNodo->prox=NULL;
	nNodo->info=NULL;
	return nNodo;
}

Musica *cria_campo() {
	Musica *nMusica = (Musica*)malloc(sizeof(Musica));
	return nMusica;
}

Fila *cria_fila() {
	Fila *nFila = (Fila *)malloc(sizeof(Fila));
	nFila->tamanho = 0;
	nFila->head=NULL;
	nFila->tail=NULL;
	return nFila;
}

Pilha *cria_pilha() {
	Pilha *nPilha = (Pilha *)malloc(sizeof(Pilha));
	nPilha->tamanho = 0;
	nPilha->topo=NULL;
	return nPilha;
}

void insere(Lista *acervo, Nodo *no) {
	if(acervo->inicio == NULL) {
		acervo->inicio = no;
	} else {
		Nodo *aux = acervo->inicio;
		while(aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = no;
	}
	acervo->tamanho++;
}

void mostra_acervo(Lista *acervo) {
	Nodo *aux = acervo->inicio;
	if(aux == NULL) {
		printf("\n Acervo vazio!\n");
	} else {
		printf("\n\n ########## Acervo ##########");
		while(aux != NULL) {
			mostra_musica(aux);
			aux=aux->prox;
		}
	}
}

void mostra_musica(Nodo *aux) {
	if (aux == NULL) {
		printf("\nMC:sica nC#o encontrada.\n");
		return;
	}

	printf("\n\n -------------------------------\n");
	printf("\n Artista: %s",aux->info->artista);
	printf("\n TC-tulo: %s",aux->info->titulo);
	printf("\n Letra: %s",aux->info->letra);
	printf("\n ReproduC'C5es: %d",aux->info->execucoes);
	printf("\n DCC3digo: %d",aux->info->codigo);
	printf("\n\n -------------------------------\n");
}

Nodo *busca_codigo(Lista *acervo, int codigo) {
	if (acervo->inicio == NULL) {
		printf("\n Acervo vazio!\n");
		return NULL;
	}

	Nodo *aux = acervo->inicio;
	while(aux != NULL) {
		if(aux->info->codigo == codigo)
			break;
		aux = aux->prox;
	}

	if(aux == NULL)
		printf("\n Codigo nao encontrado!");

	return aux;
}


Nodo *busca_titulo(Lista *acervo, const char *titulo) {
	if (acervo->inicio == NULL) {
		printf("\n Acervo vazio!\n");
		return NULL;
	}

	Nodo *aux = acervo->inicio;
	while(aux != NULL) {
		if(strcmp(aux->info->titulo, titulo) == 0)
			break;
		aux = aux->prox;
	}

	if(aux == NULL)
		printf("\n Titulo nao encontrado!");

	return aux;
}

Nodo *busca_artista(Lista *acervo, const char *artista) {
	if (acervo->inicio == NULL) {
		printf("\nAcervo vazio!\n");
		return NULL;
	}

	Nodo *aux = acervo->inicio;
	int encontrou = 0;
	while (aux != NULL) {
		if (strcmp(aux->info->artista, artista) == 0) {
			mostra_musica(aux);
			encontrou = 1;
		}
		aux = aux->prox;
	}

	if (!encontrou)
		printf("\nNenhuma mC:sica do artista \"%s\" foi encontrada.\n", artista);
}

Pilha *playlist_pessoal(Lista *acervo) {
	char titulo[256];
	int op;

	Pilha *pilha = cria_pilha();

	do {
		op = menu1_2_2();
		switch(op) {
		case 1:
			Nodo *item = cria_nodo();
			printf("\n Informe o tC-tulo da mC:sica: ");
			scanf(" %[^\n]s",titulo);
			Nodo *resultado = busca_titulo(acervo, titulo);
			if (resultado != NULL) {
				item->info = copia_musica(resultado);
				push(pilha, item);
			} else {
				printf("\nMC:sica nC#o encontrada. NC#o adicionada C  playlist.\n");
				free(item);
			}
			break;
		case 0:
			break;
		}
	} while(op != 0);
	return pilha;
}

void push(Pilha *pilha, Nodo *item) {
	if(item != NULL) {
		item->prox = pilha->topo;
		pilha->topo = item;
		pilha->tamanho++;
	} else {
		free(item);
	}
}

void pop(Pilha *pilha) {
	Nodo *aux = pilha->topo;
	pilha->topo = aux->prox;
	pilha->tamanho--;
	free(aux);
}

void enqueue(Fila *fila, Nodo *item) {
	if(fila->head == NULL) {
		fila->head = item;
		fila->tail = item;
	} else {
		fila->tail->prox = item;
		fila->tail = item;
	}
	fila->tamanho++;
}

void dequeue(Fila *fila) {
	Nodo *aux = fila->head;
	fila->head = aux->prox;
	fila->tamanho--;
	free(aux);
}

Musica* copia_musica(Nodo *no) {
	Musica *nova = malloc(sizeof(Musica));
	if (nova != NULL) {
		strcpy(nova->titulo, no->info->titulo);
		strcpy(nova->artista, no->info->artista);
		strcpy(nova->letra, no->info->letra);
		nova->execucoes = no->info->execucoes;
		nova->codigo = no->info->codigo;
	}
	return nova;
}

Fila *playlist_aleatoria(int tamanho, Lista *acervo) {

	Fila *fila = cria_fila();
	Nodo *aux = acervo->inicio;

	printf("\n ########## MUSICAS QUE ENTRARAM NA PLAYLIST ##########\n");

	for(int i = 0; i < tamanho; i++) {
		aux = acervo->inicio;
		int o = rand() % acervo->tamanho;
		for(int j = 0; j < o; j++) {
			aux = aux->prox;
		}
		Nodo *item = cria_nodo();
		item->info = copia_musica(aux);
		enqueue(fila, item);

		mostra_musica(item);
	}

	return fila;
}

void executa_pilha(Lista *acervo, Pilha *pilha) {
	if (pilha == NULL || acervo == NULL) return;

	while (pilha->tamanho > 0 && pilha->topo != NULL) {
		Nodo *Topo = pilha->topo;
		Nodo *aux = acervo->inicio;

		// Procura a mC:sica no acervo
		while (aux != NULL) {
			if (aux->info->codigo == Topo->info->codigo) {
				aux->info->execucoes++;
				break;
			}
			aux = aux->prox;
		}
        printf("\nExecutando: %s - %s\n", Topo->info->artista, Topo->info->titulo);
		pop(pilha);
	}
}

void executa_fila(Lista *acervo, Fila *fila) {
	if (fila == NULL || acervo == NULL) return;

	while (fila->tamanho > 0 && fila->head != NULL) {
		Nodo *Head = fila->head;
		Nodo *aux = acervo->inicio;

		// Procura a mC:sica no acervo
		while (aux != NULL) {
			if (aux->info->codigo == Head->info->codigo) {
				aux->info->execucoes++;
				break;
			}
			aux = aux->prox;
		}
		printf("\nExecutando: %s - %s\n", Head->info->artista, Head->info->titulo);
		dequeue(fila);
	}
}

int output_fila(Fila *fila) {
	char arquivo[20];

	printf("\n Nome do arquivo: ");
	scanf("%s", arquivo);

	FILE *arq = fopen(arquivo, "w");
	if(arq == NULL) {
		printf("Erro ao gerar o arquivo");
		return 1;
	}

	Nodo *aux = fila->head;
	fprintf(arq,"%d\n",fila->tamanho);

	for(int i = 0; i < fila->tamanho; i++) {
		fprintf(arq,"%s;",aux->info->artista);
		fprintf(arq,"%s;",aux->info->titulo);
		fprintf(arq,"%s;",aux->info->letra);
		fprintf(arq,"%d;",aux->info->execucoes);
		fprintf(arq,"%d\n",aux->info->codigo);
		aux = aux->prox;
	}

	fclose(arq);

	printf("\n\n **** Arquivo gerado com sucesso ****\n");
}

int output_pilha(Pilha *pilha) {
	char arquivo[20];

	printf("\n Nome do arquivo: ");
	scanf("%s", arquivo);

	FILE *arq = fopen(arquivo, "w");
	if(arq == NULL) {
		printf("Erro ao gerar o arquivo");
		return 1;
	}

	Nodo *aux = pilha->topo;
	fprintf(arq,"%d\n",pilha->tamanho);

	for(int i = 0; i < pilha->tamanho; i++) {
		fprintf(arq,"%s;",aux->info->artista);
		fprintf(arq,"%s;",aux->info->titulo);
		fprintf(arq,"%s;",aux->info->letra);
		fprintf(arq,"%d;",aux->info->execucoes);
		fprintf(arq,"%d\n",aux->info->codigo);
		aux = aux->prox;
	}

	fclose(arq);

	printf("\n\n **** Arquivo gerado com sucesso ****\n");
}

int output_acervo(Lista *acervo) {
	char arquivo[20];

	printf("\n Nome do arquivo: ");
	scanf("%s", arquivo);

	FILE *arq = fopen(arquivo, "w");
	if(arq == NULL) {
		printf("Erro ao gerar o arquivo");
		return 1;
	}

	Nodo *aux = acervo->inicio;
	fprintf(arq,"%d\n",acervo->tamanho);

	for(int i = 0; i < acervo->tamanho; i++) {
		fprintf(arq,"%s;",aux->info->artista);
		fprintf(arq,"%s;",aux->info->titulo);
		fprintf(arq,"%s;",aux->info->letra);
		fprintf(arq,"%d;",aux->info->execucoes);
		fprintf(arq,"%d\n",aux->info->codigo);
		aux = aux->prox;
	}

	fclose(arq);

	printf("\n\n **** Arquivo gerado com sucesso ****\n");
}

void libera_lista(Lista *acervo) {
	Nodo *aux = acervo->inicio;
	while (aux != NULL) {
		Nodo *temp = aux;
		aux = aux->prox;
		free(temp->info); // libera Musica
		free(temp);       // libera Nodo
	}
	free(acervo);
}

void libera_fila(Fila *fila) {
	Nodo *aux = fila->head;
	while (aux != NULL) {
		Nodo *temp = aux;
		aux = aux->prox;
		free(temp->info);
		free(temp);
	}
	free(fila);
}

void libera_pilha(Pilha *pilha) {
	Nodo *aux = pilha->topo;
	while (aux != NULL) {
		Nodo *temp = aux;
		aux = aux->prox;
		free(temp->info);
		free(temp);
	}
	free(pilha);
}
