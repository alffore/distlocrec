#include "distloc.h"

const double RT=6300000;
const int NumHilos=8;

PLocalidad ploc;
PRecurso prec;

int cantiloc;
int cantirec;




int main(int cargs, char **args){

int i;

cantiloc=atoi(*(args+1));
cantirec=atoi(*(args+2));
char * archlocs=*(args+3);
char * archrecs=*(args+4);

ploc=(PLocalidad) malloc(sizeof(sLocalidad)*cantiloc);
prec=(PRecurso) malloc(sizeof(sRecurso)*cantirec);

if(prec!=NULL && ploc!=NULL){

  cargaArchivoLocs(archlocs);

  for(i=0;i<10;i++){
    printf("x: %.10lf\n",(ploc+i)->x);
  }

}


if(ploc!=NULL)free(prec);
if(prec!=NULL)free(ploc);

  return 0;
}
