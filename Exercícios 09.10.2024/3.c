/*Programa que lẽ uma matriz 3 x 6 com valores reais e:

(a) Imprime a soma de todos os elementos das colunas ímpares.

(b) Imprime a média aritmética dos elementos da segunda e quarta colunas.

(c) Substitui os valores da sexta coluna pela soma dos valores das colunas 1 e 2.

(d) Imprime a matriz modificada*/

#include <stdio.h>
int main()
{
int mat[3][6],i,j,sum;

printf("Digite os valores da matriz: \n");
for(i=0;i<3;i++){
 for(j=0;j<6;j++){
  scanf("%i",&mat[i][j]);
 }
}

printf("A soma dos elementos das colunas ímpares são: %i\n",
mat[0][1]+mat[0][3]+mat[0][5]+mat[1][1]+mat[1][3]+mat[1][5]+
mat[2][1]+mat[2][3]+mat[2][5]);

printf("A média dos elementos da segunda e quarta coluna é: %i\n",
(mat[0][1]+mat[0][3]+mat[1][1]+mat[1][3]+mat[2][1]+mat[2][3])/6);

sum=mat[0][1]+mat[0][2]+mat[1][1]+mat[1][2]+mat[2][1]+mat[2][2];
mat[0][5]=mat[1][5]=mat[2][5]=sum;

for(i=0;i<3;i++){
 for(j=0;j<6;j++){
  printf("%i",mat[i][j]);
 }
 printf("\n");
}

return 0;
}
