#include <stdio.h>

int main() {

Int valor,pares;

printf(“Número: “);

scanf(“%d”,&valor);

printf(“Estes são tos os números pares até %d:\n”,valor);

for(pares = 2; pares <= valor; pares+=2){

    printf(“%d\n”, pares);

}

return 0;

}

