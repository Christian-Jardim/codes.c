/*Programa onde uma função recebe três notas de um aluno e uma letra.
Se a letra for 'A' a função retorna a média aritmética, se for 'P',
a média ponderada (pesos 5, 3 e 2) e se for 'H' a média harmônica.*/

#include <stdio.h>

float vet[3];
int i;
char cod;

int média (char x){

switch (x){
 case 'A':
  printf("A média aritmética é: %f",(vet[0]+vet[1]+vet[2])/3);
  break;
 case 'P':
  printf("A média ponderada é: %f",vet[0]*0.5+vet[1]*0.3+vet[2]*0.2);
  break;
 case 'H':
  printf("A média harmônica é: %f",3/(1/vet[0]+ 1/vet[1]+ 1/vet[2]));
  break;
 default:
  printf("Opção inválida.");}}

int main(){
    
printf("Notas:\n");
for(i=0;i<3;i++){
    scanf("%f",&vet[i]);}

printf("Digite 'A' para receber a média aritmética, 'P' para a média\nponderada, com pesos 5, 3 e 2, e 'H' para a média harmônica: ");
scanf("%s",&cod);

média(cod);

return 0;}
