#include  <stdio.h>
#include <stdlib.h>

int main (int cargs, char **args){

  int i;
  printf("Cantidad argumentos: %d\n",cargs);

  for(i=0;i<cargs;i++){

    printf("Arg %d %s\n",i,*(args+i));

  }


  return 0;
}
