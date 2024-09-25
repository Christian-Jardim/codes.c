/*Calcular a potencia de 'a' por 'b'*/

#include <stdio.h>
int main(){

int bas,expo,cont,resul=1;

printf("Digite um valor para a base: ");
scanf("%i",&bas);
printf("Digite um valor para o expoente: ");
scanf("%i",&expo);

if(bas>=1 || expo>=1){
    for (cont=1;cont<=expo;cont++){
        resul*=bas;
    }
    printf("A função %i^%i é igual a: %i.",bas,expo,resul);
}
else{
    printf("Número inválido.\n");
}

return 0;
}
