#include <stdlib.h>
#include <stdio.h>

void somaRef(int * b){
  *b = 20;
}
int somaPar(int b){
  b = 15;
  return b;
}

int main(){

int a=10;

somaRef(&a);
printf("%d\n",a);

a = somaPar(a);
printf("%d\n",a);
  return 0;
}
