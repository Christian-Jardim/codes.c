#include <stdio.h>
#include <string.h>

enum gen{rock=1, samba, metal, sertanejo, jazz};

typedef struct Band{
  char nome[30];
  enum gen tipo;
  int rank;
  int integ;
}Band;

void load(Band band[]);
void print(Band band[], int i);
void ran(Band band[], int r);
void est(Band band[], int g);
void banVeri(Band band[], char ver[20]);
void menu();

int main() {
  int r,g,op;
  char genfav[10],ver[20];
  Band band[5];
  do{
    menu();
    printf("\nEscolha uma das opcoes acima: ");
    scanf("%d", &op);
    switch(op) {
    case 1:
      load(band);
      break;
    case 2:
      for(int i=0;i<5;i++){
        print(band,i);
      }  
      break;
    case 3:
      printf("Digite o rank: ");
      scanf("%d",&r);
      ran(band, r);
      break;
    case 4:
      printf("\nDigite o valor do genero: 1 - rock, 2 - samba, 3 - metal, 4 - sertanejo, 5 - jazz\n");
      scanf("%d", &g);
      est(band, g);
      break;
    case 5:
      printf("\nDigite o nome de uma banda: ");
      scanf(" %[^\n]", ver);
      banVeri(band, ver);
      break;
    case 6:
      return 0;
      break;
    default:
      printf("\nOpcao invalida");
    }
  }while(op != 6);
}

void menu() {
  printf("\n\n1 - Inserir as bandas");
  printf("\n2 - Apresentar todas as bandas");
  printf("\n3 - Achar uma banda pelo rank");
  printf("\n4 - Apresentar todas as bandas de um genero");
  printf("\n5 - Verificar se uma banda esta entre as suas favoritas");
  printf("\n6 - Sair");
}

void load(Band band[]) {
  for(int i=0; i<5; i++) {
    printf("\nDigite o nome de uma banda favorita: ");
    scanf(" %[^\n]s", band[i].nome);
    int tipoinf;
    printf("\nSeu estilo musical, dentro destas opcoes: 1 - rock, 2 - samba, 3 - metal, 4 - sertanejo, 5 - jazz: ");
    scanf("%d", &tipoinf);
    band[i].tipo = tipoinf;
    printf("\nQuantidade de membros: ");
    scanf("%d",&band[i].integ);
    printf("\nA posicao dela no seu ranking: ");
    scanf("%d",&band[i].rank);
  }
}

void print(Band band[], int i) {
    printf("\nBanda: %s\n",band[i].nome);
    printf("\nQuantidade de integrantes:%d\n", band[i].integ);
    printf("\nLugar no ranking:%d\n",band[i].rank);
    printf("\nEstilo musical: ");
    switch(band[i].tipo) {
    case 1:
      printf("rock\n");
      break;
    case 2:
      printf("samba\n");
      break;
    case 3:
      printf("metal\n");
      break;
    case 4:
      printf("sertanejo\n");
      break;
    case 5:
      printf("jazz\n");
      break;
    }
}

void ran(Band band[], int r) {
  for(int i=0; i<5; i++) {
    if(band[i].rank == r) {
      print(band, i);
    }
  }
}

void est(Band band[], int g) {
  printf("Estas são as suas bandas favoritas desse estilo:\n");
  for(int i=0; i<5; i++) {
    if(band[i].tipo == g) {
      print(band, i);
    }
  }
}

void banVeri(Band band[], char ver[20]) {
  int y;
  for(int i=0; i<5; i++) {
    if(strcmp(ver, band[i].nome) == 0) {
      printf("\nEsta banda é uma das suas favoritas.\n");
      y=1;}
    if(y=0) {
      printf("\nEsta banda não está entre as suas favoritas.\n");
    }
  }
}
