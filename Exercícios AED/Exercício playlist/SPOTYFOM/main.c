#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "spotyfom.h"

int main() {
	int op1,op2,op3,codigo;
	char titulo[256],artista[256];

	Lista *acervo=NULL;
	Fila *fila=NULL;
	Pilha *pilha=NULL;

	srand(time(NULL));

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
								printf(" \nInforme o codigo: ");
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
							case 1: // Executa a playlist aleatoria
								executa_fila(acervo,fila);
								break;
							case 2: // Executa a playlist pessoal
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
								printf(" \nInforme o titulo da musica: ");
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
