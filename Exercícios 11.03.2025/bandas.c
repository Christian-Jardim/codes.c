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
		scanf(" %[^\n]", band.nome[i]);
		scanf(" %[^\n]", band.gen[i]);
		scanf("%i",&band.x[i]);
		scanf("%i",&rank.x[i]);
	}
}

int main() {
	Band band[5];
}

void ran(Band band[], r) {
	for(int i=0; i<5; i++) {
		if(pos.x[i] == r) {
			printf("\nBanda:%s\n",band.x[i]);
			printf("Estilo musical:%s\n",gen.x[i]);
			printf("Quantidade de integrantes:%d\n",integ.x[i]);
printf("Lugar no ranking:%d\n",pos.x[i]);
		}
	}
}

void est(Band band, char fav[10]) {
	char c[10];
	printf("Estas são as suas bandas favoritas desse estilo:\n");
	for(int i=0; i<5; i++) {
		strcpy(c, gen.x[i]);
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