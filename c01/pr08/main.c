#include <stdio.h>

int main (void){

  float amount, interest, payment, monthly_rate;
  float balance1, balance2, balance3;

  printf("Enter amount of loan: ");
  scanf("%f", &amount);
 
  printf("Enter interest rate: ");
  scanf("%f", &interest);
  
  printf("Enter monthly payment: ");
  scanf("%f", &payment);

  monthly_rate = interest/12/100;

  balance1 = amount * ( 1 + monthly_rate ) - payment;
  balance2 = balance1 * ( 1 + monthly_rate ) - payment;
  balance3 = balance2 * ( 1 + monthly_rate ) - payment;

  printf("%.2f\n", balance1);
  printf("%.2f\n", balance2);
  printf("%.2f\n", balance3);

  return 0;

}
