#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
void valida_posicao(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code, int posicao);
void valida_code(desc *playlist, int *code);
void insere(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code);
nodo *remover_encontra(desc *playlist, int code1, int code2, int code3, int code4);
void mostra_musica(nodo *aux, int code);
void mostra_playlist(desc *playlist);
void toca(nodo *aux);
void ver_tamanho(desc *playlist);
void libera(desc *playlist);

int main() {
	int op,posicao,code;
	char title[256], artist[256], lyrics [256];
	do {
		menu();
		printf("\nEscolha uma das opcoes acima: ");
		scanf("%d", &op);
		switch(op) {
		case 1:
			desc *playlist=cria_desc();
			break;
		case 2:
			nodo *node=cria_nodo();
			musica *song=cria_espaco();

			printf("\nDigite a posicao na qual quer inserir: ");
			scanf("%d",&posicao);
			printf("Digite o titulo da musica: ");
			scanf(" %[^\n]s",title);
			printf("Digite o nome do artista: ");
			scanf(" %[^\n]s",artist);
			printf("Digite a letra da musica: ");
			scanf(" %[^\n]s",lyrics);
			printf("Informe um codigo para identificar essa musica: ");
			scanf("%d",&code);
			valida_code(playlist,&code);
			valida_posicao(playlist,node,song,title,artist,lyrics,code,posicao);
			break;
		case 3:
			printf("\nDigite o codigo da musica que quer remover: ");
			scanf("%d",&code);
			nodo *removido = remover_encontra(playlist,code,0,1,1);
			break;
		case 4:
			printf("\nDigite o codigo da musica que quer encontrar: ");
			scanf("%d",&code);
			mostra_musica(remover_encontra(playlist,code,1,1,1),0);
			break;
		case 5:
			mostra_playlist(playlist);
			break;
		case 6:
			printf("Digite o codigo da musica que quer tocar: ");
			scanf("%d",&code);
			toca(remover_encontra(playlist,code,1,1,1));
			break;
		case 7:
			ver_tamanho(playlist);
			break;
		case 8:
			libera(playlist);
			printf("\nVoce saiu!");
			break;
		default:
			printf("\nOpcao invalida\n");
		}
	} while(op != 8);
	return 0;
}

void menu() {
	printf("\n1 - Criar uma playlist");
	printf("\n2 - Inserir uma musica");
	printf("\n3 - Remover uma musica");
	printf("\n4 - Encontrar uma musica");
	printf("\n5 - Mostrar toda a playlist");
	printf("\n6 - Tocar uma musica");
	printf("\n7 - Ver o tamanho da playlist");
	printf("\n8 - Sair");
}

desc *cria_desc(void) {
	desc *nDesc = (desc *)malloc(sizeof(desc));
	nDesc->tamanho = 0;
	nDesc->primeiro_nodo=NULL;
	return nDesc;
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

void valida_code(desc *playlist, int *code) {
	int c;
	if(remover_encontra(playlist,*code,1,0,0) != NULL) {
		printf("Ja existe uma musica com este codigo, digite outro: ");
		scanf("%d",&c);
		*code = c;
	}
}

void valida_posicao(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code, int posicao) {
	if(playlist->primeiro_nodo == NULL || posicao == 0) {
		node->prox = playlist->primeiro_nodo;
		playlist->primeiro_nodo = node;
		insere(playlist,node,song,title,artist,lyrics,code);
	} else {
		nodo *aux=playlist->primeiro_nodo;
		if(playlist->tamanho < posicao) {
			while(aux->prox != NULL) {
				aux=aux->prox;
			}
			node->prox = aux->prox;
			aux->prox = node;
			insere(playlist,node,song,title,artist,lyrics,code);
		} else {
			nodo *anterior;
			int indice = 0;
			while(aux != NULL) {
				anterior = aux;
				aux = aux->prox;
				indice++;
				if(indice == posicao) {
					node->prox = aux;
					anterior->prox = node;
					insere(playlist,node,song,title,artist,lyrics,code);
				}
			}
		}
	}
}

void insere(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int code) {
	node->info = song;
	strcpy(song->titulo, title);
	strcpy(song->artista, artist);
	strcpy(song->letra, lyrics);
	song->codigo = code;
	playlist->tamanho++;
}

nodo *remover_encontra(desc *playlist, int code1, int code2, int code3, int code4) {
	if (playlist->primeiro_nodo == NULL) {
		if(code4 == 0) {
			return NULL;
		} else {
			printf("\nPlaylis vazia!\n");
			return NULL;
		}
	} else {
		nodo *aux = playlist->primeiro_nodo;
		if (aux->info->codigo == code1) {
			if (code2 == 0) {
				playlist->primeiro_nodo = aux->prox;
				playlist->tamanho--;
				return aux;
			} else {
				return aux;
			}
		} else {
			while (aux->prox != NULL) {
				nodo *anterior = aux;
				aux = aux->prox;
				if (aux->info->codigo == code1) {
					if (code2 == 0) {
						anterior->prox = aux->prox;
						playlist->tamanho--;
						return aux;
					} else {
						return aux;
					}
				}
			}
			if(code3 != 0) {
				printf("\nNao ha musica com esse codigo na playlist!\n");
			}
			return NULL;
		}
	}
}

void mostra_playlist(desc *playlist) {
	nodo *aux=playlist->primeiro_nodo;
	if(aux == NULL) {
		printf("\nPlaylist vazia!\n");
	} else {
		while(aux != NULL) {
			mostra_musica(aux,0);
			aux=aux->prox;
		}
	}
}

void mostra_musica(nodo *aux, int code) {
	if(aux == NULL) {
		return;
	} else {
		printf("\nTitulo da musica: %s",aux->info->titulo);
		printf("\nNome do artista: %s",aux->info->artista);
		printf("\nLetra da musica: %s\n",aux->info->letra);
		if(code != 1) {
			printf("\nCodigo da musica: %d",aux->info->codigo);
			printf("\nQuantidade de reproducoes: %d\n",aux->info->execucoes);
		}
	}
}

void toca(nodo *aux) {
	if(aux == NULL) {
		return;
	} else {
		mostra_musica(aux,1);
		aux->info->execucoes++;
	}
}

void ver_tamanho(desc *playlist) {
	printf("\nA playlist possui %d musica(s)!\n",playlist->tamanho);
}

void libera(desc *playlist) {
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