/*Receber 5 conuntos de 2 valores, sendo um valor para identificação e outro para altura. Imprimir o número com a maoir
e a menor altura e suas alturas.*/

#include <stdio.h>
int main() {
int a1n,a1a,a2n,a2a,a3n,a3a,a4n,a4a,a5n,a5a;

   //Aluno 1
printf("Digite um número entre 1 e 5 para ser o seu número: ");
scanf("%i",&a1n);
printf("Digite a sua altura em centímetros: ");
scanf("%i",&a1a);

    //Aluno 2
printf("Digite um número entre 1 e 5, diferente de %i, para ser o seu número: ",a1n);
scanf("%i",&a2n);

if(a1n==a2n){
   do{
      printf("Este número já foi escolhido. Escolha outro: ");
      scanf("%i",&a2n);
    }while (a1n==a2n);
}
    
printf("Digite a sua altura em centímetros: ");
scanf("%i",&a2a);

    //Aluno 3
printf("Digite um número entre 1 e 5, diferente de %i e %i, para ser o seu número: ",a1n,a2n);
scanf("%i",&a3n);

if(a1n==a3n || a2n==a3n){
   do{
      printf("Este número já foi escolhido. Escolha outro: ");
      scanf("%i",&a3n);
    }while (a1n==a3n || a2n==a3n);
}

printf("Digite a sua altura em centímetros: ");
scanf("%i",&a3a);

    //Aluno 4
printf("Digite um número entre 1 e 5 diferente de %i, %i e %i para ser o seu número: ",a1n,a2n,a3n);
scanf("%i",&a4n);

if(a1n==a4n || a2n==a4n || a3n==a4n){
   do{
      printf("Este número já foi escolhido. Escolha outro: ");
      scanf("%i",&a4n);
    }while (a1n==a4n || a2n==a4n || a3n==a4n);
}

printf("Digite a sua altura em centímetros: ");
scanf("%i",&a4a);

    //Aluno 5
printf("Digite um número entre 1 e 5 diferente de %i, %i, %i e %i para ser o seu número: ",a1n,a2n,a3n,a4n);
scanf("%i",&a5n);

if(a1n==a5n || a2n==a5n || a3n==a5n || a4n==a5n){
   do{
      printf("Este número já foi escolhido. Escolha outro: ");
      scanf("%i",&a5n);
    }while (a1n==a4n || a2n==a4n || a3n==a4n);
}

printf("Digite a sua altura em centímetros: ");
scanf("%i",&a5a);

if(a1a>=a2a && a1a>=a3a && a1a>=a4a && a1a>=a5a){
    printf("O aluno com a maior altura é o %i: %i\n",a1n,a1a);
}
else if(a2a>=a1a && a2a>=a3a && a2a>=a4a && a2a>=a5a){
    printf("O aluno com a maior altura é o %i: %i\n",a2n,a2a);
}
else if(a3a>=a1a && a3a>=a2a && a3a>=a4a && a3a>=a5a){
    printf("O aluno com a maior altura é o %i: %i\n",a3n,a3a);
}
else if(a4a>=a1a && a4a>=a2a && a4a>=a3a && a4a>=a5a){
    printf("O aluno com a maior altura é o %i: %i\n",a4n,a4a);
}
else {
    printf("O aluno com a maior altura é o %i: %i\n",a5n,a5a);
}

if(a1a<=a2a && a1a<=a3a && a1a<=a4a && a1a<=a5a){
    printf("O aluno com a menor altura é o %i: %i",a1n,a1a);
}
else if(a2a<=a1a && a2a<=a3a && a2a<=a4a && a2a<=a5a){
    printf("O aluno com a menor altura é o %i: %i",a2n,a2a);
}
else if(a3a<=a1a && a3a<=a2a && a3a<=a4a && a3a<=a5a){
    printf("O aluno com a menor altura é o %i: %i",a3n,a3a);
}
else if(a4a<=a1a && a4a<=a2a && a4a<=a3a && a4a<=a5a){
    printf("O aluno com a menor altura é o %i: %i",a4n,a4a);
}
else {
    printf("O aluno com a menor altura é o %i: %i",a5n,a5a);
}

return 0;
}
