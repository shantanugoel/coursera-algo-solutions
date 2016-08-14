#include <stdio.h>

#define TEST 0

int a[10000001] = {0};

int solve(int n)
{
  if(n < 2)
  {
    return n;
  }
  else
  {
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
      a[i] = (a[i - 1] + a[i - 2]) % 10;
    }
  }
  return a[n];
}

int test()
{
  for(int i = 0; i <= 10000000; ++i)
  {
    printf("%d: %d\n", i, solve(i));
  }
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
