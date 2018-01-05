#include <stdio.h>
#include <stdlib.h>

//Calcula a frequência e o percentual
float calculos(float T,float x){
float p;
p = 100*(T/x);
  return p;
}

int main()
{
    FILE * header;
    FILE * r;
    FILE * g;
    FILE * b;
    FILE * AnaliseCor;

    int l,c,i,j,fr=0,fg=0,fb=0;
    header = fopen("Header.txt","r");
    fscanf(header,"%d %d",&l,&c);
    fclose(header);

    r = fopen("r.txt","r");
    g = fopen("g.txt","r");
    b = fopen("b.txt","r");

    if((!r) || (!g) || (!b)){
      printf("Erro ao abrir arquivos RGB!\n");
      exit(0);
    }

    int **mr;
    int **mg;
    int **mb;

    mr = (int**)malloc(l*(sizeof(int*)));
    mg = (int**)malloc(l*(sizeof(int*)));
    mb = (int**)malloc(l*(sizeof(int*)));

    for(i=0;i<l;i++){
      *(mr+i) = (int*)malloc(c*(sizeof(int)));
      *(mg+i) = (int*)malloc(c*(sizeof(int)));
      *(mb+i) = (int*)malloc(c*(sizeof(int)));
        for(j=0;j<c;j++){
            fscanf(r,"%d ",&mr[i][j]);
            fscanf(g,"%d ",&mg[i][j]);
            fscanf(b,"%d ",&mb[i][j]);
            if(mr[i][j] == 255){
              fr++;
            }
            if(mg[i][j] == 255){
              fg++;
            }
            if(mb[i][j] == 255){
              fb++;
            }
        }
    }
    fclose(r);
    fclose(g);
    fclose(b);

AnaliseCor = fopen("AnaliseCor.csv","w");
if(!AnaliseCor){
  printf("Erro ao criar AnaliseCor.txt\n");
  exit(0);
}
float Pr,Pg,Pb,Tr=0,Tg=0,Tb=0,tot;
float Frt,Fgt,Fbt,aux;

//Soma total de cada canal
for(i=0;i<l;i++){
  for(j=0;j<c;j++){
    Tr +=mr[i][j];
    Tg +=mg[i][j];
    Tb +=mb[i][j];
  }
}
//Soma total dos 3 canais
tot=Tr+Tg+Tb;
//Produto da quantidade de linhas pela quantidade de colunas;
aux = l*c;

//Percentual
Pr = calculos(Tr,tot);
Pg = calculos(Tg,tot);
Pb = calculos(Tb,tot);

//Frequência
Frt = calculos(fr,aux);
Fgt = calculos(fg,aux);
Fbt = calculos(fb,aux);

fprintf(AnaliseCor,"Canal R: %.2lf %%, Puro: %.2f %%\n",Pr,Frt);
fprintf(AnaliseCor,"Canal G: %.2lf %%, Puro: %.2f %%\n",Pg,Fgt);
fprintf(AnaliseCor,"Canal B: %.2lf %%, Puro: %.2f %%\n",Pb,Fbt);
fclose(AnaliseCor);

    return 0;
}
