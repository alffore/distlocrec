#include <stdlib.h>
#include <stdio.h>

int main(void){

  int est;
  int mun;
  int loc;

  float lat;
  float lng;

  int tipo;

  FILE * fh=NULL;


  fh=fopen("demo_datos.txt","r");

  fscanf(fh,"%d %d %d %f %f %d",&est,&mun,&loc,&lat,&lng,&tipo);

  printf("e: %d,lat: %f\n",est,lat);

  fclose(fh);

  return 0;
}
