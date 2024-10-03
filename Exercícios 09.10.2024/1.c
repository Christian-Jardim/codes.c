/*Programa para corrigir uma prova com 10 questões de múltipla escolha (a, b, c, d ou e),
em uma turma com 3 alunos. Cada questão vale 1 ponto. Leia o gabarito, e para cada aluno leia
sua matricula (número inteiro) e suas respostas. Calcule e escreva para cada aluno:
sua matrícula, suas respostas,sua nota e o percentual de aprovação.*/

#include <stdio.h>
#include <string.h>
int main()
{

int i,j,n1=1,n2=1,n3=1,mat1,mat2,mat3;
char a1[2][5], a2[2][5], a3[2][5], g[2][5] = {'a','d','b','d','d','b','c','a','c','d'};

printf("Digite a matrícula do primeiro aluno:");
scanf("%i",&mat1);
printf("Digite as respostas do aluno:\n");
for(i=0;i<2;i++){
 for(j=0;j<5;j++){
  scanf("%s",&a1[i][j]);
 }
}
printf("\nDigite a matrícula do segundo aluno:");
scanf("%i",&mat2);
printf("Digite as respostas do aluno:\n");
for(i=0;i<2;i++){
 for(j=0;j<5;j++){
  scanf("%s",&a2[i][j]);
 }
}
printf("\nDigite a matrícula do terceiro aluno:");
scanf("%i",&mat3);
printf("Digite as respostas do aluno:\n");
for(i=0;i<2;i++){
 for(j=0;j<5;j++){
  scanf("%s",&a3[i][j]);
 }
}

for(i=0;i<2;i++){
 for(j=0;j<5;j++){
  if(a1[i][j] == g[i][j]){
   n1++;
  }
 }
}
for(i=0;i<2;i++){
 for(j=0;j<5;j++){
  if(a2[i][j] == g[i][j]){
   n2++;
  }
 }
}
for(i=0;i<2;i++){
 for(j=0;j<5;j++){
  if(a3[i][j] == g[i][j]){
   n3++;
  }
 }
}

printf("\nAluno com número de matrícula: %i\nRespostas:\n",mat1);
for(i=0;i<2;i++){
 for(j=0;j<5;j++){
  printf("%c",a1[i][j]);
 }
 printf("\n");
}
printf("Nota:%i\n%i%% de aprovação.\n*********************\n",n1,n1*10);

printf("\nAluno com número de matrícula: %i\nRespostas:\n",mat2);
for(i=0;i<2;i++){
 for(j=0;j<5;j++){
  printf("%c",a2[i][j]);
 }
 printf("\n");
}
printf("Nota:%i\n%i%% de aprovação.\n*********************\n",n2,n2*10);

printf("\nAluno com número de matrícula: %i\nRespostas:\n",mat3);
for(i=0;i<2;i++){
 for(j=0;j<5;j++){
  printf("%c",a3[i][j]);
 }
 printf("\n");
}
printf("Nota:%i\n%i%% de aprovação.\n*********************\n",n3,n3*10);
return 0;
}
