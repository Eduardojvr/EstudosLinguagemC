#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct dados{
    char nome[30];
    int idade;
    char sexo;
    struct dados * prox;
}lista;

 typedef struct cabecalho{
  int qtd;
  lista * inicio;
  lista * proximo;
 }cab;


void ordena(cab * d){
    int i=0,q = d->qtd;
    lista * aux;
    while(q>0){
        i=0;
        while(i<q){
            if(d->proximo->idade > d->proximo->prox->idade){
                    aux = d->proximo;
                    d->proximo = d->proximo->prox;
                    d->proximo->prox = aux;
            }
            i++;
        }
        q--;
    }

}
void insere_dados_fim(cab * d,int x){
    lista * novo,*aux;
    novo=(lista*)malloc(sizeof(lista));
    if(d->qtd == 0){
        d->inicio = novo;
        novo->idade = x;
        d->inicio->prox = NULL;
    }else{
        d->proximo = d->inicio;
        while(d->proximo->prox != NULL){
            d->proximo = d->proximo->prox;
        }
        d->proximo->prox = novo;
        novo->idade = x;
        novo->prox=NULL;
    }
    d->qtd++;
}
int main(){
    cab * d;
    d=(cab*)malloc(sizeof(cab));
    d->proximo=NULL;
    d->inicio=d->proximo;
    d->qtd=0;

   int op,id,m;



    do{
         printf("1-Inserir\n2-Alterar\n3-Excluir\n4-Pesquisar");
         scanf("%d",&op);

    switch(op){
        case 1:
            printf("Idade:");
            scanf("%d",&id);
            insere_dados_fim(d,id);


            break;

        case 2:
            ordena(d);
            d->proximo = d->inicio;
            while(d->proximo->prox != NULL){
                printf("%d\n",d->proximo->idade);
                d->proximo = d->proximo->prox;
            }
            break;
    }

    }while(op!=6);

    return 0;
}
