#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[30];
	char gen[20];
	int rank;
	int integ;
}Band;

void load(Band band[]) {
	for(i=0; i<5; i++) {
		printf("\nDigite o nome de uma banda favorita, seu estilo musical,\n");
		printf("quantidade de membros e o lugar dela no seu ranking:\n");
		scanf(" %[^\n]", band[i].nome);
		scanf(" %[^\n]", band[i].gen);
		scanf("%i",&band[i].integ);
		scanf("%i",&band[i].rank);
	}
}

int main() {
	Band band[5];
}

void ran(Band band[], r) {
	for(int i=0; i<5; i++) {
		if(band[i].rank == r) {
			printf("\nBanda:%s\n",band[i].nome);
			printf("Estilo musical:%s\n", band[i].gen);
			printf("Quantidade de integrantes:%d\n", band[i].integinteg);
printf("Lugar no ranking:%d\n",band[i].rank);
		}
	}
}

void est(Band band, char fav[10]) {
	char c[10];
	printf("Estas são as suas bandas favoritas desse estilo:\n");
	for(int i=0; i<5; i++) {
		strcpy(c, band[i].gen);
		if(strcmp(c, h) == 0) {
			printf("%s\n",band.x[i]);
		}
	}
}

void ban(Band band, char ver[20]) {
	int y;
	char c[10];
	for(int i=0; i<5; i++) {
		strcpy(c, band.x[i]);
		if(strcmp(c, g) == 0) {
			printf("Esta banda é uma das suas favoritas.");
			y=1;}
		if(y=0) {
			printf("Esta banda não está entre as suas favoritas.");
		}
	}
}