/*Declarar duas strings com capacidade para 20 caracteres.
Ler a primeira string e copiá-la para a segunda.
Imprimir no final o conteúdo das duas strings.*/

#include <string.h>
#include <stdio.h>

int main()
{
char p1[21], p2[21];
    
printf("Primeira palavra: ");
gets(p1);
strcpy(p2,p1);
puts(p1);
puts(p2);
    
return 0;
}
