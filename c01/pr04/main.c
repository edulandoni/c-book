#include <stdio.h>

int main(void)
{
  float money;
  const float TAX_RATE = 5.0f;

  printf("Enter an amount: ");
  scanf("%f", &money);

  float total_with_tax = money + ((TAX_RATE * money) / 100.0f);

  printf("Whitn tax added: %.2f\n", total_with_tax);
  
  return 0;
}
