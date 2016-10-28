#include <stdio.h>
#include <stdlib.h>

void f1(int a);
void f2(int* a);

int main(void){


  int b=5;


  //f1(b);
  f2(&b);

  printf("%d\n",b);

  return 0;

}

void f1(int a){

  a++;
}


void f2( int *a){

  (*a)++;

}
