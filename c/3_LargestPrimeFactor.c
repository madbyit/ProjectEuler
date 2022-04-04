#include <stdio.h>

//The prime factors of 13195 are 5, 7, 13 and 29.What is the largest prime factor of the number 600851475143 ?

int main (void)
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
   printf("highest = %d\n", highest );

  }
  i +=2 ; // skip all even numbers since not prime

} while(number != 1);



 printf ("Highest prime factor of %lld is %d\n", insert, highest);
 return 1;
}
