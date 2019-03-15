/*
Aluno: Eduardo Júnio Veloso Rodrigues
Matrícula: 14/0168192
Exercício 1 : Gerenciador de Automóveis para proprietários de veículos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dados{
    int id;
    int ano;
    char placa[10];
    char renavan[11];
    char corVeiculo[20];
    char marca[50];
    char modelo[50];
    char proprietario[50];
    char cpf[20];
    char rg[20];
    char data[15];
    struct dados * prox;
    struct dados * ant;
}lista;

typedef struct cabecalho{
    int qtd;
    lista * inicio;
    lista * fim;
}cab;

void insere_inicio(int id, int ano, char placa[], char renavan[], char corVeiculo[], char marca[], char modelo[],  char proprietario[], char cpf[], char rg[], char data[], cab * l, FILE * arquivo){
    lista * novo = (lista*)malloc(sizeof(lista));
    novo->id = id;
    novo->ano = ano;

    for(int i=0;i<strlen(placa);i++){
        novo->placa[i] = placa[i];
    }
    for(int i=0;i<strlen(renavan);i++){
        novo->renavan[i] = renavan[i];
    }
    for(int i=0;i<strlen(corVeiculo);i++){
        novo->corVeiculo[i] = corVeiculo[i];
    }
    for(int i=0;i<strlen(marca);i++){
        novo->marca[i] = marca[i];
    }
    for(int i=0;i<strlen(modelo);i++){
        novo->modelo[i] = modelo[i];
    }
    for(int i=0;i<strlen(proprietario);i++){
        novo->proprietario[i] = proprietario[i];
    }
    for(int i=0;i<strlen(cpf);i++){
        novo->cpf[i] = cpf[i];
    }
    for(int i=0;i<strlen(rg);i++){
        novo->rg[i] = rg[i];
    }
    for(int i=0;i<strlen(data);i++){
        novo->data[i] = data[i];
    }
    arquivo = fopen("base.txt", "a");

    fprintf(arquivo, "%d    ", novo->id);
    fprintf(arquivo, "%d    ", novo->ano);
    fprintf(arquivo, "%s    ", novo->placa);
    fprintf(arquivo, "%s    ", novo->renavan);
    fprintf(arquivo, "%s    ", novo->corVeiculo);
    fprintf(arquivo, "%s    ", novo->marca);
    fprintf(arquivo, "%s    ", novo->modelo);
    fprintf(arquivo, "%s    ", novo->proprietario);
    fprintf(arquivo, "%s    ", novo->cpf);
    fprintf(arquivo, "%s    ", novo->rg);
    fprintf(arquivo, "%s    \n", novo->data);

    fclose(arquivo);

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
int val, op, id, ano;
char placa[10], renavan[11], corVeiculo[20], marca[50], modelo[50],proprietario[50], rg[20], data[15];
char dadosBanco[1000], idRegistro[10], cpf[20];
FILE *arquivo;
FILE *arquivoTemporario;

while (1) {
    printf("1-Inserir\n2-Listar dados salvos na memória\n3-Listar dados salvos no banco\n4-Excluir dado\n5-Sair\n");
    scanf("%d",&op);
    getchar();
    switch (op) {
        case 1:
            printf("Digite um id:\n");
            scanf("%d", &id);

            printf("Digite o ano:\n");
            scanf("%d", &ano);

            printf("Digite a placa:\n");
            scanf("%s",placa);

            printf("Digite o renavan:\n");
            scanf("%s",renavan);

            printf("Digite a cor do veiculo:\n");
            scanf("%s",corVeiculo);

            printf("Digite a marca do veiculo:\n");
            scanf("%s",marca);

            printf("Digite o modelo do veiculo:\n");
            scanf("%s",modelo);

            printf("Digite o nome do proprietario:\n");
            scanf("%s",proprietario);

            printf("Digite o cpf do proprietario:\n");
            scanf("%s",cpf);

            printf("Digite o RG do proprietario:\n");
            scanf("%s",rg);

            printf("Digite a data de nascimento do proprietario:\n");
            scanf("%s",data);

            insere_inicio(id, ano, placa, renavan, corVeiculo, marca, modelo, proprietario, cpf,rg, data, salva, arquivo);

            break;
        case 2:
            if(salva->inicio == NULL){
                printf("Lista vazia!");
            }else{
                salva->fim = salva->inicio;
                printf("============================\n Registros em memória\n============================\n");    
                while(salva->fim != NULL){
                    printf("%d    ",salva->fim->id);
                    printf("%d    ",salva->fim->ano);
                    printf("%s    ",salva->fim->placa);
                    printf("%s    ",salva->fim->renavan);
                    printf("%s    ",salva->fim->corVeiculo);
                    printf("%s    ",salva->fim->marca);
                    printf("%s    ",salva->fim->modelo);
                    printf("%s    ",salva->fim->cpf);
                    printf("%s    ",salva->fim->proprietario);
                    printf("%s    ",salva->fim->rg);
                    printf("%s    ",salva->fim->data);
                     salva->fim = salva->fim->prox;
                }
            }
            printf("\n");
            break;
        case 3:
            printf("============================\n Registros no banco\n============================\nID  |  ANO  |  PLACA  |  RENAVAN  |  COR(CARRO)  |  MARCA  |  MODELO  |  PROPRIETARIO  |  CPF  |  RG  |  DATA(NASCIMENTO)\n");    
            arquivo = fopen("base.txt", "r");
            if(arquivo){
                char dadosDoBanco[1000];
                while(fgets(dadosDoBanco, 1000, arquivo) != NULL){
                    printf("%s", dadosDoBanco);
                }
            }
            printf("\n");
            break;
        case 4:
            printf("Digite o ID do registro que deseja excluir:");
            scanf("%c", idRegistro);
            getchar();

            arquivo = fopen("base.txt", "r");
            arquivoTemporario = fopen("temporario.txt", "a");
            while(fgets(dadosBanco, 1000, arquivo) != NULL){
                if(dadosBanco[0] == idRegistro[0]){
                    printf("****** Dado excluido com sucesso! ******\n");
                }else {
                    fprintf(arquivoTemporario, "%s", dadosBanco);
                }
            }
            fclose(arquivo);
            fclose(arquivoTemporario);

            arquivo = fopen("base.txt", "w");
            arquivoTemporario = fopen("temporario.txt", "r");

            char dadosNovos[1000];
            while(fgets(dadosNovos, 1000, arquivoTemporario) != NULL){
                fprintf(arquivo, "%s", dadosNovos);
            }
            fclose(arquivo);
            fclose(arquivoTemporario);

            arquivoTemporario = fopen("temporario.txt", "w");
            fclose(arquivoTemporario);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}
  return 0;
}