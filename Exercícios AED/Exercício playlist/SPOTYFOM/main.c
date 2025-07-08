#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct musica Musica;
typedef struct nodo Nodo;
typedef struct desc Lista;
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
	Nodo *primeiro_nodo;
	int tamanho;
};

struct fila {
	Nodo *head;
	Nodo *tail;
	int tamanho;
};

struct pilha {
	Nodo *top;
	int tamanho;
};

int menu();
int menu1();
int menu1_1();
int menu1_2();
int menu1_2_2();
int menu1_4();
int menu1_5();

int carrega(Desc **acervo);
int gera(Desc *fonte);

Lista *cria_desc();
Nodo *cria_nodo();
Musica *cria_campo();

void insere(Desc *acervo, Nodo *no);
Fila *playlist_aleatoria(int codigo, Desc *acervo);
Pilha *playlist_pessoal(Desc *acervo);
void executa(Lista *acervo, Fila *fila, Pilha *pilha);

void push(Desc *playlist, Nodo *item);
void pop(Pilha *pilha);
Musica* copia_musica(Nodo *no);

void mostra_musica(Nodo *aux);
void mostra_acervo(Lista *acervo);
Nodo *busca_codigo(Lista *acervo, int codigo);
Nodo *busca_titulo(Lista *acervo, const char *titulo);
Nodo *busca_artista(Lista *acervo, const char *artista);

