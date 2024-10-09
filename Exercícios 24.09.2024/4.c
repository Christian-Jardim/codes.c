/*Programa que lẽ dez conjuntos de dois valores, o primeiro representando
o número do aluno e o segundo representando a sua altura em metros.
Encontra o aluno mais baixo e o mais alto e mostre o nú́mero do aluno
mais baixo e do mais alto, juntamente com suas alturas.*/

#include <stdio.h>
int main(){

float num[10],alt[10],max,min;
int j,pmax,pmin;

printf("Digite os números dos alunos:\n");
for(j=0;j<10;j++){
 scanf("%f",&num[j]);}

printf("Digite as alturas em metros dos alunos:\n");
for(j=0;j<10;j++){
 scanf("%f",&alt[j]);}

for(j=0;j<10;j++){
 if(alt[j]>max){
  max=alt[j];
  pmax=j;}}

min=max;  
for(j=0;j<10;j++){
 if(alt[j]<min){
   min=alt[j];
   pmin=j;
  }
 }
   
printf("O aluno com a maior altura é o: %1.f.\n",num[pmax]);
printf("%2.f.\n",max);
printf("O aluno com a menor altura é o: %1.f.\n",num[pmin]);
printf("%2.f.\n",min);

return 0;
}
