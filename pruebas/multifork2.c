#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



/*
http://stackoverflow.com/questions/1381089/multiple-fork-concurrency
*/

int main(void){
	int numberOfChildren = 8;
	pid_t *childPids = NULL;
	pid_t p;

	/* Allocate array of child PIDs: error handling omitted for brevity */
	childPids = (pid_t*) malloc(numberOfChildren * sizeof(pid_t));

	/* Start up children */
	for (int ii = 0; ii < numberOfChildren; ++ii) {
	   if ((p = fork()) == 0) {
	      // Child process: do your work here
	      //
	      printf("Hijo: %d %d\n",ii,getpid());
	      exit(0);
	   }
	   else {
	      childPids[ii] = p;
	   }
	}

	/* Wait for children to exit */
	int stillWaiting;
	do {
	   stillWaiting = 0;
	    for (int ii = 0; ii < numberOfChildren; ++ii) {
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

	/* Cleanup */
	free(childPids);


}
