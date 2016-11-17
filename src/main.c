#include "distloc.h"


extern void cargaArchivoLocs(char *);
extern void cargaArchivoRecs(char *);
extern void escribeSalida(void);
extern void calculoP(int);


const double RT=6371008.8;
const int NumHilos=8;

PLocalidad ploc;
PRecurso prec;

int cantiloc;
int cantirec;

extern int indexIP[23];



int main(int cargs, char **args){

  pid_t *childPids = NULL;
  pid_t p;

	childPids = (pid_t*) malloc(NumHilos * sizeof(pid_t));

//int i;
int pos;
int stillWaiting;
int ii;

cantiloc=atoi(*(args+1));
cantirec=atoi(*(args+2));
char * archlocs=*(args+3);
char * archrecs=*(args+4);



ploc=(PLocalidad) mmap(NULL, sizeof(sLocalidad)*cantiloc, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);
prec=(PRecurso) mmap(NULL, sizeof(sRecurso)*cantirec, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);

if(prec!=NULL && ploc!=NULL){

  cargaArchivoLocs(archlocs);
  cargaArchivoRecs(archrecs);



  for (pos = 0; pos < NumHilos; ++pos) {
	   if ((p = fork()) == 0) {

	      printf("Hijo: %d %d\n",pos,getpid());

        calculoP(pos);

	      exit(0);
	   }
	   else {
	      childPids[pos] = p;
	   }
	}

  /* Wait for children to exit */

  do {
     stillWaiting = 0;
      for (ii = 0; ii < NumHilos; ++ii) {
         if (childPids[ii] > 0) {
            if (waitpid(childPids[ii], NULL, WNOHANG) != 0) {
               /* Child is done */
               printf("hijo termino: %d %d\n",ii, childPids[ii]);

               childPids[ii] = 0;
            }
            else {
               /* Still waiting on this child */
               stillWaiting = 1;
            }
         }
         /* Give up timeslice and prevent hard loop: this may not work on all flavors of Unix */
         sleep(0);
      }
  } while (stillWaiting);



}

escribeSalida();



munmap(prec,sizeof(sRecurso)*cantirec);
munmap(ploc,sizeof(sLocalidad)*cantiloc);

if(childPids!=NULL)free(childPids);
  return 0;
}
