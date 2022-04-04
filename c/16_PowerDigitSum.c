

/*
2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 21000?

NOTE: need -lm flag to compile
NOTE: if use of GMP library, the flag -lgmp must be used
*/


#include <stdio.h>
#include <gmp.h>

int main()
{
    mpz_t n;
    mpz_init(n);
    mpz_ui_pow_ui(n,2,1000);

    int result = 0;
    while (mpz_cmp_ui(n,0))
    {
        result += mpz_fdiv_q_ui(n,n,10);
    }

    printf("%d\n", result);

    return 0;
}

/*
//OTHER SOLUTION
#include <stdio.h>

#include <math.h>
#include <string.h>

int main()
{
  int base = 2;
  int expo = 1000;
  double result = pow(base, expo);
  char result_str[500];
  int sum = 0;

  sprintf(result_str, "%.0f", result); //convert result to string

  //loop through string, convert to integer, sum the integers
  for (int i = 0; i < strlen(result_str); i++ )
  {
    sum += result_str[i] - '0';
  }

  printf("Value of %d^%d = %.f\n", base, expo, result);
  printf("The integer has %ld digits.\n", strlen(result_str) );
  printf("The sum of all digits is: %d\n", sum);
  return 0;
}
*/
