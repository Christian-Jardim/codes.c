/*Receber um valor maior que 10 e imprimir todos os nÃºmeros pares
entre 1 e ele.*/

#include <stdio.h>
int main() {

int valor,pares;

printf("Digite um nÃºmero maior que 10: ");
scanf("%d",&valor);

if(valor>10){
    printf("Estes sÃ£o todos os nÃºmeros pares atÃ© %d:\n",valor);

    for(pares = 2;pares<=valor;pares+=2){
       printf("%d\n",pares);
}
}
else{
    printf("NÃºmero invÃ¡lido.");
}
return 0;
}
