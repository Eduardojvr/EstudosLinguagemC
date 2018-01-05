#include <stdio.h>
#include <stdlib.h>

int main(){

char lateral='|',linhas='-';
int i,j,l,c,cont=0;
char m[5][5];
int t=0;
char jogador1[50],jogador2[50];
int est = 3;
printf("#####################\n   JOGO DA VELHA\n#####################\n\n");


for(i=0;i<5;i++){
  for(j=0;j<5;j++){
    if(t == 1 || t == 3 || t == 11 || t == 13 || t == 21 || t == 23){
      m[i][j]=lateral;
    }else if(t == 5 || t == 6 || t == 7 || t == 8 || t== 9 || t == 15 || t == 16 || t == 17 || t == 18 || t==19){
        m[i][j]=linhas;
      }else{
        m[i][j] = ' ';
      }
  t++;
}

}
printf("Nome do jogador 1:");
scanf("%s",jogador1);
printf("Nome do jogador 2:");
scanf("%s",jogador2);

t=0;

while(cont != 9){
  printf("Posições válidas [linha,coluna]:[0,0] [0,2] [0,4] [2,0] [2,2]\n                                [2,4] [4,0] [4,2] [4,4]\n");
  if(t == 0){
    printf("%s ",jogador1);
  }else{
    printf("%s ",jogador2);
  }
    printf("Digite a linha:");
    scanf("%d",&l);
    printf("Digite a coluna:");
    scanf("%d",&c);
    if(((l == 0 && c == 0) || (l == 0 && c == 2) || (l == 0 && c == 4) ||
    (l == 2 && c == 0) || (l == 2 && c == 2) || (l == 2 && c == 4) ||
    (l == 4 && c == 0) || (l == 4 && c == 2) || (l == 4 && c == 4)) && ((m[l][c] != 'O') && (m[l][c] != 'x'))){
      if(t ==0 ){
        m[l][c] = 'O';
    }else{
        m[l][c] = 'x';
    }
    for(i=0;i<5;i++){
      for(j=0;j<5;j++){
        printf("%c ",m[i][j]);
      }
      printf("\n");
    }
    if(t == 1){
      t=0;
    }else{
      t=1;
    }
    cont++;
  }else{
    printf("Posição inválida!A posição já foi escolhida ou não existe!\n");
  }
  if((m[0][0] == 'x' && m[0][2]== 'x' && m[0][4] == 'x') || (m[2][0]== 'x' && m[2][2]== 'x' && m[2][4]== 'x')
  || (m[4][0]== 'x' && m[4][2]== 'x' && m[4][4]== 'x') || (m[0][0]== 'x' && m[2][0]== 'x' && m[4][0]== 'x')
  || (m[0][2]== 'x' && m[2][2]== 'x' && m[4][2]== 'x') || (m[0][4]== 'x' && m[2][4]== 'x' && m[4][4]== 'x')
  || (m[0][0]== 'x' && m[2][2]== 'x' && m[4][4]== 'x') || (m[0][4]== 'x' && m[2][2]== 'x' && m[4][0]== 'x')){
    printf("\nO jogador %s venceu!\n",jogador2 );
    est = 1;
    break;
  }else if(((m[0][0] == 'O' && m[0][2]== 'O' && m[0][4] == 'O') || (m[2][0]== 'O' && m[2][2]== 'O' && m[2][4]== 'O')
  || (m[4][0]== 'O' && m[4][2]== 'O' && m[4][4]== 'O') || (m[0][0]== 'O' && m[2][0]== 'O' && m[4][0]== 'O')
  || (m[0][2]== 'O' && m[2][2]== 'O' && m[4][2]== 'O') || (m[0][4]== 'O' && m[2][4]== 'O' && m[4][4]== 'O')
  || (m[0][0]== 'O' && m[2][2]== 'O' && m[4][4]== 'O') || (m[0][4]== 'O' && m[2][2]== 'O' && m[4][0]== 'O'))){
    printf("\nO jogador %s venceu!\n",jogador1 );
    est = 2;
    break;
  }
}
if(est == 3){
  printf("\nEmpate!\n");
}

  return 0;
}
