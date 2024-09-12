/*Receber os valores de dois vetores e, se forem iguais nas mesmas posições, imprimi-los.*/ 

#include <stdio.h>
int main(){

int vet1[5],vet2[5],x,y;

for(x=0;x<5;x++){
    printf("Digite os valores do vetor 1: \n");
    scanf("%d",&vet1[x]);
}
for(x=0;x<5;x++){
    printf("Digite os valores do vetor 2:\n");
    scanf("%d",&vet2[x]);
}
for(y=0;y<5;y++){
    if(vet1[y]==vet2[y]){
        printf("A posição %d possui o mesmo valor: %d\n",y+1,vet1[y]);
    }
}
return 0;
}
