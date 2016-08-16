#include <stdio.h>

#define TEST 0

int coins[] = {10, 5, 1};

int solve(int n)
{
  int count = 0;
  for(int i = 0; i < n;)
  {
    for(int j = 0; j < 3; ++j)
    {
      if(coins[j] <= (n - i))
      {
        i += coins[j];
        count++;
        break;
      }
    }
  }
  return count;
}

int test()
{
}

int main()
{
  int n = 0, res = 0;
#if TEST == 0
  res = scanf("%d", &n);
  printf("%d", solve(n));
#else
  test();
#endif
  return 0;
}
