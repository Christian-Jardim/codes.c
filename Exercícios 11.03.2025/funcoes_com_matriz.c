//Lista 1
//Data
//Christian de Vargas Jardim (christianjardim.aluno@unipampa.edu.br)

#include <stdio.h>

int criaMatriz(int m, int n);

int main() {
	int op,m,n;

	do {
		printf("O que desejas fazer?\n");
		printf("1 - Criar uma matriz\n");
		printf("2 - Ler os elementos de uma matriz\n");
		printf("3 - Receber a soma dos elementos da matriz\n");
		printf("4 - Retornar os elementos de uma determinada coluna da matriz\n");
		printf("5 - Sair do programa\n\n");
		do {
			scanf("%i", &op);
			if (op < 1 && op > 5) {
				printf("Numero invalido, digite novamente: ");
				scanf("%i", &op);
			}
		} while(op < 1 && op > 5);

		switch (op) {
		case 1:
			printf("\nDigite a quantidade de colunas: ");
			scanf("%i", &m);
			printf("Digite a quantidade de linhas: \n");
			scanf("%i", &n);
			*mat = criaMatriz(m, n);
			break;
		case 5:
			return 0;
			break;
		}
	} while(op != 5);
}

int criaMatriz(int m, int n) {
	int mat[m][n],i,j;
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("\nDigite a posicao %i%i da matriz: ", i+ 1,j+ 1);
			scanf("%i", &mat[i][j]);
		}
	}
 return mat
}
