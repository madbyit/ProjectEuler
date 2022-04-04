/*

You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.
A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Deklaration
bool is_it_leap_year(int year);
bool leap_year = false;
int count_leap_year = 0;

int main()
{
  int day_in_week[7] = {1,2,3,4,5,6,7};
  int nr_of_days_in_months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int num_of_months = sizeof(nr_of_days_in_months)/sizeof(int);

  int test_year = 1900; //1 jan = monday
  int end_year = 2000;
  bool is_leap_year = false;
  int countsundays = 0;
  int weekday = 0; //1 jan 1900 start with monday
  int day = 0;

  for(int year = test_year; year<=end_year; year++)
  {
    is_leap_year = is_it_leap_year(year);
    if(is_leap_year)
    {
      nr_of_days_in_months[1] = 29;
    }

for (int month = 1; month<=num_of_months; month++)
    {
      int month_number = nr_of_days_in_months[month-1];

      int the_first = 1;
      int counter = 0;

      do{
        day = day_in_week[weekday];
        weekday++;
        counter++;

        if(weekday == 6 && year > test_year && the_first == 1)
        {
          countsundays++;
        }

        if(weekday > 6)
        {
          weekday = 0;
        }

        the_first++;

      }while(counter < month_number);

    }
  }

  printf("TOTAL SUM OF SUNDAYS THAT FALLS ON THE FIRST EACH MONTH: %d\n", countsundays);
  return 0;
}


bool is_it_leap_year(int year)
{
  if(year%4 == 0)
  {
    if( year%100 == 0)
    {
      // year is divisible by 400, hence the year is a leap year
      if ( year%400 == 0)
        leap_year = true;
      else
        leap_year = false;
    }
  }
  else
    leap_year = false;
  
  return leap_year;
}
