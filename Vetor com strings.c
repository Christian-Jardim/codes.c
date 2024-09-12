/*Receber os valores de dois vetores e, se forem iguais nas mesmas posições, imprimi-los.*/ 

#include <stdio.h>
#include <string.h>
int main(){
int cont,cont2,q,w;
char nome1[11],nome2[11],nome3 [30];

printf("Digite o primeiro nome: ");
scanf("%s",nome1);
printf("Digite o segundo nome: ");
scanf("%s",nome2);

cont=strlen(nome1);
cont2=strlen(nome2);

for(q=0;q<cont;q++){
    nome3[q]=nome1[q];
}
cont2=cont+cont2;
for(q=cont;q<cont2;q++){
    nome3[q]=nome2[w];
    w++;
}
puts(nome3);
return 0;
}
