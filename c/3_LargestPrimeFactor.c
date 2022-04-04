/*PROBLEM:
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?

NOTE:
Prime numbers are numbers that have only 2 factors: 1 and themselves. 
For example, the first 5 prime numbers are 2, 3, 5, 7, and 11. 
By contrast, numbers with more than 2 factors are call composite numbers.
*/

#include <stdio.h>

int main (void)
{
  long long insert = 600851475143;
  int i = 3; // start at 3 for primes
  int highest = 0;

  long long number = insert;

  do 
  {
    while (!(number % i)) // while no remainder
    {
      number /= i;
      highest = i;
    }
    i +=2 ; // skip all even numbers since they are not prime numbers

  } while(number != 1);

 printf("Highest prime factor of %lld is %d\n", insert, highest);
 return 0;
}

//Outputs:
// 600851475143 / 71 = 8462696833
// 8462696833 / 839 = 10086647
// 10086647 / 1471 = 6857
// 6857 / 6857 = 1
// Answer highest: 6857 is the highest prime factor