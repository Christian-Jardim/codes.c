/*Escreva um programa C que leia duas strings. Se as strings forem iguais
escreva “strings iguais”. Caso contrário, concatene as duas strings e 
imprima a string resultante.*/

#include <stdio.h>
#include <string.h>
int main(){
    
char s1[11],s2[11],s3[11];

printf("Palavra 1: ");
gets(s1);
printf("Palavra 1: ");
gets(s2);
printf("Palavra 1: ");
gets(s3);

if(strcmp(s2,s1)>0 || strcmp(s3,s1)>0  || strcmp(s3,s2)>0){
    puts(s1);
    puts(s2);
    puts(s3);
}
if(strcmp(s1,s2)>0 || strcmp(s3,s2)>0  || strcmp(s3,s2)>0){
    puts(s1);
    puts(s2);
    puts(s3);
}
return 0;
}
