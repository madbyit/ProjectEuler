/*
n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

/*
#include <stdio.h>
#include <string.h>

int main()
{
  int sum = 0;
  int factordigit = 10;
  long long factor = factordigit;
  char str[20];



//Factoring n*(n-1)*(n-2)..*3*2*1.
  for (int i = factordigit-1; i > 0; i--)
  {
    factor *= i;
  }




sprintf(str, "%lld", factor);

for (int j = 0; j < strlen(str); j++)
{
  sum += str[j]-'0';
}

printf("Sum of the digits in the factor %lld = %d\n", factor, sum);
  return 0;
}
*/


#include <stdio.h>
#include <stdlib.h>

#define size_of_number 160
#define question 100
#define base 10

//Function Prototypes
void initialise(int[]);
int sum_of_digits(int[]);
void factorial(int[],int);

//Initially, the number is 0 so all it's digits are set to zero.
void initialise(int number[])
{
    for(int i = 0; i < size_of_number; i++){
      number[i] = 0;}
}

//Finding the factorial by multiplying the digits
void factorial(int number[], int num)
{
    int i, first_digit;
    int carry, replace, product;

    //First digit keeps track of the position of the 'most significant digit' in the array - where the trailing zeroes end.
    first_digit = 0;
    number[first_digit] = 1; //If we don't do this, the answer will be 0.

    //This while loop calculates num! and stores it in number[]
    while(num != 1)
    {
        //This block performs multiplication of number[] with the current value of num and stores the result in num
        //The multiplication is done like how we normally do it by hand.
        carry = 0;
        for(i = 0; i <= first_digit; i++)
        {
            product = num*number[i] + carry;
            replace = product%base; //Replace is what should be rewritten in the ith digit
            carry = product/base; //Carry needs to be added when num is multiplied with the next most significant digit

            //The ith digit of number is rewritten now as the product%base we're working in. This case - 10
            number[i] = replace;

            //If there is a carry in the MSB, then the number of digits will increase. For example, 112x10 = 1120. There is a carry in the MSB.
            if( (i == first_digit) && (carry > 0) )
            {
                first_digit++;
            }
        }

        num--;
    }
}

//Finding the sum of all digits
int sum_of_digits(int number[])
{
    int i, sum = 0;
    //All the digits are initialised to zero so we don't need to know where MSB is to avoid extra terms being added
    for(i = 0; i < size_of_number; i++)
    {
        sum = sum + number[i];
    }
    return sum;
}


//MAIN
int main()
{
    int number[size_of_number]; //The number is treated as an array of single digits, rather than an int data type
    int sum;
    initialise(number);
    factorial(number, question);
    //Getting the sum of the digits of the number
    sum = sum_of_digits(number);
    printf("The sum of the digits of %d! is %d.\n",question, sum);
    return 0;
}
