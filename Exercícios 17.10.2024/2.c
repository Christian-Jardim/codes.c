#include <stdio.h>

int vet[5],i,sum,j;

int num(){
 printf("Digite 5 números inteiros:\n");
for(i=0;i<5;i++){
 scanf("%i",&vet[i]);
  if(vet[i]<0){
    printf("Número inválido, digite novamente:");
    scanf("%i",&vet[i]);}}
}

int SomaDivisores(){
 for(i=0;i<5;i++){
  for(j=1;j<=vet[i];j++){
   if(vet[i]%j==0){
    sum+=j;
  }
  printf("A soma dos divisores de %i, sem contar o mesmo, é: %i.\n",vet[i],sum);
}
}}

int main()
{

num();
SomaDivisores();

return 0;
}
