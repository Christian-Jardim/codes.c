#include <stdio.h>
#include <string.h>

enum{};

typedef struct {
	char nome[30];
	enum gen;
	int rank;
	int integ;
	int tipo;
}Band;

void load(Band band[]);
void print(Band band[]);
void ran(Band band[], int r);
void est(Band band[], char genfav[10]);
void ban()Band band[], char ver[20]);

int main() {
	Band band[5];
}

void load(Band band[]) {
	for(i=0; i<5; i++) {
		printf("\nDigite o nome de uma banda favorita: ");
		scanf(" %[^\n]", band[i].nome);
		printf("\nSeu estilo musical: ");
		scanf(" %[^\n]", band[i].gen);
		printf("\nQuantidade de membros: );
		scanf("%d",&band[i].integ);
		printf("\nA posicao dela no seu ranking: ");
		scanf("%d",&band[i].rank);
	}
}

void print(Band band) {
	for(int i=0; i<5; i++){
		printf("\nBanda:%s\n",band[i].nome);
			printf("Estilo musical: %s\n", band[i].tipo);
			printf("Quantidade de integrantes:%d\n", band[i].integ);
printf("Lugar no ranking:%d\n",band[i].rank);
}

void ran(Band band[], int r) {
	for(int i=0; i<5; i++) {
		if(band[i].rank == r) {
			printf("\nBanda:%s\n",band[i].nome);
			printf("Estilo musical: %s\n", band[i].tipo);
			printf("Quantidade de integrantes:%d\n", band[i].integ);
printf("Lugar no ranking:%d\n",band[i].rank);
		}
	}
}

void est(Band band[], char genfav[10]) {
	printf("Estas são as suas bandas favoritas desse estilo:\n");
	for(int i=0; i<5; i++) {
		if(strcmp(genfav, band[i].tipo) == 0) {
			printf("%s\n",band.x[i]);
		}
	}
}

void ban(Band band[], char ver[20]) {
	int y;
	for(int i=0; i<5; i++) {
		if(strcmp(ver, band[i].nome) == 0) {
			printf("Esta banda é uma das suas favoritas.");
			y=1;}
		if(y=0) {
			printf("Esta banda não está entre as suas favoritas.");
		}
	}
}