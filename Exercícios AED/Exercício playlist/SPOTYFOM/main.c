#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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

int menu1();
int menu2();

Desc *carrega(Desc *acervo);

Desc *cria_desc();
Nodo *cria_nodo();
Musica *cria_campo();

void insere(Desc *acervo, Nodo *no);
void mostra_musica(Nodo *aux, int sinal);
void mostra_acervo(Desc *acervo);
Nodo *encontra(Desc *playlist, char titulo[20]);
int main() {

	int op;
	Desc *acervo=NULL;

	do {
		op = menu1();
		switch(op) {
		case 1:
			do {
				acervo=carrega(acervo);
				op = menu2();
				switch(op) {
				case 1:

					break;
				case 2:

					break;
				case 3:

					break;
				case 4:
					switch(op) {
					case 1:

					}
					break;
				case 5:

					break;
				default:
					printf("\n Opcao invalida\n");
				}
			} while(op != 0);;
			break;
		case 0:
			printf("\n Voce saiu!");
			break;
		default:
			printf("\n Opcao invalida\n");
		}
	} while(op != 0);

	return 0;
}

int menu1() {
	int op;
	printf("\n 1 - Carregar arquivo de musicas");
	printf("\n 0 - Sair");
	printf("\n Escolha uma das opcoes acima: ");
	scanf("%d",&op);
	return op;
}

int menu2() {
	int op;
	printf("\n 1 - BUSCA");
	printf("\n 2 - PLAYLIST");
	printf("\n 3 - EXECUCAO");
	printf("\n 4 - IMPRESSAO");
	printf("\n 5 - RELATORIO");
	printf("\n 0 - Voltar ao menu anterior");
	printf("\n Escolha uma das opcoes acima: ");
	scanf("%d",&op);
	return op;
}

Desc *carrega(Desc *acervo) {

	int qt;
	char arquivo[20], linha[100];

	printf("\n Nome do arquivo: ");
	scanf("%s", arquivo);
	FILE *arq = fopen(arquivo, "r");

	if(arq == NULL) {
		printf("\n Erro ao carregar o arquivo");
	} else {
		acervo=cria_desc();

		fscanf(arq,"%d\n",&qt);
		while(qt > 0) {
			Nodo *no=cria_nodo();
			Musica *musica=cria_campo();
			no->info = musica;

			// Remover o \n do final, se houver
			linha[strcspn(linha, "\n")] = 0;

			// Separar com strtok
			char *token = strtok(linha, ";");
			if (token != NULL)
				strcpy(musica->artista, token);

			token = strtok(NULL, ";");
			if (token != NULL)
				strcpy(musica->titulo, token);

			token = strtok(NULL, ";");
			if (token != NULL)
				strcpy(musica->letra, token);

			token = strtok(NULL, ";");
			if (token != NULL)
				musica->execucoes = atoi(token);

			token = strtok(NULL, ";");
			if (token != NULL)
				musica->codigo = atoi(token);

			insere(acervo,no);
			qt--;
		}
		fclose(arq);
	}
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
		while(aux != NULL) {
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
		while(aux != NULL) {
			mostra_musica(aux,0);
			aux=aux->prox;
		}
	}
}

void mostra_musica(Nodo *aux, int sinal) {
	if(aux == NULL) {
		printf(" Nao ha musica com este codigo na playlist!\n");
	}
	else {
		printf("\n Nome do artista: %s",aux->info->artista);
		printf("\n Titulo da musica: %s",aux->info->titulo);
		printf("\n Letra da musica: %s\n",aux->info->letra);
		if(sinal != 1) {
			printf("\n Quantidade de reproducoes: %d\n",aux->info->execucoes);
			printf("\n Codigo da musica: %d",aux->info->codigo);
		}
	}
}

Nodo *encontra(Desc *acervo, char titulo[20]) {
	if (acervo->primeiro_nodo == NULL) {
		printf("\n Acervo vazio!\n");
		return NULL;
	} else {
		Nodo *aux = acervo->primeiro_nodo;
		while(aux != NULL) {
			if(strcmp(aux->info->titulo, titulo) == 0) {
				return aux;
			} else {
				aux = aux->prox;
			}
		}
	}
}
