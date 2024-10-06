#include <stdio.h>

int main()
{
int A[6]={1,0,5,-2,-5,7},sum,i;

printf("A soma dos valores das posições 1, 2 e 6 é: %i\n",
sum=A[0]+A[1]+A[5]);

A[4]=100;

printf("Os valoresdo vetor são:\n");
for(i=0;i<6;i++){
 printf("%i\n",A[i]);
}

return 0;
}
