#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
  int v;
  struct dados * prox;
}lista;

lista * insere_cab(int v,lista * inicio){
  lista * novo;
  novo = (lista*)malloc(sizeof(lista));

  if(inicio == NULL){
    inicio = (lista*)malloc(sizeof(lista));
    inicio->v = v;
    inicio->prox = NULL;
  }else{
    novo->v = v;
    novo->prox = inicio;
    inicio = novo;
  }
  return inicio;
}

int  main(){
lista * inicio=NULL;
lista * proximo=NULL;
int op,v;

while(1){
  printf("1-Inserir\n2-Mostrar\n3-Sair\n");
  scanf("%d",&op);
switch (op) {
  case 1:
  printf("Digite uma valor:\n");
  scanf("%d",&v);
  inicio = insere_cab(v,inicio);
  break;
  case 2:
  proximo = inicio;
  while (proximo != NULL) {
    printf("%d ",proximo->v);
    proximo = proximo->prox;
  }
  printf("\n");
  break;
  case 3:
  exit(0);
  break;
  default:
  printf("Opção inválida!\n");
  break;
}
}
  return 0;
}
