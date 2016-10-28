#include "distloc.h"

extern void calculoP(int);
double distLocRec(PLocalidad , PRecurso );
int distVecLocRec(PLocalidad , PRecurso );
void escanning(void);


extern PLocalidad ploc;
extern PRecurso prec;

extern int cantiloc;
extern int cantirec;

extern const int NumHilos;
extern const double RT;


void calculoP(int pos){
  int j;
  int i;

  double daux;
  int iaux;

  for(j=pos;j<cantiloc;j+=NumHilos){

    for(i=0;i<cantirec;i++){

      daux=distLocRec(ploc+j,prec+i);

      if((ploc+j)->dist[(prec+i)->tipo]>daux){
        (ploc+j)->dist[(prec+i)->tipo]=daux;
        (ploc+j)->c[(prec+i)->tipo]=(prec+i)->cconapo;
      }

    }


  }




}


double distLocRec(PLocalidad p, PRecurso r){
  double d=p->x*r->x;
  d+=p->y*r->y;
  d+=p->z * r->z;

  return acos(d);

}

/**
*
*/
void escanning(void){
  int i,j;
int dist;

  for(j=0;j<cantiloc;j++){
    for(i=0;i<cantirec;i++){
      dist=distVecLocRec(ploc+j,prec+i);
      if(dist==1){
        (ploc+j)->dist[(prec+i)->tipo]=0;
        (ploc+j)->c[(prec+i)->tipo]=(prec+i)->cconapo;
      }

    }
  }
}

int distVecLocRec(PLocalidad p, PRecurso r){

  if( p->lat - r->lat==0 &&  p->lng - r->lng ==0){
    return 1;
  }

  return 0;
}
