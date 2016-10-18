#include <stdio.h>
#include <stdlib.h>

struct Localidad{
  int cconapo;
  double lat;
  double lng;

  double dist_museo;
  int cconapo_museo;
};

typedef struct Localidad* PLocalidad;

struct Recurso{
  int cconapo;
  double lat;
  double lng;
};

const int cantlocs=200000;

PLocalidad ploc;

struct Recurso *prec;


int main(void){

  ploc=(PLocalidad)malloc(cantlocs*sizeof(struct Localidad));

  for(size_t i=0;i<cantlocs;i++){
    (ploc+i)->cconapo=i*10;
  }

  for(size_t i=0;i<cantlocs;i++){
    printf("%ld cconapo: %d\n",i,(ploc+i)->cconapo);
  }


  printf("bytes: %ld\n",cantlocs*sizeof(struct Localidad));

  free(ploc);
  return 0;
}
