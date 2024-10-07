#include <stdio.h>
int main(){

float alunos[2][10],max,min;
int j,pmax,pmin;

printf("Digite os números dos alunos:\n");
for(j=0;j<10;j++){
 scanf("%f",&alunos[0][j]);}

printf("Digite as alturas em metros dos alunos:\n");
for(j=0;j<10;j++){
 scanf("%f",&alunos[1][j]);}

for(j=0;j<9;j++){
 if(alunos[1][j]>alunos[1][j+ 1]){
  if(alunos[1][j]>max){
   max=alunos[1][j];
   pmax=j;}}}
   
for(j=0;j<9;j++){
 if(alunos[1][j]<alunos[1][j+ 1]){
  if(alunos[1][j]<min){
   min=alunos[1][j];
   pmin=j;}}}
   
printf("O aluno com a maior altura é o: %i.\n",alunos[0][pmax]);
printf("%2.f.\n",max);
printf("O aluno com a menor altura é o: %i.\n",alunos[0][pmin]);
printf("%2.f.\n",min);
return 0;
}
