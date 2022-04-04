/*
  The sum of the squares of the first ten natural numbers is,
  12 + 22 + ... + 102 = 385
  The square of the sum of the first ten natural numbers is,

  (1 + 2 + ... + 10)2 = 552 = 3025
  Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

  Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <stdio.h>
#include <math.h>

int main ()
{
double difference = 0;
double sumofsquares = 0;
double sum = 0;
double squareofthesum = 0;

for (int i = 1; i <= 100; i++)
{
  sum += i;
  squareofthesum = pow(sum,2);
  sumofsquares += pow(i, 2);
}

difference = squareofthesum-sumofsquares;


 printf ("The difference between sum of the squares of the first hundred natural numbers and the square of the sum is: %f\n", difference);
 return 1;
}
