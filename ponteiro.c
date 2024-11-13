#include <stdio.h>

void mm(int *v, int n , int *min, int*max){
 *max=v[0];
 *min=v[0];
 for(int i=0; i<10; i++){
  if(v[i]>*max){
   *max=v[i];}
  if(v[i]<*min){
   *min=v[i];}}}

int main(){
int x[10], min, max, *vet, i, n;

for(i=0;i<10;i++){
 scanf("%i",&x[i]);}

vet=x;
n=10;

mm(vet, n , &min, &max);
printf("Minimo:%i e Maximo:%i\n.", min, max);
return 0;}
