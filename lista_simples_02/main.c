#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
    int valor;
    struct dados * prox;
}dado;

typedef struct cabecalho{
    int qtd;
    dado * inicio;
    dado * proximo;
}cab;
void menu(){
    printf("--------------\nMenu\n--------------\n");
    printf("1-Cadastrar\n");
    printf("2-Cadastros\n");
    printf("3-Procurar\n");
    printf("4-Excluir\n");
    printf("5-Sair\n");
}
void insere(int val,cab * salva){
    dado * novo,*aux;
    if(salva->qtd == 0){
        novo = (dado*)malloc(sizeof(dado));
        novo->valor = val;
        salva->inicio = novo;
        salva->proximo = novo;
        novo->prox=NULL;
    }else{
        aux = salva->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        novo = (dado*)malloc(sizeof(dado));
        novo->valor = val;
        aux->prox = novo;
        salva->proximo = novo;
        novo->prox = NULL;
    }
    salva->qtd++;
}
void imprimir(cab * salva){
    if(salva->qtd == 0){
            printf("Lista vazia!\n");
    }else{
    salva->proximo = salva->inicio;
    printf("Quantidade de cadastros: %d\n",salva->qtd);
    printf("Registros:\n");
    while(salva->proximo != NULL){
        printf("%d ",salva->proximo->valor);
        salva->proximo = salva->proximo->prox;
    }
    printf("\n");
  }
}
void procurando(){
    int i;
for(i=0;i<10;i++){
    system("cls");
    printf("Procurando.");
    system("cls");
    printf("Procurando..");
    system("cls");
    printf("Procurando...");
    system("cls");
    printf("Procurando....");
    system("cls");
    printf("Procurando.....");
    system("cls");
    printf("Procurando......");
    system("cls");
    printf("Procurando.......");
    system("cls");
    printf("Procurando........");
    system("cls");
}
}
void proc(int v,cab * salva){
    dado * aux;
    aux = salva->inicio;
    if(salva->qtd == 0){
        printf("Lista vazia!\n");
    }else{
    while(aux->valor != v && aux->prox != NULL){
        aux = aux->prox;
    }
       if(aux->valor == v){
            printf("Encontrado!\n");
        }else{
            printf("Não encontrado!\n");
        }
    }
}

void exluir(int v,cab * salva){
    dado * aux,*aux2;
    if(salva->inicio->valor == v){
        aux = salva->inicio->prox;
        free(salva->inicio);
        salva->inicio = aux;
        printf("Valor excluido!\n");
        salva->qtd--;
    }else{
    aux = salva->inicio;
    while(aux->valor != v && aux->prox != NULL ){
        aux2 =  aux;
        aux=aux->prox;
    }
    if(aux->valor == v){
      aux2->prox = aux->prox;
      free(aux);
      salva->qtd--;
      printf("Valor excluido!\n");
    }else{
        printf("Valor não encontrado!\n");
    }
  }
}


int main()
{
cab * salva;
 salva = (cab*)malloc(sizeof(cab));
 salva->qtd=0;
 salva->inicio=NULL;
 salva->proximo=NULL;
int op,val;


do{
menu();
scanf("%d",&op);
switch(op){
case 1:
      printf("Valor:");
      scanf("%d",&val);
      insere(val,salva);
    break;
case 2:
        imprimir(salva);
    break;

case 3:
    printf("Valor a ser procurado: ");
    scanf("%d",&val);
    procurando();
    proc(val,salva);
    break;
case 4:
    printf("Valor a ser excluido: ");
    scanf("%d",&val);
    exluir(val,salva);

    break;
case 5:
    exit(0);
default:
    printf("Opção inválida!\n");
    break;
        }
}while(1);
    return 0;
}
