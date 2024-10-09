/*Programa que preenche um vetor de tamanho 100 com
os 100 primeiros naturais que não são múltiplos de 7.*/

#include <stdio.h>
int main()
{

int vet[100],i;
for(i=0;i<100;i++){
 if(i%7 != 0){
  vet[i]=i;}}

return 0;
}
