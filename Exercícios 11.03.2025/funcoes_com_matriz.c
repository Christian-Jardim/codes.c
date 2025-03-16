//Lista 1
//Data
//Christian de Vargas Jardim (christianjardim.aluno@unipampa.edu.br)

#include <stdio.h>
#include <stdlib.h>

int **criaMatriz(int m, int n);
void leiaMatriz(int **mat, int m, int n);
void imprimeMatriz(int **mat, int m, int n);
int somaMatriz(int **mat, int m, int n);
int *colunaMat(int **mat, int m, int ncoluna);
void imprimeVet(int *vet, int n);
void liberaVet(int *vet);
void liberaMatriz(int **mat, int m);

int main() {
	int op,m,n,**mat=NULL,sum,*vet,ncoluna;

	do {
		printf("\nO que desejas fazer?\n");
		printf("1 - Criar uma matriz\n");
		printf("2 - Ler os elementos de uma matriz\n");
		printf("3 - Imprimir a matriz\n");
		printf("4 - Receber a soma dos elementos da matriz\n");
		printf("5 - Retornar os elementos de uma determinada coluna da matriz\n");
		printf("6 - Sair do programa\n\n");
		scanf("%i", &op);
		
		do {
			if (op < 1 || op > 6) {
				printf("\nNumero invalido, digite novamente: ");
				scanf("%i", &op);
			}
		} while(op < 1 || op > 6);

		switch (op) {
		case 1:
			printf("\nDigite a quantidade de linhas: ");
			scanf("%i", &m);
			printf("Digite a quantidade de colunas: ");
			scanf("%i", &n);
			printf("\n");
			mat = criaMatriz(m, n);
			break;
		case 2:
			leiaMatriz(mat, m, n);
			break;
		case 3:
			imprimeMatriz(mat, m, n);
			break;
		case 4:
			sum = somaMatriz(mat, m, n);
			printf("\nA soma dos elementos da matriz e: %i\n", sum);
			break;
		case 5:
			printf("\nDigite qual coluna voce quer: ");
			scanf("%i", &ncoluna);
			vet = colunaMat(mat, m, ncoluna);
			imprimeVet(vet, m);
			break;
		case 6:
			liberaVet(vet);
			liberaMatriz(mat, m);
			return 0;
			break;
		}
	} while(op != 6);
}

int **criaMatriz(int m, int n) {
	int **mat,i,j;
	mat = malloc(sizeof (int*)*m);
	for (i=0; i < m; i++) {
		mat[i] = malloc(sizeof (int)*n);
	}
	return mat;
}

void leiaMatriz(int **mat, int m, int n) {
	int i, j;
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("\nDigite a posicao %i%i da matriz: ", i+ 1,j+ 1);
			scanf("%i", &mat[i][j]);
		}
	}
}

void imprimeMatriz(int **mat, int m, int n) {
	int i, j;
	printf("\n");
	printf("\n");
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf("%i  ",mat[i][j]);
		}
		printf("\n");
	}
}

int somaMatriz(int **mat, int m, int n) {
	int i, j, sum=0;

	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			sum+=mat[i][j];
		}
	}
	return sum;
}

int *colunaMat(int **mat, int m, int ncoluna) {
	int *vet,i;
	vet = malloc(sizeof(int*)*m);
	for(i=0; i<m; i++) {
		vet[i] = mat[i][ncoluna - 1];
	}
	return vet;
}

void imprimeVet(int *vet, int m) {
	int i;
	printf("\n");
	for(i=0; i<m; i++) {
		printf("%i  ", vet[i]);
	}
	printf("\n");
}

void liberaVet(int *vet) {
	free(vet);
}

void liberaMatriz(int **mat, int m) {
	int i;
	for(i=0; i<m; i++) {
		free (mat[i]);
	}
	free(mat);
}
