#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
  int v;
  struct arvore * esq;
  struct arvore * dir;
}arv;


arv * insere(int x,arv * raiz){
  arv * aux;
  arv * novo = (arv*)malloc(sizeof(arv));
  novo->v = x;
  if(!raiz){
    raiz = novo;
    raiz->esq = NULL;
    raiz->dir = NULL;
  }else{
    aux = raiz;
    while ((aux->esq != NULL) || (aux->dir != NULL)) {
        if((aux->v) > (novo->v)){
          aux = aux->esq;
        }else if((aux->esq == NULL)){
          break;
        }else if((aux->dir == NULL)){
          break;
        }else if((aux->v) < (novo->v)){
          aux = aux->dir;
        }
    }
    if((aux->v) > (novo->v)){
      aux->esq = novo;
      novo->esq = NULL;
      novo->dir = NULL;
    }else if((aux->v) < (novo->v)){
      aux->dir = novo;
      novo->esq = NULL;
      novo->dir=NULL;
    }
  }
  return raiz;
}

int main (){
int x,op;
arv * aux=NULL;
arv * raiz=NULL;

while (1) {
  printf("1-insert\n2-Imprimir\n3-Sair");
  scanf("%d",&op);
switch(op){
  case 1:
      printf("Digite um valor: ");
      scanf("%d",&x);
      raiz = insere(x,raiz);
    break;
  case 2:
      aux = raiz;
      while (aux != NULL) {
        aux = aux->esq;
          if(aux->esq == NULL){
            printf("Menor valor da arvore: %d\n",aux->v);
          break;
          }
      }
      aux = raiz;
      while (aux != NULL) {
        if(aux->dir == NULL){
            printf("Maior valor da arvore: %d\n",aux->v);
          break;
        }
        aux = aux->dir;
      }
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
