#include <stdio.h>
int main()
{

int vet[5],cod,i;

printf("Digite os valoresdo vetor:\n");
for(i=0;i<5;i++){
 scanf("%i",&vet[i]);
}

printf("Digite um código entre 0 e 2: ");
scanf("%i",&cod);

if(cod==0){
 return 0;
}
else if(cod==1){
 printf("Os valores do vetor são:\n");
 for(i=0;i<5;i++){
  printf("%i",vet[i]);
 }
}
else if(cod==2){
 printf("Os valores em posições invertidas do vetor são:\n");
 for(i=4;i>-1;i--){
  printf("%i",vet[i]);
 }
}
else{
 printf("Código inválido.");
}

return 0;
}
