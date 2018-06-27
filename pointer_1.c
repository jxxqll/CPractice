#include <stdio.h>
#include <stdlib.h>


void countUp(int * a)
{
   (*a)++;
}

int main() {

  int c = 0;

  countUp(&c);

  printf("the value is %d", c);

  return 0;
}







