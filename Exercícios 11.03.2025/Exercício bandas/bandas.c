#include <stdio.h>

enum gen{rock=1, samba, metal, sertanejo, jazz};

typedef struct {
	char nome[30];
	enum gen tipo;
	int rank;
	int integ;
}Band;

void load(Band band[]);
void print(Band band[]);
void ran(Band band[], int r);
void est(Band band[], int g);
void banVeri(Band band[], char ver[20]);

int main() {
	int r,g;
	char genfav[10],ver[20];
	Band band[5];
	load(band);
	print(band);
	printf("\nDigite um numero entre 1 e 5: ");
	scanf("%d",&r);
	ran(band, r);
	printf("\nDigite um numero entre 1 e 5: ");
	scanf("%d", &g);
	est(band, g);
	printf("\nDigite o nome de uma banda: ");
	scanf(" %[^\n]", ver);
	banVeri(band, ver);
	return 0;
}

void load(Band band[]) {
	for(int i=0; i<5; i++) {
		printf("\nDigite o nome de uma banda favorita: ");
		scanf(" %[^\n]", band[i].nome);
		int tipoinf;
		printf("\nSeu estilo musical, dentro desta opcoes: 1 - rock, 2 - samba, 3 - metal, 4 - sertanejo, 5 - jazz: ");
		scanf("%d", &tipoinf);
		band[i].tipo = tipoinf;
		printf("\nQuantidade de membros: ");
		scanf("%d",&band[i].integ);
		printf("\nA posicao dela no seu ranking: ");

		scanf("%d",&band[i].rank);
	}
}

void print(Band band[]) {
	for(int i=0; i<5; i++){
		printf("\nBanda: %s\n",band[i].nome);
		printf("\nQuantidade de integrantes:%d\n", band[i].integ);
        printf("\nLugar no ranking:%d\n",band[i].rank);
		printf("\nEstilo musical: ");
		switch(band[i].tipo) {
			case 1:
				printf("\nrock");
				break;
			case 2:
			   printf("\nsamba");
				break;
			case 3:
			   printf("\nmetal");
				break;
			case 4:
			   printf("\nsertanejo");
				break;
			case 5:
			   printf("\njazz");
				break;
        }
    }
}

void ran(Band band[], int r) {
	for(int i=0; i<5; i++) {
		if(band[i].rank == r) {
			printf("\nBanda: %s\n",band[i].nome);
		printf("\nQuantidade de integrantes:%d\n", band[i].integ);
        printf("\nLugar no ranking:%d\n",band[i].rank);
		printf("\nEstilo musical: ");
		switch(band[i].tipo) {
			case 1:
				printf("\nrock");
				break;
			case 2:
			   printf("\nsamba");
				break;
			case 3:
			   printf("\nmetal");
				break;
			case 4:
			   printf("\nsertanejo");
				break;
			case 5:
			   printf("\njazz");
				break;
		}
	}
}
}

void est(Band band[], int g) {
	printf("Estas são as suas bandas favoritas desse estilo:\n");
	for(int i=0; i<5; i++) {

		if(band[i].tipo == g) {
			printf("\nBanda: %s\n",band[i].nome);
		printf("\nQuantidade de integrantes:%d\n", band[i].integ);
        printf("\nLugar no ranking:%d\n",band[i].rank);
		printf("\nEstilo musical: ");
		switch(band[i].tipo) {
			case 1:
				printf("\nrock");
				break;
			case 2:
			   printf("\nsamba");
				break;
			case 3:
			   printf("\nmetal");
				break;
			case 4:
			   printf("\nsertanejo");
				break;
			case 5:
			   printf("\njazz");
				break;
		}
	}
}
}

void banVeri(Band band[], char ver[20]) {
	int y;
	for(int i=0; i<5; i++) {
		if(strcmp(ver, band[i].nome) == 0) {
			printf("\nEsta banda é uma das suas favoritas.\n");
			y=1;}
		if(y=0) {
			printf("\nEsta banda não está entre as suas favoritas.\n");
		}
	}
}
