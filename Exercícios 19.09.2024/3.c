/*Escreva um programa C que leia duas strings. Se as strings forem iguais
escreva “strings iguais”. Caso contrário, concatene as duas strings e 
imprima a string resultante.*/

#include <stdio.h>
#include <string.h>
int main(){
    
char s[3][11],aux[22];
int i,j;
for(i=0;i<3;i++){
    printf("Digite a palavra %i: ",i+1);
    scanf("%s",s[i]);
}

for(i=0;i<3;i++){
    for(j=1;j<3;j++){
        if(strcmp(s[j- 1],s[j])>0){
            strcpy(aux,s[j- 1]);
            strcpy(s[j- 1],s[j]);
            strcpy(s[j],aux);
        }
    }
}
for(i=0;i<3;i++){
    printf("%s\n",s[i]);
}
return 0;
}
