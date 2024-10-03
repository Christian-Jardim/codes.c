#include <stdio.h>
#include <string.h>
int main()
{

int i,j,sum,n1;
char a1[3][5],a2[3][5],a3[3][5],g[2][5]={ a, d, b, d, d, b, c, a, c, d};

printf("Digite os cinco números da matrícula e as respostas do aluno 1:\n");
for(i=0;i<3;i++){
 for(j=0;j<5;j++){
  scanf("%c",&a1[i][j]);
 }
}
printf("Digite os cinco números da matrícula e as respostas do aluno 3:\n");
for(i=0;i<3;i++){
 for(j=0;j<5;j++){
  scanf("%c",&a2[i][j]);
 }
}
printf("Digite os cinco números da matrícula e as respostas do aluno 3:\n");
for(i=0;i<3;i++){
 for(j=0;j<5;j++){
  scanf("%c",&a3[i][j]);
 }
}

for(i=1;i<2;i++){
 for(j=0;j<5;j++){
  if(a1[i][j]==g[i- 1][j]){
   n1++;
  }
 }
}
printf("%i",n1);
return 0;
}
