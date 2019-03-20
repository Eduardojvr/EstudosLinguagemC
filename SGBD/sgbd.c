/*

Aluno: Eduardo Júnio Veloso Rodrigues
Matrícula: 14/0168192
Exercício 2 (aula 2 exercicio 1) : Gerenciador de Automóveis para proprietários de veículos

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dadosCarro{
    char placa[10];
    char renavan[11];
    char corVeiculo[20];
    char marca[50];
    char modelo[50];
    char cpfDono[20];
    struct dadosCarro * prox;
    struct dadosCarro * ant;
}listaCarro;

typedef struct dadosPessoa {
    char proprietario[50];
    char cpf[20];
    char data[15];
    struct dadosPessoa * prox;
    struct dadosPessoa * ant;
}listaPessoa;

typedef struct cabecalhoCarro{
    int qtd;
    listaCarro * inicio;
    listaCarro * fim;
}cabCarro;

typedef struct cabecalhoPessoa{
    int qtd;
    listaPessoa * inicio;
    listaPessoa * fim;
}cabPessoa;

int pessoa_exist(FILE * arquivoPessoa, char cpfDono[]){
    arquivoPessoa = fopen("basePessoa.txt", "r");
    char dados[1000];
    int achou = 0;
    int controle = 0;
    while(fgets(dados, 1000, arquivoPessoa) != NULL){
        controle = 0;
        for(int i = 0; i < 11; i++){
            if(dados[i] != cpfDono[i]){
                controle = 0;
                break;
            }
            controle+=1;
            if(controle > 10){
                achou = 1;
            }
        }
    }
   fclose(arquivoPessoa);
    
    return achou;
}

void ordena_arquivo_pessoa(FILE * arquivoPessoa){
    char * pEnd;
    char dados[1000];
    cabPessoa * l = (cabPessoa*)(malloc(sizeof(cabPessoa))); 
    l->qtd = 0;
    l->inicio = NULL;
    l->fim = NULL;

    arquivoPessoa = fopen("basePessoa.txt", "r");
    while(fgets(dados, 1000, arquivoPessoa)!= NULL){
        listaPessoa * novo = (listaPessoa*)malloc(sizeof(listaPessoa));
        int count = 0;
        while(dados[count] != ' '){
            novo->cpf[count] = dados[count];
            count++;
        }
        count+=4;
        int posProp = 0;
        while(dados[count] != ' '){
            novo->proprietario[posProp] = dados[count];
            count++;
            posProp+=1;
        }
        count+=4;
        int posData = 0;
        while(dados[count] != ' '){
            novo->data[posData] = dados[count];
            count++;
            posData+=1;
        }
        
        if(l->inicio == NULL){
            l->inicio = novo;
            l->fim = l->inicio;
            l->fim->prox = NULL;
        }else{
            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
        }
            l->qtd++;
    }
    fclose(arquivoPessoa);
    if(l->qtd > 1){
        printf("\n>> Ordenando arquivo\n");    
        int i=0;
        listaPessoa aux;
        listaPessoa vp[5000];
        l->fim = l->inicio;
        for(int i = 0; i < l->qtd; i++){
            vp[i] = *l->fim;
            l->fim = l->fim->prox;
        }
            
        for(int i = 0; i < l->qtd; i++){
            for(int j = 0; j < l->qtd-1; j++){
                if(strtol (vp[j].cpf, &pEnd ,10) > strtol(vp[j+1].cpf, &pEnd, 10)){
                    aux = vp[j];
                    vp[j] = vp[j+1];
                    vp[j+1] = aux;
                }
            }
        }
            
        arquivoPessoa = fopen("basePessoa.txt", "w"); 
        for(int i=0;i<l->qtd;i++){
            fprintf(arquivoPessoa, "%s    ", vp[i].cpf);
            fprintf(arquivoPessoa, "%s    ", vp[i].proprietario);
            fprintf(arquivoPessoa, "%s    \n", vp[i].data);
        }
        fclose(arquivoPessoa);
        printf("\n>> Arquivo ordenado com sucesso!\n");  
    }  
}

void ordena_arquivo_carro(FILE * arquivoCarro){
    
    char dados[1000];
    cabCarro * l = (cabCarro*)(malloc(sizeof(cabCarro))); 
    l->qtd = 0;
    l->inicio = NULL;
    l->fim = NULL;

    arquivoCarro = fopen("baseVeiculo.txt", "r");
    while(fgets(dados, 1000, arquivoCarro)!= NULL){
        listaCarro * novo = (listaCarro*)malloc(sizeof(listaCarro));
        int count = 0;
        while(dados[count] != ' '){
            novo->cpfDono[count] = dados[count];
            count++;
        }
        int posPlaca = 0;
        count+=4;
        while(dados[count] != ' '){
            novo->placa[posPlaca] = dados[count];
            count++;
            posPlaca+=1;
        }
        count+=4;
        int posRenavan = 0;
        while(dados[count] != ' '){
            novo->renavan[posRenavan] = dados[count];
            count++;
            posRenavan+=1;
        }
        count+=4;
        int posCor = 0;
        while(dados[count] != ' '){
            novo->corVeiculo[posCor] = dados[count];
            count++;
            posCor+=1;
        }
        count+=4;
        int posMarca = 0;
        while(dados[count] != ' '){
            novo->marca[posMarca] = dados[count];
            count++;
            posMarca+=1;
        }
        count+=4;
        int posModelo = 0;
        while(dados[count] != ' '){
            novo->modelo[posModelo] = dados[count];
            count++;
            posModelo+=1;
        }
        if(l->inicio == NULL){
            l->inicio = novo;
            l->fim = l->inicio;
            l->fim->prox = NULL;
        }else{
            novo->prox = l->inicio;
            l->inicio->ant = novo;
            l->inicio = novo;
        }
            l->qtd++;
    }
    fclose(arquivoCarro);
    if(l->qtd > 1){
        printf("\n>> Ordenando arquivo\n");    
        int i=0;
        listaCarro aux;
        listaCarro vc[5000];
        l->fim = l->inicio;
        for(int i = 0; i < l->qtd; i++){
            vc[i] = *l->fim;
            l->fim = l->fim->prox;
        }
            
        for(int i = 0; i < l->qtd; i++){
            for(int j = 0; j < l->qtd-1; j++){
                if(atoi(vc[j].cpfDono) > atoi(vc[j+1].cpfDono)){
                    aux = vc[j];
                    vc[j] = vc[j+1];
                    vc[j+1] = aux;
                }
            }
        }
            
        arquivoCarro= fopen("baseVeiculo.txt", "w"); 
        for(int i=0;i<l->qtd;i++){
            fprintf(arquivoCarro, "%s    ", vc[i].cpfDono);
            fprintf(arquivoCarro, "%s    ", vc[i].placa);
            fprintf(arquivoCarro, "%s    ", vc[i].renavan);
            fprintf(arquivoCarro, "%s    ", vc[i].corVeiculo);
            fprintf(arquivoCarro, "%s    ", vc[i].marca);
            fprintf(arquivoCarro, "%s    \n", vc[i].modelo);
        }
        fclose(arquivoCarro);
        printf("\n>> Arquivo ordenado com sucesso!\n");
    }    
}
void insere_pessoa(char proprietario[], char cpf[], char data[], cabPessoa * l, FILE * arquivoPessoa){
    listaPessoa * novo = (listaPessoa*)malloc(sizeof(listaPessoa));

    for(int i=0;i<strlen(proprietario);i++){
        novo->proprietario[i] = proprietario[i];
    }
    for(int i=0;i<strlen(cpf);i++){
        novo->cpf[i] = cpf[i];
    }

    for(int i=0;i<strlen(data);i++){
        novo->data[i] = data[i];
    }
    arquivoPessoa = fopen("basePessoa.txt", "a");

    fprintf(arquivoPessoa, "%s    ", novo->cpf);
    fprintf(arquivoPessoa, "%s    ", novo->proprietario);
    fprintf(arquivoPessoa, "%s    \n", novo->data);

    fclose(arquivoPessoa);

    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    l->qtd++;
    ordena_arquivo_pessoa(arquivoPessoa);
}

void insere_veiculo(char placa[], char renavam[], char corVeiculo[], char marca[], char modelo[], char cpfDono[], cabCarro * l, FILE * arquivoCarro){
    listaCarro * novo = (listaCarro*)malloc(sizeof(listaCarro));

    for(int i=0;i<strlen(placa);i++){
        novo->placa[i] = placa[i];
    }
    for(int i=0;i<strlen(renavam);i++){
        novo->renavan[i] = renavam[i];
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
    for(int i=0;i<strlen(cpfDono);i++){
        novo->cpfDono[i] = cpfDono[i];
    }
    arquivoCarro = fopen("baseVeiculo.txt", "a");

    fprintf(arquivoCarro, "%s    ", novo->cpfDono);
    fprintf(arquivoCarro, "%s    ", novo->placa);
    fprintf(arquivoCarro, "%s    ", novo->renavan);
    fprintf(arquivoCarro, "%s    ", novo->corVeiculo);
    fprintf(arquivoCarro, "%s    ", novo->marca);
    fprintf(arquivoCarro, "%s    \n", novo->modelo);

    fclose(arquivoCarro);

    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->inicio = novo;
    }
    l->qtd++;
    ordena_arquivo_carro(arquivoCarro);
}

int exclui_veiculo(char placa[], FILE * arquivoCarro){
    arquivoCarro = fopen("baseVeiculo.txt","r");
    FILE * tmp = fopen("temporarioExclusao.txt","w");
    char dados[1000];
    char placaBanco[10];

    if (!arquivoCarro) {
        printf(">> Veiculo nao cadastrado!\n");
        return -1;
    }
    
    for(int i = 0; i < 9; i++){
        placaBanco[i] = ' ';
    }
    
    while(fgets(dados, 1000, arquivoCarro)){
        int count = 0;
        while(dados[count] != ' '){
            count++;
        }
        int pos = 0;
        count+=4;
        while(dados[count] != ' '){
            placaBanco[pos] = dados[count];
            count++;
            pos+=1;
        }
            
        if((placaBanco[0] == placa[0]) && (placaBanco[1] == placa[1]) && (placaBanco[2] == placa[2]) && (placaBanco[3] == placa[3]) && (placaBanco[4] == placa[4]) && (placaBanco[5] == placa[5]) && (placaBanco[6] == placa[6]) && (placaBanco[7] == placa[7])){
           printf("****** Dado excluido com sucesso! ******\n");
        }else {
            fprintf(tmp , "%s    ", dados);
        }
    }
    fclose(arquivoCarro);
    fclose(tmp);    

    char dadosSalvar[1000];
    arquivoCarro = fopen("baseVeiculo.txt", "w");
    tmp = fopen("temporarioExclusao.txt", "r");

    while(fgets(dadosSalvar, 1000, tmp) != NULL){
        fprintf(arquivoCarro,"%s    ", dadosSalvar);
    }
    fclose(arquivoCarro);
    fclose(tmp); 

    return 1;
}

int cpf_isValid(char cpf[]){
    int valido = 0;
    if(strlen(cpf) == 11)
        return 1;
    return 0;
}

int procura_veiculo(char cpf[], FILE * arquivoCarro){

    arquivoCarro = fopen("baseVeiculo.txt","r");
    char tamanho[1000];
    int tam = 0;
    while(fgets(tamanho ,1000, arquivoCarro)){
        tam+=1;
    }
    fclose(arquivoCarro);
    char cpfBanco[1000];
    int achou = 0;
    printf("****************************\n Resultado da pesquisa \n****************************\n|  CPF  |  PLACA  |  RENAVAM  |  COR(CARRO)  |  MARCA  |  MODELO  |\n");    
    arquivoCarro = fopen("baseVeiculo.txt","r");
    if(tam < 2)
        tam = tam*2;    

    while(fgets(cpfBanco ,1000, arquivoCarro)){
        for(int i = 0; i < tam/2 ; i++){
            if((cpfBanco[0] == cpf[0]) && (cpfBanco[1] == cpf[1]) && (cpfBanco[2] == cpf[2]) && (cpfBanco[3] == cpf[3]) && (cpfBanco[4] == cpf[4]) && (cpfBanco[5] == cpf[5]) && (cpfBanco[6] == cpf[6]) && (cpfBanco[7] == cpf[7]) && (cpfBanco[8] == cpf[8]) && (cpfBanco[9] == cpf[9]) && (cpfBanco[10] == cpf[10])){
                printf("%s", cpfBanco);
                achou = 1;
            }
        }
    }
    if (achou == 0) {
        printf(">> Nenhum veículo encontrado para este cpf!\n");
    }
    
    fclose(arquivoCarro);
    return achou;
}

int altera_dados_veiculo(FILE * arquivoCarro, FILE * arquivoPessoa, char placa[]){
    arquivoCarro = fopen("baseVeiculo.txt", "r");
    FILE * tmp = fopen("temporarioEdicao.txt","w");
    char placaCarro[10], renavan[11], corVeiculo[20], marca[50], modelo[50], proprietario[50], data[15], cpfDono[20];
    int achou = 0;
    char dados[1000];
    char placaBanco[10];
    while(fgets(dados, 1000, arquivoCarro) != NULL){
        int count = 0;
        while(dados[count] != ' '){
            count++;
        }
        int pos = 0;
        count+=4;
        while(dados[count] != ' '){
            placaBanco[pos] = dados[count];
            count++;
            pos+=1;
        }
            
        if((placaBanco[0] == placa[0]) && (placaBanco[1] == placa[1]) && (placaBanco[2] == placa[2]) && (placaBanco[3] == placa[3]) && (placaBanco[4] == placa[4]) && (placaBanco[5] == placa[5]) && (placaBanco[6] == placa[6]) && (placaBanco[7] == placa[7])){
           achou = 1;
           printf("****************************\n Digite os novos dados \n****************************\n");
           printf("CPF:\n");
           scanf("%s", cpfDono);
            if(pessoa_exist(arquivoPessoa, cpfDono) == 1){    
                printf("PLACA:%s\n", placaBanco);

                printf("RENAVAM:\n");
                scanf("%s", renavan);

                printf("COR DO VEÍCULO:\n");
                scanf("%s", corVeiculo);

                printf("MARCA:\n");
                scanf("%s", marca);

                printf("MODELO\n");
                scanf("%s",modelo);

                fprintf(tmp,"%s    %s    %s    %s    %s    %s    ", cpfDono, placaBanco, renavan, corVeiculo, marca, modelo);
                printf("ALERTA: >> Dados alterados com sucesso!\n");

            } else {
                printf("ALERTA: >> CPF nao cadastrado!\n");
                return -1;
            }
            
        }else {
            fprintf(tmp,"%s", dados);
        }
        if(!achou){
            printf("ALERTA: >> Placa nao encontrado!\n");
        }
    }
    fclose(tmp);
    fclose(arquivoCarro);    

    tmp = fopen("temporarioEdicao.txt","r");
    arquivoCarro = fopen("baseVeiculo.txt", "w");
    char dadosTemporario[1000];
    while(fgets(dadosTemporario, 1000, tmp) != NULL){
        fprintf(arquivoCarro,"%s", dadosTemporario);
    }
    fclose(tmp);
    fclose(arquivoCarro);
    return 1;
}

void exclui_pessoa(FILE * arquivoPessoa, FILE * arquivoCarro, char cpf[]){
    arquivoCarro = fopen("baseVeiculo.txt", "r");
    FILE * tmp = fopen("temporarioExclusao.txt","w");
    char dados[1000];
    char cpfBanco[11];
    int achou = 0, excluiu = 0;

    // Exclui veiculo associado
    while(fgets(dados, 1000, arquivoCarro) != NULL){
        int count = 0;
        while(dados[count] != ' '){
            cpfBanco[count] = dados[count];
            count++;
        }
        if((cpfBanco[0] == cpf[0]) && (cpfBanco[1] == cpf[1]) && (cpfBanco[2] == cpf[2]) && (cpfBanco[3] == cpf[3]) && (cpfBanco[4] == cpf[4]) && (cpfBanco[5] == cpf[5]) && (cpfBanco[6] == cpf[6]) && (cpfBanco[7] == cpf[7]) && (cpfBanco[8] == cpf[8]) && (cpfBanco[9] == cpf[9]) && (cpfBanco[10] == cpf[10])){
        }else{
            fprintf(tmp,"%s", dados);
        }
        
    }
    fclose(tmp);
    fclose(arquivoCarro);

    arquivoCarro= fopen("baseVeiculo.txt","w");
    tmp = fopen("temporarioExclusao.txt", "r");
    // Salva os que nao foram exluidos na base dadoVeiculo.txt
    while(fgets(dados, 1000, tmp) != NULL){
        fprintf(arquivoCarro,"%s", dados);
    }
    fclose(tmp);
    fclose(arquivoCarro);

    arquivoPessoa = fopen("basePessoa.txt", "r");
    tmp = fopen("arquivoExclusao.txt", "w");
    // Exclui pessoa
    while(fgets(dados, 1000, arquivoPessoa) != NULL){
        int count = 0;
        while(dados[count] != ' '){
            cpfBanco[count] = dados[count];
            count++;
        }
        if((cpfBanco[0] == cpf[0]) && (cpfBanco[1] == cpf[1]) && (cpfBanco[2] == cpf[2]) && (cpfBanco[3] == cpf[3]) && (cpfBanco[4] == cpf[4]) && (cpfBanco[5] == cpf[5]) && (cpfBanco[6] == cpf[6]) && (cpfBanco[7] == cpf[7]) && (cpfBanco[8] == cpf[8]) && (cpfBanco[9] == cpf[9]) && (cpfBanco[10] == cpf[10])){
            excluiu = 1;
        }else{
            fprintf(tmp,"%s", dados);
        }   
    }
    fclose(tmp);
    fclose(arquivoPessoa);

    tmp = fopen("arquivoExclusao.txt", "r");
    arquivoPessoa = fopen("basePessoa.txt", "w");

    // Salva as pessoas que nao foram excluidas em dadosPessoa.txt
    while(fgets(dados, 1000, tmp) != NULL){
        fprintf(arquivoPessoa,"%s", dados);
    }
    if(excluiu){
        printf("ALERTA: >> Dados deletados com sucesso!\n");
    } else {
        printf("ALERTA: >> Cpf nao encontrado!\n");
    }
    fclose(tmp);    
    fclose(arquivoPessoa);
}

int main() {

cabCarro * salvaCarro =  (cabCarro*)malloc(sizeof(cabCarro));
cabPessoa * salvaPessoa = (cabPessoa*)(malloc(sizeof(cabPessoa)));
salvaCarro->qtd = 0;
salvaCarro->inicio = NULL;
salvaPessoa->fim = NULL;
salvaPessoa->qtd = 0;
salvaPessoa->inicio = NULL;
salvaPessoa->fim = NULL;
int val, op, id, ano;
char placa[10], renavan[11], corVeiculo[20], marca[50], modelo[50],proprietario[50], rg[20], data[15], cpfDono[20];
char dadosBanco[1000], idRegistro[10], cpf[20];
char cpfProp[11];
FILE *arquivoPessoa;
FILE *arquivoCarro;
FILE *arquivoTemporario;
FILE * isExist;

while (1) {
    printf("______________________________________________\n");
    printf("                    MENU                      \n");
    printf("______________________________________________\n");
    printf(">> ALERTA: Evite encerrar o programa utilizando o 'CTRL+C', pode ser que ao forçar o encerramento do programa algum arquivo seja corrompido!  \n");
    printf("1-Cadastrar Pessoa\n2-Cadastrar Veiculo\n3-Listar todas as pessoas cadastradas\n4-Listar todos os veículos cadastrados\n5-Procurar veículo\n6-Alterar dados de veiculo\n7-Excluir registro de veículo\n8-Excluir pessoa cadastrada\n0-Sair\n");
    printf("______________________________________________\n");    
    printf("OP: ");
    scanf("%d",&op);
    getchar();
    switch (op) {
        case 1:
            printf("********************\nCadastro De Pessoa\n********************\n");
            
            printf("Digite o cpf do proprietario (11 NUMEROS):\n");
            scanf("%s",cpf);
            if(cpf_isValid(cpf)){
                printf("Digite o nome do proprietario (EXEMPLO: EDUARDO):\n");
                scanf("%s",proprietario);

                printf("Digite a data de nascimento do proprietario (FORMATO: DD/MM/AAAA):\n");
                scanf("%s",data);

                insere_pessoa(proprietario, cpf, data, salvaPessoa, arquivoPessoa);
            } else {
                printf(">> CPF inválido!\n");
            }

            break;
        case 2:
            printf("********************\nCadastro De Veículo\n********************\n");
            printf("Digite o cpf do proprietário:\n");
            scanf("%s",cpfDono);

            FILE * exist = fopen("basePessoa.txt","r");
            fclose(exist);

            if(exist){
                if(pessoa_exist(arquivoPessoa, cpfDono)){
                    printf("Digite a placa do veículo (FORMATO: XXX-1234):\n");
                    scanf("%s",placa);

                    printf("Digite o renavam  do veículo (MAXIMO 10 NUMEROS):\n");
                    scanf("%s",renavan);

                    printf("Digite a cor do veículo:\n");
                    scanf("%s",corVeiculo);

                    printf("Digite a marca do veículo:\n");
                    scanf("%s",marca);

                    printf("Digite o modelo do veículo:\n");
                    scanf("%s",modelo);

                    insere_veiculo(placa, renavan, corVeiculo, marca, modelo, cpfDono, salvaCarro, arquivoCarro);
                }else{
                    printf(">> CPF nao cadastrado!\n>> Veículo nao inserido!\n");
                }
            }else{
                printf(">> É necessário possuir pessoas cadastradas para adicionar um veículo!\n");
            }
            break;
        case 3:
            printf("****************************\n Registros de Pessoas\n****************************\n|  CPF  |  NOME  |  DATA DE NASCIMENTO  |\n");    
            arquivoPessoa = fopen("basePessoa.txt", "r");
            if(arquivoPessoa){
                char dadosDoBancoPessoa[1000];
                while(fgets(dadosDoBancoPessoa, 1000, arquivoPessoa) != NULL){
                    printf("%s", dadosDoBancoPessoa);
                }
            }
            printf("\n");
            
            break;
        case 4:
            printf("****************************\n Registros de veículos \n****************************\n|  CPF  |  PLACA  |  RENAVAM  |  COR(CARRO)  |  MARCA  |  MODELO  |\n");    
            arquivoCarro = fopen("baseVeiculo.txt", "r");
            if(arquivoCarro){
                char dadosDoBancoCarro[1000];
                while(fgets(dadosDoBancoCarro, 1000, arquivoCarro) != NULL){
                    printf("%s", dadosDoBancoCarro);
                }
            }
            printf("\n");
            break;
        case 5:   
            isExist = fopen("baseVeiculo.txt","r");
            fclose(isExist);   
            if(isExist){  
                printf("Digite o cpf do proprietário:\n");
                scanf("%s", cpfProp);
                getchar();
                procura_veiculo(cpfProp, arquivoCarro);
            } else {
                printf("ALERTA: Nao existe veículos cadastrados!\n");
            }
            break;
        case 6:
            isExist = fopen("baseVeiculo.txt","r");
            fclose(isExist);
            if(isExist){
                printf("Digite a placa do veículo:\n");
                scanf("%s", placa);
                altera_dados_veiculo(arquivoCarro, arquivoPessoa, placa);
            } else {
                printf("ERRO: >> Verifique se há veículos cadastrados!\n");
            }
            
            break;
        case 7:
            isExist = fopen("baseVeiculo.txt","r");
            fclose(isExist);
            if(isExist){    
                printf("Digite a placa do veículo (FORMATO: XXX-1234):\n");
                scanf("%s", placa);
                getchar();

                exclui_veiculo(placa, arquivoCarro);
            } else {
                printf("ERRO: >> Nao existe veiculos cadastrados na base!\n");
            }
            break;
        case 8:
            printf(">> ALERTA: Ao excluir o registro de uma pessoa, todos os veículos associados a ela serao apagados!\n");
            char option[5];
            printf("1- Digite 'S' para continuar\n2-Digite 'N' para voltar ao menu inicial\nOpcao: \n");
            scanf("%s", option);
            isExist = fopen("basePessoa.txt","r");
            fclose(isExist);
            if(isExist){
                if(strcmp(option ,"s") == 0 || strcmp(option ,"S") == 0){
                    printf("Digite o cpf:\n");
                    scanf("%s", cpf);
                    exclui_pessoa(arquivoPessoa, arquivoCarro, cpf);
                }
            } else {
                printf("ERRO: >> Nao existe pessoas cadastradas no sistema!\n");
            }
            break;
        case 0:
            exit(0);
            break;
        default:
            printf(">> Opção inválida!\n");
            break;
    }
}
  return 0;
}