#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[30];
	char gen[20];
	int rank;
	int integ;
}Band;


int main() {
	Band band[5];
}

void ran(int r) {
	for(int i=0; i<5; i++) {
		if(pos.x[i] == r) {
			printf("\nBanda:%s\n",band.x[i]);
			printf("Estilo musical:%s\n",gen.x[i]);
			printf("Quantidade de integrantes:%d\n",integ.x[i]);
printf("Lugar no ranking:%d\n",pos.x[i]);
		}
	}
}

void est(char h[10]) {
	char c[10];
	printf("Estas são as suas bandas favoritas desse estilo:\n");
	for(int i=0; i<5; i++) {
		strcpy(c, gen.x[i]);
		if(strcmp(c, h) == 0) {
			printf("%s\n",band.x[i]);
		}
	}
}

void ban(char g[20]) {
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