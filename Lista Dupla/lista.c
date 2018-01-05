#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
  int v;
  struct dados * prox;
  struct dados * ant;
}lista;

typedef struct cabecalho{
  int qtd;
  lista * inicio;
  lista * fim;
}cab;

void insere_inicio(int x,cab * l){
    lista * novo = (lista*)malloc(sizeof(lista));
    novo->v = x;
    /*novo->prox = (*l).inicio;
    novo->ant = NULL;
    if(l->inicio !=  NULL)
      (*l).inicio->ant = novo;
      l->inicio = novo;
      l->qtd++;*/
      if(l->inicio == NULL){
        l->inicio = novo;
      }else{
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
      }
      l->qtd++;
}


int main() {
cab * salva =  (cab*)malloc(sizeof(cab));
salva->qtd = 0;
salva->inicio = NULL;
salva->fim = NULL;
int val;
int op;
while (1) {
  printf("1-Inserir\n2-Mostrar na ordem de entrada\n3-Mostrar na ordem inversa\n");
  scanf("%d",&op);
  getchar();
  switch (op) {
    case 1:
    printf("Valor: ");
    scanf("%d",&val);
    insere_inicio(val,salva);
    break;
    case 2:
    if(salva->inicio == NULL){
      printf("Lista vazia!");
    }else{
    salva->fim = salva->inicio;
    while(salva->fim != NULL){
      printf("%d ",salva->fim->v);
      salva->fim = salva->fim->prox;
    }
  }
    printf("\n");
    break;
    case 3:
    if(salva->inicio == NULL){
      printf("Lista vazia!");
    }else{
    salva->fim = salva->inicio;
    while (salva->fim->prox != NULL) {
      salva->fim = salva->fim->prox;
    }
    while (salva->fim != NULL) {
      printf("%d ",salva->fim->v);
      salva->fim = salva->fim->ant;
    }
  }
  printf("\n");
    break;
    default:
      printf("Opção inválida!\n");
      break;
  }
}


  return 0;
}
