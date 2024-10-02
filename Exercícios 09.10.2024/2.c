/*Programa que permite ao usuário entrar com uma matriz de 3 x 3 nu ́meros inteiros. Em seguida, gera um array unidimensional
pela soma dos nu ́meros de cada coluna da matriz e mostra na tela esse array.*/

#include <stdio.h>
int main()
{

int mat[3][3],i,j,somac,soma[3];

 printf("Digites os números da matriz: \n");
for(i=0;i<3;i++){
 for(j=0;j<3;j++){
  scanf("%i",&mat[i][j]);
 }
}

for(i=0;i<3;i++){
 for(j=0;j<3;j++){
  printf("%i",mat[i][j]);
 }
 printf("\n");
}
 
soma[0]=mat[0][0]+mat[1][0]+mat[2][0];
soma[1]=mat[0][1]+mat[1][1]+mat[2][1];
soma[2]=mat[0][2]+mat[1][2]+mat[2][2];

 for(i=0;i<3;i++){
 printf("%i",soma[i]);
}
 
return 0;
}
