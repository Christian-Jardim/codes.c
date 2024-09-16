/*Imprimir os núneros que, ao seremdividos por 11, tenham resto iigual a 5.*/

#include <stdio.h>
int main()
{

int num=1000;

printf("Estes números ao serem divididos por 11 dão resto igual a 5:\n");

for(num==1000;num<=1999;num++){
    if(num%11==5){
        printf("%i\n",num);
    }
}
return 0;
}
