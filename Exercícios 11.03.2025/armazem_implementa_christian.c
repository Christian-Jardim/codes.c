#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void apresenta1(Item *item, int qt) {
        char p[15];

        printf("\nDigite o nome do produto: ");
        scanf(" %[^\n]", p);

        for(int i=0; i<qt; i++) {
                if(strcmp(p, item[i].nome) == 0) {
                        apresenta(item, i);
                }
        }
}

void apresentaT(Item *item, int qt) {

        for(int i=0; i<qt; i++) {
                apresenta(item, i);
        }
}

int balanco(int qt, Item *item) {
        int i=0,qtp;

        if(i<qt) {
                qtp+=item[i].quant;
        }
        else {
                return qtp;
        }
}

void buscaN(Item *item, int qt) {
        char p[15];

        printf("\nDigite o nome do produto: ");
        scanf(" %[^\n]", p);

        for(int i=0; i<qt; i++) {
                if(strcmp(p, item[i].nome) == 0) {
                        apresenta(item,i);
                }
        }
}

void buscaS(Item *item, int qt) {
        int s;

        printf("\n\n1-hortifruti; 2-bebidas; 3-mercearia; 4-higiene; 5-acougue; 6-laticineos; 7-frios; 8-doces; 9-padaria");
        printf("\nO setor do produto, dentre as opcoes acima: ");
        scanf("%d", &s);

        for(int i=0; i<qt; i++) {
                if(item[i].setor == s) {
                        apresenta(item,i);
                }
        }
}

void venda(Item *item, int qt) {
        char p[15];
        int qv;

        printf("\nDigite o nome do produto que foi vendido: ");
        scanf(" %[^\n]", p);
        printf("\nA quantidade que foi vendida: ");
        scanf("%d", &qv);

        for(int i=0; i<qt; i++) {
                if(strcmp(p, item[i].nome) == 0) {
                        item[i].quant = item[i].quant - qv;
                }
        }
}

int carrega(Item *item) {
    int qt,s;
    FILE *arq;
    if((arq=fopen("armazem_aed.txt", "r"))==NULL) {
                printf("oi");
        }
        else {
                fscanf(arq,"%d\n",&qt);
                for(int i=0; i<qt; i++) {
                        fscanf(arq,"%s\n",item[i].nome);
                        fscanf(arq,"%d\n",&s);
                        item[i].setor = s;
                        fscanf(arq,"%d\n",&item[i].quant);
                        fscanf(arq,"%f\n",&item[i].valor);
                }
        }
        fclose(arq);
        return qt;
}

int gera(int qt, Item *item) {
        FILE *arq;
        if((arq=fopen("armazem_aed.txt", "w"))==NULL) {
                printf("oi");
        }
        else {
                fprintf(arq,"%d\n",qt);
                for(int i=0; i<qt; i++) {
                        fprintf(arq,"%s\n",item[i].nome);
                        fprintf(arq,"%d\n",item[i].setor);
                        fprintf(arq,"%d\n",item[i].quant);
                        fprintf(arq,"%.2f\n",item[i].valor);
                }
        }
        fclose(arq);
} 