/*
PROBLEM:
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>

// Declarations
static int is_palindromic(unsigned int n);

// MAIN
int main(void)
{
  unsigned int val1, val2, largestpalindrome = 0;

  for (val1 = 100; val1 <= 999; val1++) {

    for (val2 = 100; val2 <= 999; val2++) {
      unsigned int result = val1*val2;

      if (is_palindromic(result) && result > largestpalindrome) {
        largestpalindrome = result;
      }

    }
  }
  printf("Largest Palindrome =%u\n", largestpalindrome);
  return 0;
}

// Definitions
int is_palindromic(unsigned int n)
{
  unsigned int reversed = 0, t = n;

  while (t) {
    reversed = 10*reversed + (t % 10);
    t /= 10;
  }
  return reversed == n;
}
