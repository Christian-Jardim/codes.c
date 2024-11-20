#include <stdio.h>
#include <string.h>
struct Cand {
	char c1[30], c2[30];
	int n1, n2;
}cand;


void comp(char x[30], char y[30]){
    int i;
    char aux[30];
    i=strcmp(y, x);
    if(i>0){
       strcpy(aux,);
       x=y;
       y=aux;
    }
}

int main(){
	int voto, v1, v2, vb;

	printf("Digite o nome do primeiro candidato: ");
	scanf(" %[^\n]",cand.c1);
	printf("Agora o seu dígito: ");
	scanf("%i",&cand.n1);
	printf("\nDigite o nome do segundo candidato: ");
	scanf(" %[^\n]",cand.c2);
	printf("Agora o seu dígito: ");
	scanf("%i",&cand.n2);
	
	comp(cand.n1, cand.n2);

	
    printf("%i\n",v1);
    printf("%i",v2);
    return 0;
}
