#include <stdio.h>

int fun(int x){

if(x==11){
 return 0;}
else{
 printf("%i\n",x);
 return fun(x+1);}}

int main(){

fun(1);  

return 0;}
