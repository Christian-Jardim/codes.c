#include <stdio.h>

int main() {
	FILE *arq;
	char cont[100];
	if((arq = fopen("votacao.txt", "r")) == NULL) {
		printf("Erro ao tentar abrir o arquivo.");
		return 0;
	}
	else {
		while(fgets(cont, 100, arq) != NULL) {
			printf("%s",cont);
		}
	}
	fclose(arq);
	return 0;
}
