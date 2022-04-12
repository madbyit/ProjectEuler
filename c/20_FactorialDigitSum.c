/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Declarations */
#define sizeOfNumber 160
#define startVal 100
#define base 10
void init(int[]);
void factorial(int[],int);
int sumOfDigits(int[]);

/* MAIN */
int main()
{
    int number[sizeOfNumber]; //The number is treated as an array of single digits
    int sum;
    init(number);
    int num = startVal;
    factorial(number, num);
    //Getting the sum of the digits of the number
    sum = sumOfDigits(number);
    printf("The sum of the digits of %d! is: %d \n", startVal, sum);
    return 0;
}

/* Definitions */

// Initially, the number is 0 so all it's digits are set to zero.
void init(int number[])
{
    for(int i = 0; i < sizeOfNumber; i++)
    {
      number[i] = 0;
    }
}

// Finding the factorial by multiplying the digits
void factorial(int number[], int num)
{
    int i, msd, carry, replaceIndex, product;

    //'msd' keeps track of the position of the 'most significant digit' [msd] in the array - where the trailing zeroes end.
    msd = 0;
    number[msd] = 1; //If we don't do this, the answer will be 0.
    
    //This while loop calculates num! and stores it in number[]
    do
    {
        //This block performs multiplication of number[] with the current value of num and stores the result in num
        //The factorisation is done like how we do it by hand using carry
        carry = 0;
        for(i = 0; i <= msd; i++)
        {
            product = num*number[i] + carry;

            replaceIndex = product%base;

            carry = product/base; //Carry needs to be added when num is multiplied with the next most significant digit

            //The ith digit of number is rewritten now as the product%base we're working in. This case - 10
            number[i] = replaceIndex;

            // There is a carry in the MSD.
            if( (i == msd) && (carry > 0) )
            {
                msd++;
            }
        }
        num--;
    }while(num != 1);
}

//Finding the sum of all digits
int sumOfDigits(int number[])
{
    int i, sum = 0;
    //All the digits are initialised to zero so we don't need to know where MSB is to avoid extra terms being added
    for(i = 0; i < sizeOfNumber; i++)
    {
        sum = sum + number[i];
    }
    return sum;
}

/*ANSWER The sum of the digits of 100! is 648 . */