int main() {
	int op1,op2,op3,codigo;
	char titulo[256],artista[256];

	Lista *acervo=NULL;
	Fila *fila=NULL;
	Pilha *pilha=NULL;

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
								playlist_aleatoria(codigo);
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
						executa(acervo, fila, pilha);
						break;
					case 4: // Abre o menu para gerar o arquivo de relatorio
						do {
							op3 = menu1_4();
							switch(op3) {
							case 1: // Gera um arquivo de saida com os dados da playlist
								gera(fila, pilha);
								break;
							case 2: // Gera um arquivo de saida com os dados do acervo
								gera(acervo);
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
		case 0: // Sai do programa
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

int menu1_4() {
	int op;
	printf("\n\n ########## 1.4 | MENU ##########\n");
	printf("\n 1 - Gerar arquivo da playlist");
	printf("\n 2 - Gerar arquivo do acervo");
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

int carrega(Desc **acervo) {
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

	*acervo = cria_desc();

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

Desc *cria_desc() {
	Desc *nDesc = (Desc *)malloc(sizeof(Desc));
	nDesc->tamanho = 0;
	nDesc->primeiro_nodo=NULL;
	return nDesc;
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



void insere(Desc *acervo, Nodo *no) {
	if(acervo->primeiro_nodo == NULL) {
		acervo->primeiro_nodo = no;
	} else {
		Nodo *aux = acervo->primeiro_nodo;
		while(aux->prox != NULL) {
			aux = aux->prox;
		}
		aux->prox = no;
	}
	acervo->tamanho++;
}

void mostra_acervo(Desc *acervo) {
	Nodo *aux = acervo->primeiro_nodo;
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
	if(aux == NULL)
		return;

	printf("\n\n -------------------------------\n");
	printf("\n Artista: %s",aux->info->artista);
	printf("\n TC-tulo: %s",aux->info->titulo);
	printf("\n Letra: %s",aux->info->letra);
	printf("\n ReproduC'C5es: %d",aux->info->execucoes);
	printf("\n DCC3digo: %d",aux->info->codigo);
	printf("\n\n -------------------------------\n");
}

Nodo *busca_codigo(Desc *acervo, int codigo) {
	if (acervo->primeiro_nodo == NULL) {
		printf("\n Acervo vazio!\n");
		return NULL;
	}

	Nodo *aux = acervo->primeiro_nodo;
	while(aux != NULL) {
		if(aux->info->codigo == codigo)
			break;
		aux = aux->prox;
	}

	if(aux == NULL)
		printf("\n Codigo nao encontrado!");

	return aux;
}


Nodo *busca_titulo(Desc *acervo, const char *titulo) {
	if (acervo->primeiro_nodo == NULL) {
		printf("\n Acervo vazio!\n");
		return NULL;
	}

	Nodo *aux = acervo->primeiro_nodo;
	while(aux != NULL) {
		if(strcmp(aux->info->titulo, titulo) == 0)
			break;
		aux = aux->prox;
	}

	if(aux == NULL)
		printf("\n Titulo nao encontrado!");

	return aux;
}

Nodo *busca_artista(Desc *acervo, const char *artista) {
	if (acervo->primeiro_nodo == NULL) {
		printf("\n Acervo vazio!\n");
		return NULL;
	}

	Nodo *aux = acervo->primeiro_nodo;
	while (aux != NULL) {
		if (strcmp(aux->info->artista, artista) == 0)
			break;
		aux = aux->prox;
	}

	if(aux == NULL)
		printf("\n Artista nao encontrado!\n");

	return aux;
}

Desc *playlist_pessoal(Desc *acervo) {
	char titulo[256];
	int op;

	Desc *playlist = cria_desc();

	do {
		op = menu1_2_2();
		switch(op) {
		case 1:
			Nodo *item = cria_nodo();
			printf("\n Informe o tC-tulo da mC:sica: ");
			scanf(" %[^\n]s",titulo);
			item-> info = copia_musica(busca_titulo(acervo,titulo));
			push(playlist,item);
			break;
		case 0:
			break;
		}
	} while(op != 0);
	return playlist;
}

void push(Desc *playlist, Nodo *item) {
	if(item != NULL) {
		item->prox = playlist->primeiro_nodo;
		playlist->primeiro_nodo = item;
		playlist->tamanho++;
	} else {
		free(item);
	}
}

void pop(Desc *playlist) {
	Nodo *aux = playlist->primeiro_nodo;
	playlist->primeiro_nodo = aux->prox;
	playlist->tamanho--;
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

Desc *playlist_aleatoria(int codigo, Desc *acervo) {
    int i;
    
    Fila *playlist = cria_fila;
    Nodo *aux = acervo->primeiro_nodo;
    
    for(i = 0; i < tamanho; i++) {
        for(int j = 0; j < (rand() % 10); j++)
            aux = aux->prox;
        Nodo *item = cria_nodo();
        item-> info = copia_musica(aux);
        enqueue(playlist, item);
    }
    
    return playlist;
}

void executa(Desc *acervo, Desc *playlist) {
	Nodo *aux = acervo->primeiro_nodo;

	if(playlist != NULL && acervo != NULL) {
		while(playlist->tamanho > 0) {
			while(aux != NULL) {
				if(aux->info->codigo == playlist->primeiro_nodo->info->codigo)
					break;
				aux = aux->prox;
			}
			aux->info->execucoes++;
			aux = acervo->primeiro_nodo;
			pop(playlist);
		}
	}
}

int gera(Desc *fonte) {
	char arquivo[20];

	printf("\n Nome do arquivo: ");
	scanf("%s", arquivo);

	FILE *arq = fopen(arquivo, "w");
	if(arq == NULL) {
		printf("Erro ao gerar o arquivo");
		return 1;
	}

	Nodo *aux = fonte->primeiro_nodo;

	fprintf(arq,"%d\n",fonte->tamanho);
	for(int i = 0; i < fonte->tamanho; i++) {
		fprintf(arq,"%s;",aux->info->artista);
		fprintf(arq,"%s;",aux->info->titulo);
		fprintf(arq,"%s;",aux->info->letra);
		fprintf(arq,"%d;",aux->info->execucoes);
		fprintf(arq,"%d\n",aux->info->codigo);
		aux = aux->prox;
	}

	fclose(arq);

	printf("\n\n **** Arquivo carregado com sucesso ****\n");
}
