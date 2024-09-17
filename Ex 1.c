/*Receber um valor maior que 10 e imprimir todos os números pares
entre 1 e ele.*/

#include <stdio.h>
int main() {

int valor,pares;

printf("Digite um número maior que 10: ");
scanf("%d",&valor);

if(valor>10){
    printf("Estes são todos os números pares até %d:\n",valor);

    for(pares = 2;pares<=valor;pares+=2){
       printf("%d\n",pares);
}
}
else{
    printf("Número inválido.");
}
return 0;
}
