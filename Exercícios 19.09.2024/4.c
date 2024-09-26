/*Escreva um programa C que leia duas strings. Se as strings forem iguais
escreva “strings iguais”. Caso contrário, concatene as duas strings e 
imprima a string resultante.*/

#include <stdio.h>
#include <string.h>
int main()
{

char s1[11],s2[22];

printf("Digite a primeira palavra: ");
gets(s1);
printf("Digite a primeira palavra: ");
gets(s2);

if(strcmp(s1,s2)==0){
    printf("Strings iguais.");
}
else{
    strcat(s2,s1);
    printf("%s",s2);
}
return 0;
}
