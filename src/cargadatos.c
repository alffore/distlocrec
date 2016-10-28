#include "distloc.h"

extern PLocalidad ploc;
extern void cargaArchivoLocs(char *);
extern void cargaArchivoRecs(char *);


int eml2conapo(int, int, int);
double deg2rad(double);
void cesfe2carte(double lat, double lng, double *res);


/**
* Función que carga los datos de localidades
*/
void cargaArchivoLocs(char * archlocs){
  int est;
  int mun;
  int loc;

  double lat,lng;
  double latr,lngr;
  double res[3];

  double *res2=(double *)malloc(3*sizeof(double));


  int pob;

  FILE *fh=fopen(archlocs,"r");

  PLocalidad p;

int i=0;
  while(fscanf(fh,"%d %d %d %lf %lf %d",&est,&mun,&loc,&lat,&lng,&pob)!=EOF){


    latr=deg2rad(lat);
    lngr=deg2rad(lng);
    cesfe2carte(latr,lngr,res2);

    p=(ploc+i);

    p->est=est;
    p->mun=mun;
    p->loc=loc;
    p->cconapo=eml2conapo(est,mun,loc);

    p->lat=lat;
    p->lng=lng;

    p->x=*(res2);
    p->y=*(res2+1);
    p->z=*(res2+2);

    p->pob=pob;

    i++;
  }


  fclose(fh);

free(res2);

}


void cargaArchivoRecs(char * archrecs){

}


int eml2conapo(int e, int m, int l){
  return (e*1000+m)*1000+l;
}

double deg2rad(double x){
  return M_PI*x/180.00;
}


void cesfe2carte(double lat, double lng, double *res){

    *(res)=cos(lng)*sin(lat);
    *(res+1)=sin(lng)*sin(lat);
    *(res+2)=cos(lat);


}
