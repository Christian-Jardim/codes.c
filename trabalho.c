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
		printf("Digite o nome de um candidato: ");
		scanf(" %[^\n]",cand.nome[i]);
		printf("Agora o seu numero: ");
		scanf("%i",&cand.cod[i]);
	}
}

void ord() {
	int i, a;
	char aux[30];
	i=strcmp(cand.nome[1], cand.nome[0]);
	if(i<0) {
		strcpy(aux, cand.nome[0]);
		strcpy(cand.nome[0], cand.nome[1]);
		strcpy(cand.nome[1], aux);
		a=cand.cod[0];
		cand.cod[0]=cand.cod[1];
		cand.cod[1]=a;
	}
}

void vot() {
	while(voto >=0) {
		for(int i=0; i<q; i++) {
			printf("\nVote em %s:%i",cand.nome[0], cand.cod[0]);
			printf("\nVoto em branco: 0");
			printf("\nPara encerrar votaC'C#o, digite qualquer valor negativo.\n");
			printf("Sua escolha: ");
			scanf("%i",&voto);
			if(voto==0)
				vb++;
			else {
				for(i=0; i<q; i++) {
					if(voto == cand.cod[i])
						votos[i]++;
					if(voto !=0 && voto != votos[i])
						vn++;
				}
			}
			vt++;
		}
	}
}

int main() {

	regis();
	ord();
	vot();

	printf("Totais de votos:%i\n",vt);
	for(int i=0; i<q; i++) {
		printf("%s:%i votos.\n",cand.nome[i], votos[i]);
	}
	printf("Votos em branco:%i",vb);
	printf("\nVotos nulos:%i",vn);
	printf("\nPorcentagem de votos em branco sobre o total de votos:%d%%",(vb*100)/vt);
	printf("\nPorcentagem de votos nulos sobre o total de votos:%d%%",(vn*100)/vt);
	return 0;
}
