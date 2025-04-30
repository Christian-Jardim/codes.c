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
void valida_posicao(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int *code);
void insere(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int *code);
nodo *remover_encontra(desc *playlist, int code1, int code2);
void mostra_musica(nodo *aux);
void mostra_playlist(desc *p);
void toca();
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
      
			printf("Digite o titulo da musica: ");
			scanf(" %[^\n]s",title);
			printf("Digite o nome do artista: ");
			scanf(" %[^\n]s",artist);
			printf("Digite a letra da musica: ");
			scanf(" %[^\n]s",lyrics);
			printf("Informe um codigo para identificar essa musica: ");
			scanf("%d",&code);
			valida_posicao(playlist,node,song,title,artist,lyrics,&code);
			break;
		case 3:
			printf("\nDigite o codigo da musica que quer remover: ");
			scanf("%d",&code);
			nodo *removido = remover_encontra(playlist,code,0);
			break;
		case 4:
			printf("\nDigite o codigo da musica que quer encontrar: ");
			scanf("%d",&code);
			mostra_musica(remover_encontra(playlist,code,1));
			break;
		case 5:
			mostra_playlist(playlist);
			break;
    case 6:
			printf("\nDigite o codigo da musica que quer trocar: ");
			scanf("%d",&code);
			mostra_musica(remover_encontra(playlist,code,1));
			break;
		case 7:
			libera(playlist);
			printf("\nVoce saiu!");
			break;
		default:
			printf("\nOpcao invalida\n");
		}
	} while(op != 7;
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

void valida_posicao(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int *code, int *posicao) {

		node->prox=playlist->primeiro_nodo;
		playlist->primeiro_nodo=node;
		insere(playlist,node,song,title,artist,lyrics,code);
}

void insere(desc *playlist, nodo *node, musica *song, char *title, char *artist, char *lyrics, int *code) {
	node->info = song;
	node->prox = NULL;
	strcpy(song->titulo, title);
	strcpy(song->artista, artist);
	strcpy(song->letra, lyrics);
	song->codigo = *code;
	playlist->tamanho++;
}

nodo *remove(desc *playlist, int code1, int code2) {
	nodo *aux = playlist->primeiro_nodo;
	playlist->primeiro_nodo = playlist->primeiro_nodo->prox;
	playlist->tamanho--;
	return aux;
}



void mostra_playlist(desc *p) {
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
	}
	else {
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
	}
	else {
		printf("\nTitulo da musica: %s",aux->info->titulo);
		printf("\nNome do artista: %s",aux->info->artista);
		printf("\nLetra da musica: %s",aux->info->letra);
		aux->info->execucoes++;
	}
}
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
