#include <stdio.h>

int main(void){

  const float PI = 3.14f;
  const float r = 10.0f;
  
  float volume = (4.0f / 3.0f) * PI * ( r * r * r);
  printf("Volume = %.2f\n", volume);
  return 0;
}
