#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
void cria_posicao(pilha *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int *code);
void insere(pilhq *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int *code);
nodo *remover(pilha *playlist);
nodo *encontrar(pilha *playlist, int code);
void mostra_musica(nodo *aux);
void mostra_playlist(pilha *p);
void toca(nodo *aux);
void libera(pilha *playlist);

int main() {
	int op,posicao,code;
	char title[256], artist[256], lyrics [256];
	do {
		menu();
		printf("\nEscolha uma das opcoes acima: ");
		scanf("%d", &op);
		switch(op) {
		case 1:
			pilha *playlist=cria_pilha();
			break;
		case 2:
			nodo *node=cria_nodo();
			musica *song=cria_espaco();

			printf("\nDigite o titulo da musica: ");
			scanf(" %[^\n]s",title);
			printf("Digite o nome do artista: ");
			scanf(" %[^\n]s",artist);
			printf("Digite a letra da musica: ");
			scanf(" %[^\n]s",lyrics);
			printf("Informe um codigo para identificar essa musica: ");
			scanf("%d",&code);
			cria_posicao(playlist,node,song,title,artist,lyrics,&code);
			break;
		case 3:
			remover(playlist);
			break;
		case 4:
			printf("\nDigite o codigo da musica que quer encontrar: ");
			scanf("%d",&code);
			mostra_musica(encontrar(playlist,code));
			break;
		case 5:
			mostra_playlist(playlist);
			break;
		case 6:
			printf("\nDigite o codigo da musica que quer trocar: ");
			scanf("%d",&code);
			mostra_musica(encontrar(playlist,code));
			break;
		case 7:
			libera(playlist);
			printf("\nVoce saiu!");
			break;
		default:
			printf("\nOpcao invalida\n");
		}
	} while(op != 7);
	return 0;
}

void menu() {
	printf("\n1 - Criar uma playlist");
	printf("\n2 - Inserir uma musica");
	printf("\n3 - Remover uma musica");
	printf("\n4 - Encontrar uma musica");
	printf("\n5 - Mostrar toda a playlist");
	printf("\n6 - Tocar uma musica");
	printf("\n7 - Sair");
}

pilha *cria_desc(void) {
	desc *nPilha = (pilha *)malloc(sizeof(pilha));
	nPilha->tamanho = 0;
	nPilha->primeiro_nodo=NULL;
	return nPilha;
}

nodo *cria_nodo(void) {
	nodo *nNodo=(nodo *)malloc(sizeof(nodo));
	nNodo->prox=NULL;
	nNodo->info=NULL;
	return nNodo;
}

musica *cria_espaco(void) {
	musica *nMusica = (musica*)malloc(sizeof(musica));
	return nMusica;
}

void cria_posicao(pilha *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int *code) {
	node->prox=playlist->primeiro_nodo;
	playlist->primeiro_nodo=node;
	insere(playlist,node,song,title,artist,lyrics,code);
}

void insere(pilha *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int *code) {
	node->info = song;
	strcpy(song->titulo, title);
	strcpy(song->artista, artist);
	strcpy(song->letra, lyrics);
	song->codigo = *code;
	playlist->tamanho++;
}

nodo *remover_encontra(pilha *playlist, int code, sinal1, int sinal2, int sinal3) {
        if (playlist->primeiro_nodo == NULL) {
                if(sinal3 == 0) {
                        return NULL;
                } else {
                        printf("\nPlaylis vazia!\n");
                        return NULL;
                }
        } else {
                nodo *aux = playlist->primeiro_nodo;
                if (aux->info->codigo == code) {
                        if (sinal1 == 0) {
                                playlist->primeiro_nodo = aux->prox;
                                playlist->tamanho--;
                                return aux;
                        } else {
                                return aux;
                        }
                } else {
                        while (aux->prox != NULL) {
                                if (aux->prox->info->codigo == code) {
                                        if (sinal1 == 0) {
                                                aux->prox = aux->prox->prox;
                                                playlist->tamanho--;
                                                return aux;
                                        } else {
                                                return aux;
                                        }
                                }
                                aux = aux->prox;
                        }
                        if(sinal2 != 0) {
                                printf("\nNao ha musica com esse codigo na playlist!\n");
                        }
                        return NULL;
                }
        }
}

void mostra_playlist(pilha *p) {
	nodo *aux=p->primeiro_nodo;
	if(aux == NULL) {
		printf("\nPlaylist vazia!\n");
	} else {
		while(aux != NULL) {
			mostra_musica(aux);
			aux=aux->prox;
		}
	}
}

void mostra_musica(nodo *aux) {
	if(aux == NULL) {
		printf("Nao ha musica com este codigo na playlist!\n");
	} else {
		printf("\nTitulo da musica: %s",aux->info->titulo);
		printf("\nNome do artista: %s",aux->info->artista);
		printf("\nLetra da musica: %s",aux->info->letra);
		printf("\nCodigo da musica: %d",aux->info->codigo);
		printf("\nQuantidade de reproducoes: %d\n",aux->info->execucoes);
	}
}

void toca(nodo *aux) {
	if(aux == NULL) {
		printf("Nao ha musica com este codigo na playlist!\n");
	} else {
		printf("\nTitulo da musica: %s",aux->info->titulo);
		printf("\nNome do artista: %s",aux->info->artista);
		printf("\nLetra da musica: %s",aux->info->letra);
		aux->info->execucoes++;
	}
}

void libera(pilha *playlist) {
	nodo *aux = playlist->primeiro_nodo;
	nodo *anterior;
	while(aux != NULL) {
		anterior = aux;
		aux = aux->prox;
		free(anterior);
	}
	free(aux);
	playlist->primeiro_nodo = NULL;
	playlist->tamanho = 0;
}
