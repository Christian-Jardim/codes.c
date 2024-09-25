/*Calcular a soma da progressão: 1+1/2+1/3+...+1/n.*/

#include <stdio.h>
int main(){

float soma,num,dnm;

printf("Vamos realizar a soma da progressão: 1+1/2+...+1/n.\n");
printf("Digite um número inteiro e positivo: ");
scanf("%f",&num);

if(num>=1){
    printf("Os termos são: \n1\n");
    for (dnm=2;dnm<=num;dnm++){
        soma+=(1/dnm);
        printf("1/%2.f.\n",dnm);
    }
    soma+=1;
    printf("A soma dos termos é: %f",soma);
}
else{
    printf("Número inválido.\n");
}

return 0;
}
