#include <stdio.h>
using namespace std;

int main()
{

  int limit = 1000;
  int sum = 0;

  for(int i = 1; i < limit; i++)
  {
    if (((i % 3) == 0) || ((i % 5) == 0))
        sum += i;
  }
  printf("Sum = %d\n", sum);
return 0;
}
