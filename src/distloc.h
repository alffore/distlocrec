#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>



#ifndef __DISTLOC_H__
#define __DISTLOC_H__

#define CANT_TIPOS_OC 24

//Definicion de la estructura de Localidad
struct Localidad{
  int est;
  int mun;
  int loc;

  int cconapo;
  double lat;
  double lng;

 //coordenas cartesianas
  double x;
  double y;
  double z;

  int pob;

  //distancias mínimas a recursos
  double dist[CANT_TIPOS_OC];

  //claves conapo a las localidades de los recursos
  int c[CANT_TIPOS_OC];
};

typedef struct Localidad sLocalidad;
typedef struct Localidad* PLocalidad;


struct Recurso{
  int est;
  int mun;
  int loc;

  int cconapo;
  double lat;
  double lng;

  double x;
  double y;
  double z;

  char stipo[22];
  int tipo;

  int id;
};

typedef struct Recurso sRecurso;
typedef struct Recurso* PRecurso;


struct Diccionario{
  char nombre[22];
};

typedef struct Diccionario sDiccionario;
typedef struct Diccionario* PDiccionario;


#endif
