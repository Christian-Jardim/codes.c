/*Programa que lê 5 números inteiros positivos (uma função que leia esse número
e verifica se ele é positivo). Para cada número informado escrever a soma de seus
divisores (exceto ele mesmo). Utiliza a função SomaDivisores para obter a soma.*/

#include <stdio.h>

int vet[5],i,sum,j;

int num(){
printf("Digite 5 números inteiros:\n");
for(i=0;i<5;i++){
 scanf("%i",&vet[i]);
  if(vet[i]<0){
    printf("Número inválido, digite novamente:");
    scanf("%i",&vet[i]);}}}

int SomaDivisores(){
 for(i=0;i<5;i++){
 sum=0;
 for(j=1;j<vet[i];j++)
  if(vet[i]%j==0){
  sum+=j;}
 printf("A soma dos divisores de %i, sem contar o memsmo, é %i.\n",vet[i],sum);}}
 
int main(){

num();
SomaDivisores();

return 0;}
