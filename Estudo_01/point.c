#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
  int valor;
  struct dados * prox;
}lista;

typedef struct cabe{
  int qtd;
  lista * inicio;
  lista * fim;
}cab;


lista * printa_cont(lista * pp){
  pp = (lista*)malloc(sizeof(lista));
  (*pp).valor+=5;
  return pp;
}

int main(){

//Passagem de ponteiro
lista * p2=NULL;
p2 = printa_cont(p2);
printf("%d\n",(*p2).valor);

//Ponteiro para ponteiro
int a = 3;
int *p1;
int **pp;

p1 = &a;
*pp = p1;
printf("%d\n",&a);
printf("%d\n",p1);
printf("%d\n",**pp);

  return 0;
}
