#include "distloc.h"

extern void calculoP(int);
double distLocRec(PLocalidad , PRecurso );
int distVecLocRec(PLocalidad , PRecurso );
void escanning(int);


extern PLocalidad ploc;
extern PRecurso prec;

extern int cantiloc;
extern int cantirec;

extern const int NumHilos;
extern const double RT;

extern int indexIP[23];
/**
*
*/
void calculoP(int pos){
  int j;
  int i;

  double daux;


/*  escanning(pos);

return ;*/

  for(j=pos;j<cantiloc;j+=NumHilos){

    for(i=0;i<cantirec;i++){

/*      if((ploc+j)->dist[(prec+i)->tipo]==0 && (ploc+j)->c[(prec+i)->tipo]>1000000){
        i=indexIP[(prec+i)->tipo]+1;
        if(i>=cantirec)break;
      }*/

      daux=distLocRec(ploc+j,prec+i);

      if((ploc+j)->dist[(prec+i)->tipo]>daux){
        (ploc+j)->dist[(prec+i)->tipo]=daux;
        (ploc+j)->c[(prec+i)->tipo]=(prec+i)->cconapo;
      }

    }


  }




}


double distLocRec(PLocalidad p, PRecurso r){
  double d=(p->x*r->x);
  d+=(p->y*r->y);
  d+=(p->z * r->z);

  return acos(d);

}

/**
*
*/
void escanning(int pos){
  int i,j;
  int dist;

  for(j=pos;j<cantiloc;j+=NumHilos){
    for(i=0;i<cantirec;i++){
      dist=distVecLocRec(ploc+j,prec+i);
printf("%d %d %d::: %d %d\n",getpid(),pos,dist,(ploc+j)->cconapo,(prec+i)->cconapo);

      if(dist==1){
        (ploc+j)->dist[(prec+i)->tipo]=0;
        (ploc+j)->c[(prec+i)->tipo]=(prec+i)->cconapo;
      }

    }
  }
}

int distVecLocRec(PLocalidad p, PRecurso r){

  if( (p->lat - r->lat)==0 &&  (p->lng - r->lng) ==0){
    return 1;
  }

  return 0;
}
