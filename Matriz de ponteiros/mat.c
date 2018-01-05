#include <stdio.h>
#include <stdlib.h>

int main(void){
int **m;
int i,j;

m = (int**)malloc(2*(sizeof(int*)));
for(i = 0;i<2;i++){
  *(m+i) = (int*)malloc(2*(sizeof(int)));
  for(j=0;j<2;j++){
    printf("Valor [%d][%d]:",i,j);
    scanf("%d",&m[i][j]);
  }
}

for (i=0;i<2;i++) {
  for(j=0;j<2;j++){
    printf("%d ",m[i][j]);
  }
  printf("\n");
}

  return 0;
}
