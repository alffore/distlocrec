#include "distloc.h"

extern void calculoP(int);
double distLocRec(PLocalidad , PRecurso );




extern PLocalidad ploc;
extern PRecurso prec;

extern int cantiloc;
extern int cantirec;

extern const int NumHilos;
extern const double RT;



/**
*
*/
void calculoP(int pos){
  int j;
  int i;

  double daux;

  for(j=pos;j<cantiloc;j+=NumHilos){

    for(i=0;i<cantirec;i++){




      daux=distLocRec(ploc+j,prec+i);

      if((ploc+j)->cconapo==151100001){
        printf("%d => %d :: %lf\n",(ploc+j)->cconapo,(prec+i)->cconapo,daux);
      }

      if((ploc+j)->dist[(prec+i)->tipo]>daux){
        (ploc+j)->dist[(prec+i)->tipo]=daux;
        (ploc+j)->c[(prec+i)->tipo]=(prec+i)->cconapo;
      }

    }
  }
}

/**
*
*/
double distLocRec(PLocalidad p, PRecurso r){
  double d=(p->x*r->x);
  d+=(p->y*r->y);
  d+=(p->z*r->z);

  d=(d<-1.0)?-1.0:d;
  d=(d>1.0)?1.0:d;

  return acos(d);

}
