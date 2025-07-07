#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct musica Musica;
typedef struct nodo Nodo;
typedef struct desc Desc;

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

struct desc {
	Nodo *primeiro_nodo;
	int tamanho;
};

int menu();
int menu1();
int menu1_1();
int menu1_5();

int carrega(Desc **acervo);

Desc *cria_desc();
Nodo *cria_nodo();
Musica *cria_campo();

void insere(Desc *acervo, Nodo *no);
void mostra_musica(Nodo *aux, int sinal);
void mostra_acervo(Desc *acervo);
void busca_codigo(Desc *acervo, int codigo);
void busca_titulo(Desc *acervo, const char *titulo);
void busca_artista(Desc *acervo, const char *artista);

int main() {
	int op1,op2,op3,qt = 0,codigo;
	char titulo[256],artista[256];
	Desc *acervo=NULL;
	setlocale(LC_ALL, "Portuguese");

	do {
		op1 = menu();
		switch(op1) {
		case 1:
			qt = carrega(&acervo);
			if (qt != 0) {
				do {
					op2 = menu1();
					switch(op2) {
					case 1:
						op3 = menu1_1();
						switch(op3) {
						case 1:
							printf(" \nInforme o codigo: ");
							scanf("%d",&codigo);
							busca_codigo(acervo,codigo);
							break;
						case 2:
							printf(" \nInforme o titulo: ");
							scanf(" %[^\n]s",titulo);
							busca_titulo(acervo,titulo);
							break;
						case 3:
							printf(" \nInforme o artista: ");
							scanf(" %[^\n]s",artista);
							busca_artista(acervo,artista);
							break;
						case 0:
							break;
						default:
							printf("\n OpC'C#o invC!lida\n");
						}
						break;
					case 2:
					    op3 = menu1_1();
						switch(op3) {
						case 1:
							printf(" \nInforme o tamanho da playlist: ");
							scanf("%d",&codigo);
							//busca_codigo(acervo,codigo);
							break;
						case 2:
							printf(" \nInforme o titulo: ");
							scanf(" %[^\n]s",titulo);
							//busca_titulo(acervo,titulo);
							break;
						case 0:
							break;
						default:
							printf("\n OpC'C#o invC!lida\n");
						}
						break;
					case 3:
						break;
					case 4:
						break;
					case 5:
						op3 = menu1_5();
						switch(op3) {
						case 1:
							printf(" \nInforme o tC-tulo da mC:sica: ");
							scanf(" %[^\n]s",titulo);
							busca_titulo(acervo,titulo);
							break;
						case 2:
							mostra_acervo(acervo);
							break;
						case 0:
							break;
						default:
							printf("\n OpC'C#o invC!lida\n");
						}
						break;
					case 0:
						break;
					default:
						printf("\n OpC'C#o invC!lida\n");
					}
				} while(op2 != 0);
			}
			break;
		case 0:
			break;
		default:
			printf("\n OpC'C#o invC!lida\n");
		}
	} while(op1 != 0);

	return 0;
}

int menu() {
	int op;
	printf("\n\n ---------- MENU ----------");
	printf("\n 1 - Carregar arquivo de mC:sicas");
	printf("\n 0 - Sair\n");
	printf("\n Escolha uma das opC'C5es acima: ");
	scanf("%d",&op);
	return op;
}

int menu1() {
	int op;
	printf("\n\n ------- 1 | MENU -------");
	printf("\n 1 - BUSCA");
	printf("\n 2 - PLAYLIST");
	printf("\n 3 - EXECUCCO");
	printf("\n 4 - IMPRESSCO");
	printf("\n 5 - RELATCRIO");
	printf("\n 0 - Voltar ao menu anterior\n");
	printf("\n Escolha uma das opC'C5es acima: ");
	scanf("%d",&op);
	return op;
}

int menu1_1() {
	int op;
	printf("\n\n ------- 1.1 | MENU -------");
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
	printf("\n\n ------- 1.2 | MENU -------");
	printf("\n 1 - Playlist aleatoria");
	printf("\n 2 - Playlist pessoal");
	printf("\n 0 - Voltar ao menu anterior\n");
	printf("\n Escolha uma das opC'C5es acima: ");
	scanf("%d",&op);
	return op;
}

int menu1_5() {
	int op;
	printf("\n\n ------- 1.5 | MENU -------");
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
		printf("\n\n ----");
		printf(" Erro ao carregar o arquivo");
		printf("----\n");
		return 0;
	}

	printf("\n\n ----");
	printf(" Arquivo carregado com sucesso!");
	printf("----\n");

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
	return qt;
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
	nNodo->ant=NULL;
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
		no->ant = aux;
	}
}

void mostra_acervo(Desc *acervo) {
	Nodo *aux = acervo->primeiro_nodo;
	if(aux == NULL) {
		printf("\n Acervo vazio!\n");
	} else {
		printf("\n\n --------- Acervo ---------");
		while(aux != NULL) {
			mostra_musica(aux,0);
			aux=aux->prox;
		}
	}
}

void mostra_musica(Nodo *aux, int sinal) {
	if(aux == NULL)
		return;

	printf("\n\n ------------------\n");
	printf("\n Artista: %s",aux->info->artista);
	printf("\n TC-tulo: %s",aux->info->titulo);
	printf("\n Letra: %s",aux->info->letra);
	if(sinal != 1) {
		printf("\n ReproduC'C5es: %d\n",aux->info->execucoes);
		printf(" DCC3digo: %d",aux->info->codigo);
	}
}

void busca_codigo(Desc *acervo, int codigo) {
	if (acervo->primeiro_nodo == NULL) {
		printf("\n Acervo vazio!\n");
		return;
	} else {
		Nodo *aux = acervo->primeiro_nodo;
		while(aux != NULL) {
			if(aux->info->codigo == codigo) {
				mostra_musica(aux,0);
				break;
			} else {
				aux = aux->prox;
			}
		}
		if(aux == NULL) 
			printf("\n Codigo nao encontrado!");
	}
}

void busca_titulo(Desc *acervo, const char *titulo) {
	if (acervo->primeiro_nodo == NULL) {
		printf("\n Acervo vazio!\n");
		return;
	} else {
		Nodo *aux = acervo->primeiro_nodo;
		while(aux != NULL) {
			if(strcmp(aux->info->titulo, titulo) == 0) {
				mostra_musica(aux,0);
				break;
			} else {
				aux = aux->prox;
			}
		}
		if(aux == NULL)
			printf("\n Titulo nao encontrada!");
	}
}

void busca_artista(Desc *acervo, const char *artista) {
	if (acervo->primeiro_nodo == NULL) {
		printf("\nAcervo vazio!\n");
		return;
	} else {
		Nodo *aux = acervo->primeiro_nodo;
		while (aux != NULL) {
			if (strcmp(aux->info->artista, artista) == 0) {
				mostra_musica(aux, 0);
				break;
			}
			aux = aux->prox;
		}
		if(aux == NULL)
			printf("\nArtista nao encontrado!\n");
	}
}
