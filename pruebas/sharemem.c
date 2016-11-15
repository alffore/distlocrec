/*http://stackoverflow.com/questions/13274786/how-to-share-memory-between-process-fork*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int *glob_var;
int prueba;
int *mimemo;

int main(int num,char* args)
{




    glob_var = mmap(NULL, sizeof *glob_var, PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    mimemo  = mmap(NULL, sizeof(int)*2, PROT_READ | PROT_WRITE,MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    *glob_var = 1;

    prueba =2;

    *(mimemo+1)=1234;


    if (fork() == 0) {
        *glob_var = 5;
        prueba=0;
        *(mimemo+1)=5678;
        exit(EXIT_SUCCESS);
    } else {
        wait(NULL);
        printf("%d\n", *glob_var);
        printf("prueba %d\n", prueba);
        printf("mimemo %d\n", *(mimemo+1));
        munmap(mimemo,sizeof(int)*2);
        munmap(glob_var, sizeof *glob_var);

    }
    return 0;
}
