#include <stdio.h>
#include <string.h>
struct cadastro{
 char num[4], nota[4] ;
} class[4];

int main(){
int i,m;

for(i=0;i<4;i++){
 printf("Num: ");
 gets(class[i].num);
}

for(i=0;i<4;i++){
 printf("Nota: ");
 gets(class[i].nota);
}
m=(class[0].nota + class[1].nota + class[2].nota + class[3].nota)/4;
for(i=0;i<4;i++){
 printf("%s %s\n",class[i].num,class[i].nota);
}
printf("%i",m);
return 0;
}
