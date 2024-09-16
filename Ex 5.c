#include <stdio.h>



Int main() {

   //Aluno 1

    Printf(“Digite um número entre 1 e 5 para ser o seu número representante : “);

    Scanf(“%i”,&a1n);

    Printf(“Digite a sua altura em centímetros: “);

    Scanf(“%i”,&a1a);

    

    //Aluno 2

    Printf(“Digite um número entre 1 e 5, diferente de %i, para ser o seu número representante : “);

    Scanf(“%i”,&a2n);

    If(a1n==a2n){

       Do{

          Printf(“Este número já foi escolhido. Escolha outro.”)

          Printf(“Digite um número entre 1 e 5, diferente de %i para ser o seu número representante : “,a1n);

          Scanf(“%i”,&a2n);

        }while (a1n==a2n)

    }

    Printf(“Digite a sua altura em centímetros: “);

    Scanf(“%i”,&a1a);

    

    //Aluno 3

    Printf(“Digite um número entre 1 e 5 para ser o seu número representante : “);

    Scanf(“%i”,&a1n);

    If(a1n==a2n){

       Do{

          Printf(“Este número já foi escolhido. Escolha outro.”)

          Printf(“Digite um número entre 1 e 5, diferente de %i para ser o seu número representante : “,a1n);

          Scanf(“%i”,&a2n);

          Printf(“Digite a sua altura em centímetros: “);

          Scanf(“%i”,&a2a); 

        }while (a1n==a2n)

    }

    Printf(“Digite a sua altura em centímetros: “);

    Scanf(“%i”,&a3a);

    Return 0;

}

