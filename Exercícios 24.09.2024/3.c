#include <stdio.h>
int main()
{

int vet[10],vet2[10],cod,i,x,y;

printf("Digite 10 valores entre 0 e 50 para o vetor:\n");
for(i=0;i<10;i++){
 scanf("%i",&vet[i]);
  if(vet[i]<0 || vet[i]>50){
   printf("Este valor não pertence ao intervalo [0,50], digite outro valor:\n");
   scanf("%i",&vet[i]);
  }
  if(vet[i]%2!=0){
   vet2[x]=vet[i];
   x++;
  }
}

printf("Este é o vetor com os seus valores:\n");
for(i=0;i<10;i++){
 printf("%i ",vet[i]);
 y++;
 if(y%2==0){
  printf("\n");}}

printf("Estes são os números ímpares do seu vetor:\n");
for(i=0;i<10;i++){
 if(vet2[i]!=0 && vet2[i]<51){
  printf("%i ",vet2[i]);
 }
 y++;
 if(y%2==0){
  printf("\n");
 }
}
return 0;
}
