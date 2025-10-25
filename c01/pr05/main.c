#include <stdio.h>

int main (void){

  float x;

  printf("Enter value for x: ");
  scanf("%f", &x);

  float polynomial = 3*(x*x*x*x*x)+2*(x*x*x*x)-5*(x*x*x)-(x*x)-(7*x)-6;
  printf("Result: %.2f\n", polynomial);
  
  return 0;

}
