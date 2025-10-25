#include <stdio.h>

int main (void){

  float x;

  printf("Enter value for x: ");
  scanf("%f", &x);

  float polynomial = ((((3*x+2)*x-5)*x-1)*x+7)*x-6;

  printf("Result: %.2f\n", polynomial);
  
  return 0;

}
