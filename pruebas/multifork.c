#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(void){

	int i=0;
	int j=0;

	int suma=0;


	int termino[5];

	pid_t padre;
	pid_t hijos[5];

	padre=getpid();

	printf("pid padre: %d\n",padre);

	for(i=0;i<5;i++){

		if(padre==getpid()){
			fork();
		}
		hijos[i]=getpid();
		printf("pid hijo: %d\n",hijos[i]);
		sleep(5);
		termino[i]=1;
	}

	if(padre==getpid()){
		while(1){
			suma=0;
			for(j=0;j<5;j++){
				suma+=termino[j];
			}

			if(suma==5){
				printf("todos terminaron\n");
				return 0;
			}
		}
	}

	return 0;
}
