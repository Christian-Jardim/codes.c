/*Ler um texto pelo teclado (com espaços) e imprimir, em seguida,
o número de caracteres digitados.*/

#include <stdio.h>
#include <string.h>
int main()
{
int n;
char p[21];

printf("Digite uma palavra ou frase: ");
gets(p);
n=strlen(p);
printf("O número de caracteres digitados foi: %i",n);
return 0;
}
