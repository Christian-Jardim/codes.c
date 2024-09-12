/*Receber sexo, peso e idade do usuário. Depois calcular: o peso total,
a idade total, o peso médio e a idade média de cada sexo.*\

#include <stdio.h>
int main()
{
    int sexo,vezesf,vezesm;
    float pesom,idadem,pesotm,idadetm,pesomm,idademm;
    float pesof,idadef,pesotf,idadetf,pesomf,idademf;
    printf("Digite 0 para sair.\n");
    do{
        printf("Qual é o seu sexo?\nDigite 1 para Feminino e 2 para Masculino: ");
        scanf("%i",&sexo);
        if(sexo==1){
            printf("Digite o seu peso: ");
            scanf("%f",&pesof);
            printf("Digite a sua idade: ");
            scanf("%f",&idadef);
            pesotf+=pesof;
            idadetf+=idadef;
            vezesf++;}
        
        if(sexo==2){
            printf("Digite o seu peso: ");
            scanf("%f",&pesom);
            printf("Digite a sua idade: ");
            scanf("%f",&idadem);
            pesotm+=pesom;
            idadetm+=idadem;
            vezesm++;
        }
    }while(sexo==1 || sexo==2);
    
    pesomf=pesotf/vezesf;
    idademf=idadetf/vezesf;
    pesomm=pesotm/vezesm;
    idademm=idadetm/vezesm;
    
    printf("O peso total das mlheres é: %f\n",pesotf);
    printf("O peso médio das mulheres é: %f\n",pesomf);
    printf("A idade total das mulheres é: %f\n",idadetf);
    printf("A idade média das mulheres é: %f\n",idademf);
    printf("-----------------------------------\n");
    printf("O peso total dos homens é: %f\n",pesotm);
    printf("O peso médio dos homens é: %f\n",pesomm);
    printf("A idade total dos homens é: %f\n",idadetm);
    printf("A idade média dos homens é: %f\n",idademm);
    return 0;
}
