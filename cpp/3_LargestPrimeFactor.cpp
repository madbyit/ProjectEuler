/*The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/
#include <stdio.h>
using namespace std;

int LargestPrime()
{
  long long insert = 600851475143;
  int i = 3; // start at 3 for primes... we can do this since subject is ODD
  int highest = 0;

  long long number = insert;

  do {

    while (!(number % i)) // while no remainder
    {
      number /= i;  // divide and replace
      highest = i;
    }

    i +=2 ; // skip all even numbers since not prime

  } while(number != 1);

  return highest;
}

int main (void)
{
  printf("%d\n", LargestPrime());
  return 0;
}
 