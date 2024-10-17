/*Função potẽncia (base, expoente) que, quando chamada, retorna base elevado no expoente.
Assumindo que expoente é um inteiro maior ou igual a 1.*/

#include <stdio.h>

int fun1(int x, int y){
 int i,r;
 r=x;
 for(i=1;i<y;i++){
  r=r*x;
 }
 printf("%i",r);
}

int main()
{
int x,y;
printf("Digite o valor da base: ");
scanf("%i",&x);

printf("Digite o valor do expoente: ");
scanf("%i",&y);

fun1(x,y);

return 0;
}
