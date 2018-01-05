#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados{
  char nome[50];
  int idade;
  struct dados * prox;
}lista;

typedef struct cabecalho{
  int qtd;
  lista * inicio;
  lista * proximo;
}cab;

/* ************************** Funçoes **************************  */
cab * inicia(cab * salva){
  salva = (cab*)malloc(sizeof(cab));
  if(salva == NULL){
    printf("Erro\n");
  }else{
    salva->qtd = 0;
    salva->inicio = NULL;
    salva->proximo = NULL;
  }
  return salva;
}
void menu(){
  printf("......................\nMenu\n......................\n");
  printf("1-Inserir\n");
  printf("2-Cadastros\n");
  printf("3-Alterar\n");
  printf("5-Sair\n");
}
void ler_nome(char nome[]){
  int c,i=0;
  c  = getchar();
  while (c != '\n') {
    nome[i] = c;
    i++;
    c = getchar();
  }
  nome[i] = '\n';
  nome[i+1] = '\0';
}
void insere(int id,cab * salva,FILE * arquivo,FILE * sq){
    lista * novo;
  novo = (lista*)malloc(sizeof(lista));
  novo->idade = id;
  printf("Nome: ");
  setbuf(stdin,NULL);
  ler_nome(novo->nome);

  if(salva->qtd == 0){
    salva->inicio = novo;
    novo->prox = NULL;
    salva->proximo = salva->inicio;
    arquivo = fopen("dados.txt","w+");
    fprintf(arquivo,"%s %d\n",novo->nome,novo->idade);
    fclose(arquivo);
  }else{
    arquivo = fopen("dados.txt","a+");
    fprintf(arquivo,"%s %d\n",novo->nome,novo->idade);
    fclose(arquivo);
    salva->proximo = salva->inicio;
    while (salva->proximo->prox != NULL) {
      salva->proximo = salva->proximo->prox;
    }
    salva->proximo->prox = novo;
    novo->prox =  NULL;
  }
  salva->qtd++;

    sq = fopen("qtd.txt","w");
    fprintf(sq,"%d",salva->qtd);
    fclose(sq);

}
void imprimir(cab * salva,FILE * arquivo){
  char string[50];
  arquivo = fopen("dados.txt","r");
  while (fgets(string,sizeof(string),arquivo)!= NULL ) {
    printf("%s",string);
  }
    printf("\n");
    fclose(arquivo);
}

void altera(FILE * arquivo){
  FILE * narq;
  char s[1000],n[50];
  int i;
int a=0;
  narq = fopen("temp.txt","w");
  arquivo = fopen("dados.txt","r");
  printf("Nome que deseja alterar:");
  setbuf(stdin,NULL);
  ler_nome(n);
  while (fgets(s,sizeof(s),arquivo) != NULL){
    if(strcmp(s,n) == 0){
      printf("Novo nome:");
      setbuf(stdin,NULL);
      ler_nome(n);
      printf("Nova idade:");
      scanf("%d",&i);
      fprintf(narq,"%s %d\n",n,i);
      a+=1;
    }else{
      if(a==1){
        //continue;
      }else{
        fprintf(narq,"%s",s);
      }
      a=0;
    }
  }
  fclose(narq);
  fclose(arquivo);

  arquivo = fopen("dados.txt","w");
  narq = fopen("temp.txt","r");
  while (fgets(s,sizeof(s),narq) != NULL){
    fprintf(arquivo,"%s",s);
  }
  fclose(narq);
  fclose(arquivo);
  narq = fopen("temp.txt","w");
  fclose(narq);
}

int main(){
/* **************Declarações************* */
cab * salva;
salva= NULL;
salva = inicia(salva);
FILE * arquivo;
FILE * sq;
arquivo = NULL;
int op,i,n;

do {
  menu();
  scanf("%d",&op);
  switch (op) {
    case 1:
        printf("Idade: ");
        scanf("%d",&i);
        sq = fopen("qtd.txt","r+");
        if(sq != NULL){
          fscanf(sq,"%d",&n);
          salva->qtd = n;
        }
        insere(i,salva,arquivo,sq);
        break;
    case 2:
        arquivo = fopen("dados.txt","r");
        if(arquivo == NULL){
          printf("ERRO ao abrir arquivo,quantidade de cadastros = 0\n");
        }else{
          imprimir(salva,arquivo);
          fclose(arquivo);
          printf("Quantidade de registros: %d\n",salva->qtd);
        }
        break;
   case 3:
      altera(arquivo);
        break;
   case 5 :
        exit(0);
        break;
    default:
        printf("Opção inválida\n");
        break;
  }
} while(op != 5);

  return 0;
}
