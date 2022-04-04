
/*
  If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
  If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
  NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
  The use of "and" when writing out numbers is in compliance with British usage.
*/
#include <stdio.h>
#include <string.h>

#define HUNDRED 7
#define AND 3
#define ONE_THOUSAND 11


char *the_first[10] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
char *the_teens[10] = { "", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
char *the_tens[10] = { "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

int getdigitlevel(int num)
{
   if (num < 10)
   {
      return strlen(the_first[num]);
   }
   else if(num > 10 && num < 20)
   {
      return strlen(the_teens[num%10]);
   }
   else if (num > 20 && num % 10)
   {
      return strlen(the_tens[num/10]) + strlen(the_first[num%10]);
   }
   else
   {
      return strlen(the_tens[num/10]);
   }
}


//MAIN
int main (void)
{

  //store numberofletters
  int numberofletters = 0;

  //run
  for (int i = 1; i <= 1000; i++) {

      if (i < 100) //below hundred
      {
        numberofletters += getdigitlevel(i);
      }
      else if (i >= 100 && i < 1000) //between hundred and less than thousand
      {
        if (i % 100) //Ex: onehundredandone, fivehundredandfiftyfive
        {
          numberofletters += strlen(the_first[i / 100]) + HUNDRED + AND + getdigitlevel(i % 100); //add AND
        }
        else //Ex: onehundred, twohundred, threehundred... etc
        {
          numberofletters += strlen(the_first[i / 100]) + HUNDRED;
        }
      }
      else //thousand
      {
        numberofletters += ONE_THOUSAND;
      }
  }
  printf("Number of letters that are counted: %d\n", numberofletters);

 return 1;
}
