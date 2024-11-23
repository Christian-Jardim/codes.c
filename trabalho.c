#include <stdio.h>
#include <string.h>
int q, voto, vb, vn, vt, votos[50];
struct Cand {
	char nome[50][30];
	int cod[50];
} cand;

void regis() {
	printf("Digite a quantidade de candidatos: ");
	scanf("%i",&q);
	for(int i=0; i<q; i++) {
		printf("\nDigite o nome de um candidato: ");
		scanf(" %[^\n]",cand.nome[i]);
		printf("Agora o seu numero: ");
		scanf("%i",&cand.cod[i]);
	}
}

void ord() {
	int i, a;
	char aux[30];
	for(int j=0; j<q; j++) {
		for(int i=1; i<q; i++) {
			if(strcmp(cand.nome[i- 1], cand.nome[i])>0) {
				strcpy(aux, cand.nome[i- 1]);
				strcpy(cand.nome[i- 1], cand.nome[i]);
				strcpy(cand.nome[i], aux);
				a=cand.cod[i- 1];
				cand.cod[i- 1]=cand.cod[i];
				cand.cod[i]=a;
			}
		}
	}
}
void vot() {
	int m;
	while(voto >=0) {
		m=0;
		for(int i=0; i<q; i++) {
			printf("\nVote em %s:%i",cand.nome[i], cand.cod[i]);
		}
		printf("\nVoto em branco: 0");
		printf("\nPara encerrar, digite qualquer valor negativo.\n");
		printf("Sua escolha: ");
		scanf("%i",&voto);
		if(voto == 0)
			vb++;
		else {
			for(int i=0; i<q; i++) {
				if(voto == cand.cod[i]) {
					votos[i]++;
					m=1;
				}
			}
			if(m==0 && voto >0)
				vn++;
		}
		vt++;
	}
}
void file(){
    FILE *arq;
    arq = fopen("votacao.txt", "w");
    fprintf(arq,"Totais de votos: %i\n",vt);
    for(int i=0; i<q; i++){
        fprintf(arq, "%s: %i votos.\n",cand.nome[i], votos[i]);
    }
    fprintf(arq, "Votos em branco: %i",vb);
	fprintf(arq, "\nVotos nulos: %i",vn);
	fprintf(arq, "\nPorcentagem de votos em branco sobre o total de votos: %d%%",(vb*100)/vt);
	fprintf(arq, "\nPorcentagem de votos nulos sobre o total de votos: %d%%",(vn*100)/vt);
    fclose(arq);
	
}
int main() {

	regis();
	ord();
	vot();
    	vt-=1;
	printf("Totais de votos:%i\n",vt);
	for(int i=0; i<q; i++) {
		printf("%s:%i votos.\n",cand.nome[i], votos[i]);
	}
	printf("Votos em branco:%i",vb);
	printf("\nVotos nulos:%i",vn);
	printf("\nPorcentagem de votos em branco sobre o total de votos:%d%%",(vb*100)/vt);
	printf("\nPorcentagem de votos nulos sobre o total de votos:%d%%",(vn*100)/vt);
	file();
	return 0;
}
