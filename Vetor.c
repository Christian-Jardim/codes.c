#include <stdio.h>
int main(){

int vet[5],x,y;

for(x=0;x<5;x++){
    printf("Digite: \n");
    scanf("%d",&vet[x]);
}
for(x=0;x<5;x++){
    printf("%d\t\n",vet[x]);
}
for(y=0;y<5;y++){
    if(vet[y]<0){
        printf("Dado: %d e posição: %d.\n",vet[y],y+1);
    }
}
return 0;
}
