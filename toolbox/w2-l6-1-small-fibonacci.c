#include <stdio.h>

#define TEST 0

int a[46] = {0};

int calculate_fib(int n)
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
      a[i] = a[i - 1] + a[i - 2];
    }
  }
  return a[n];
}

int test()
{
  int i = 0;
  for(i = 0; i <= 45; ++i)
  {
    printf("%d: %d\n", i, calculate_fib(i));
  }
}

int main()
{
  int n = 0, res = 0;
#if TEST == 0
  res = scanf("%d", &n);
  printf("%d", calculate_fib(n));
#else
  test();
#endif
  return 0;
}
