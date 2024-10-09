/*Programa que possui um vetor denominado A que armazena 6 números inteiros. O programa executa os seguintes passos:
(a) Atribui os seguintes valores a esse vetor: 1, 0, 5, -2, -5, 7.
(b) Armazena em uma variável inteira (simples) a soma entre os valores das posiçõesA[0], A[1] e A[5] do vetor e mostra na tela esta soma.
(c) Modifica o vetor na posição 4, atribuindo a esta posição o valor 100.
(d) Mostra na tela cada valor do vetor A, um em cada linha*/

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
